#ifndef _XTAL_FREQ
 // Unless specified elsewhere, 4MHz system frequency is assumed
 #define _XTAL_FREQ 20000000
#endif

#include	<xc.h>
#include	"lcd.h"

#define	LCD_RS RB0
#define	LCD_RW RB1
#define LCD_EN RB2
#define LCD_DATA PORTA
#define	LCD_STROBE()	((LCD_EN = 1),(LCD_EN=0))

void lcd_go_and_puts(unsigned char pos, const char * s)
{
	lcd_goto(pos);
	lcd_puts(s);
}

/* write a byte to the LCD in 4 bit mode */
void lcd_write(unsigned char c)
{
	__delay_us(40);
	LCD_DATA = (( c >> 4 ) & 0x0F ) | (LCD_DATA & 0xF0);
	LCD_STROBE();
	LCD_DATA = ( c & 0x0F ) | (LCD_DATA & 0xF0);
	LCD_STROBE();
}

/*Clear and home the LCD*/
void lcd_clear(void)
{
	LCD_RS = 0;
	lcd_write(0x1);
	__delay_ms(2);
}

/* write a string of chars to the LCD */
void lcd_puts(const char * s)
{
	LCD_RS = 1;	// write characters
	while(*s)
		lcd_write(*s++);
}

/* write one character to the LCD */
void lcd_putch(char c)
{
	LCD_RS = 1;	// write characters
	lcd_write( c );
}

/*Go to the specified position*/
void lcd_goto(unsigned char pos)
{
	LCD_RS = 0;
	lcd_write(0x80+pos);
}

/* initialise the LCD - put into 4 bit mode */
void lcd_init()
{
	char init_value;
	init_value = 0x3;
	LCD_RS = 0;
	LCD_EN = 0;
	LCD_RW = 0;
	
	__delay_ms(15);	// wait 15mSec after power applied,
	LCD_DATA	 = init_value;
	LCD_STROBE();
	__delay_ms(5);
	LCD_STROBE();
	__delay_us(200);
	LCD_STROBE();
	__delay_us(200);
	LCD_DATA = 2;	// Four bit mode
	LCD_STROBE();

	lcd_write(0x28); // Set interface length
	lcd_write(0b00001100); // Display On, Cursor off
	lcd_clear();	// Clear screen
	lcd_write(0x6); // Set entry Mode
}

void lcd_puts_ltoa(char *buf, int buf_size, long val, char div)
{
  char ascii_array[10] = {0x30,0x31,0x32,0x33,0x34,
              0x35,0x36,0x37,0x38,0x39};
  char zero_flag = 0;
  char cnt = 0;
  
  buf[buf_size - 1] = 0x00;
  buf_size --;
  while(buf_size > 0)
  {
    if(zero_flag == 0)
    {
      buf[buf_size - 1] = ascii_array[(val%10 & 0x0F)];
      val /= 10;
      buf_size --;
    }else{
      buf[buf_size - 1] = 0x20;
      val /= 10;
      buf_size --;
    }
    if(((cnt % 3) == 2) && (val != 0) && (div == 1))
    {
      buf[buf_size - 1] = 0x2e;  //0x2c is comma,0x2e is decimal
      buf_size --;
    }
    cnt ++;
    val == 0 ? zero_flag=1 : zero_flag=0;
  }
  lcd_puts(buf);
}