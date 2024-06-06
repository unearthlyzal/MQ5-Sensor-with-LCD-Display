#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define GasSensor_pin 0
#define red_pin 7
#define green_pin 6
#define buzzer 1

#define LCD_DDR DDRB
#define LCD_PORT PORTB
// Define LCD control pins
#define RS 0
#define EN 1
// Define LCD data pins
#define D4 2
#define D5 3
#define D6 4
#define D7 5


void lcd_send_nibble(uint8_t nibble) {
	LCD_PORT &= ~(1<<D7 | 1<<D6 | 1<<D5 | 1<<D4); // Clear the data pin section of the port
	if(nibble & 1<<4) LCD_PORT |= (1<<D4);
	if(nibble & 1<<5) LCD_PORT |= (1<<D5);
	if(nibble & 1<<6) LCD_PORT |= (1<<D6);
	if(nibble & 1<<7) LCD_PORT |= (1<<D7);
	LCD_PORT |= (1<<EN); // Enable pulse
	_delay_us(1); // Provide a delay
	LCD_PORT &= ~(1<<EN); // Disable pulse
}

void lcd_send_byte(uint8_t data) {
	lcd_send_nibble(data); // send upper nibble
	lcd_send_nibble(data << 4); // send lower nibble
	_delay_us(50);
}

void lcd_command(uint8_t command) {
	LCD_PORT &= ~(1<<RS);
	lcd_send_byte(command);
}

void lcd_char(char character) {
	LCD_PORT |= (1<<RS);
	lcd_send_byte(character);
}

void lcd_clear() {
	lcd_command(0x01); // clear display command
	_delay_ms(2);
}

void lcd_setCursor(uint8_t row, uint8_t col) {
	uint8_t offsets[] = {0x00, 0x40}; // 0x00 -> base address for the first row. // 0x40 -> base address for the second row.
	lcd_command(0x80 | (offsets[row] + col)); // 0x80 -> base command for setting the DDRAM address.
}

void lcd_print(char *str) {
	while (*str) {
		lcd_char(*str++);
	}
}

void lcd_begin() {
	LCD_DDR = 0xFF; // set LCD port as output
	_delay_ms(15); // wait for power up

	LCD_PORT &= ~(1<<RS); // set RS to command mode
	
	// sending "0x30" three times is part of the special initialization procedure required to wake the LCD from its reset state.
	// delays to ensure proper timing between	commands.
	lcd_send_nibble(0x30); // initialization
	_delay_ms(5);
	lcd_send_nibble(0x30); // initialization
	_delay_us(100);
	lcd_send_nibble(0x30); // initialization
	_delay_us(40);
	
	lcd_send_nibble(0x20); // set 4-bit mode
	_delay_us(40);

	lcd_command(0x28); // function set: 4-bit, 2-line, 5x8 dots
	lcd_command(0x08); // display off
	lcd_clear(); // clear screen
	lcd_command(0x06); // entry mode: increment automatically after each character, no display shift
	lcd_command(0x0C); // display on, cursor off, no blinking
}

// Gas sensor
void GasSensor_Init(){
	DDRC &= ~(1 << GasSensor_pin);
	ADCSRA = 0x87; // Enable ADC and set prescaler to 128
	ADMUX = 0x40; // ADC0, AVCC, Right adjust
	_delay_us(500);
}

int AnalogRead(){
	ADCSRA |= (1 << ADSC); // start conversion
	while((ADCSRA & (1 << ADIF)) == 0); // wait for conversion
	ADCSRA |= 1 << ADIF; // conversion complete (Clear interrupt flag)
	_delay_ms(1);
	
	return ADC;
}

void LED(){
	int val = AnalogRead();
	lcd_clear();
	if(val > 60){
		PORTD |= (1 << red_pin) | (1 << buzzer);
		PORTD &= ~(1 << green_pin);
		lcd_print("GAS detected.");
	}
	else{
		PORTD |= 1 << green_pin;
		PORTD &= ~((1 << red_pin) | (1 << buzzer));
		lcd_print("SAFE.");
	}	
}

int main(){
	lcd_begin();
	DDRD |= (1 << green_pin) | (1 << red_pin) | (1 << buzzer);
	GasSensor_Init();
	lcd_clear();
	lcd_print("ABDERAHMAN&SALMA");
	_delay_ms(2000);
	lcd_clear();
	lcd_print("GAS SENSOR");
	_delay_ms(2000);
	
	lcd_clear();
	lcd_print("Welcome");
	_delay_ms(1000);
	lcd_clear();
	
	while(1){
		LED();
	}
	lcd_clear();
}
