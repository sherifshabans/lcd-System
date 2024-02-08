/*
 * lcd sys Project 2.c
 *
 * Created: 12/21/2023 11:42:33 AM
 * Author: Hos10
 */

#include "SysInit.h"
#include <alcd.h>

void main(void)
{
    // Initialize Hardware
    initializeHardware();

    while (1)
        {
        int i;
        int input;

        for (i = 0; i <= 32; i++)
            {
            input = keypad();

			if (input == 10)
				lcd_putchar('*');
			else if (input == 11)
				lcd_putchar('#');
			else
				lcd_printf("%d", input);
			}
		lcd_clear();
		}
}
