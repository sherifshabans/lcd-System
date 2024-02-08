# Embedded LCD System Documentation

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Proteus Simulation](#proteus-simulation)
- [Developers](#developers)
- [Main file](#main-file)
- [Header file](#header-file)

## Overview

The system allows users to print values on an LCD using a keypad.

## Features

- Print values on LCD using a keypad.

## Getting Started

### Prerequisites

Ensure you have the following tools and components:

- Proteus 8 Professional
- CodeVisionAVR Evaluation
- ATmega16 Microcontroller
- Other necessary components (LCD, Keypad)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Hussein119/lcd-system.git
   cd lcd-system
   ```

2. Open the project in CodeVisionAVR.

   - Launch CodeVisionAVR and open the project file (`\Code\lcd sys Project 2.prj`).
   - Customize project settings if necessary.

3. Simulate in Proteus.

   - Open Proteus 8 Professional.
   - Load the simulation file (`\Simulation\lcd sys Project 2.pdsprj`) and run the simulation.

4. Hardware Implementation.

   - Connect the ATmega16 to the necessary components.
   - Program the microcontroller using CodeVisionAVR.

### Proteus Simulation

#### Hardware Components

1. ATmega16 Microcontroller
2. LCD Display
3. Keypad 4x3

![Hardware](image.png)

## Developers

- Islam AbdElhady Hassanein
- Ahmed Hesham Fathall Farag
- Elsherif Shapan Abdelmageed
- Hussein AbdElkader Hussein
- Enas Ragab AbdEllatif
- Mariam Tarek Saad

## Main File

### lcdSys.c

- lcdSys.c - Main file for the embedded lcd system project.
- This file serves as the main entry point for the lcd system project. It includes necessary header files

```c
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
```

## Header File

### SysInit.h

- lockSysInit.h - Header file containing initialization functions for the embedded lcd system.
- This file includes functions for initializing various hardware components such as the keypad, and LCD.

```c
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
```
