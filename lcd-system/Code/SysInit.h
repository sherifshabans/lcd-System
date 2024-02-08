#include <mega16.h>
#include <alcd.h>

// Function prototypes
void initializeHardware();
void initializeKeypad();
char keypad();

// Function to initialize hardware components
void initializeHardware()
{
    initializeKeypad();
    lcd_init(16); // Initialize the LCD
}

// Function to initialize keypad
void initializeKeypad()
{
    // Set keypad ports
    DDRC = 0b00000111;  // 1 unused pin, 4 rows (input), 3 columns (output)
    PORTC = 0b11111000; // pull-up resistance
}

// Function: keypad
// Description: Reads the input from a 4x3 matrix keypad and returns the corresponding key value.
//              The keypad is connected to port C, and the function scans each row and column
//              combination to determine the pressed key.
// Returns: Character representing the pressed key.
char keypad()
{
    while (1)
    {
        PORTC .0 = 0;
        PORTC .1 = 1;
        PORTC .2 = 1;

        switch (PINC)
        {
        case 0b11110110:
            while (PINC .3 == 0)
                ;
            return 1;
        case 0b11101110:
            while (PINC .4 == 0)
                ;
            return 4;
        case 0b11011110:
            while (PINC .5 == 0)
                ;
            return 7;
        case 0b10111110:
            while (PINC .6 == 0)
                ;
            return 10;
        }

        PORTC .0 = 1;
        PORTC .1 = 0;
        PORTC .2 = 1;

        switch (PINC)
        {
        case 0b11110101:
            while (PINC .3 == 0)
                ;
            return 2;
        case 0b11101101:
            while (PINC .4 == 0)
                ;
            return 5;
        case 0b11011101:
            while (PINC .5 == 0)
                ;
            return 8;
        case 0b10111101:
            while (PINC .6 == 0)
                ;
            return 0;
        }

        PORTC .0 = 1;
        PORTC .1 = 1;
        PORTC .2 = 0;

        switch (PINC)
        {
        case 0b11110011:
            while (PINC .3 == 0)
                ;
            return 3;
        case 0b11101011:
            while (PINC .4 == 0)
                ;
            return 6;
        case 0b11011011:
            while (PINC .5 == 0)
                ;
            return 9;
        case 0b10111011:
            while (PINC .6 == 0)
                ;
            return 11;
        }
    }
}