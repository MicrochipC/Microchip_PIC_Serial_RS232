# RS232 serial comms with PIC16x and PIC18x

*For more C sample code, see [www.MicrochipC.com](http://www.MicrochipC.com/).*

This shows how to get a serial port up and running for a PIC16F876 and a PIC18F252 or PIC18F452.

> Do you have examples for other microcontrollers? All pull requests will be honored!

# PIC16F876

*From readme.txt:*

How to interface a PIC16F876 to a computer via RS232 serial comms, with Hi-Tech C and VB6 source code.

##What you need

- PIC16F876 on a breadboard.
- Schematic diagram for hardware (see the .gif file and the Protel 99 .sch file)
- MAX232 or SIPEX232 or MAX3222 (theres a lot of them around) serial chip for
  converting 5/0V logic levels of PIC to +13V/-13V logic levels of the RS232 port
  on a PC.
- Four capacitors above 1uF or more.
- A terminal program, such as HyperTerm for Windows for examining output from RS232 port.

##Instructions

- Program your PIC with the supplied .hex file.  Remember to get the crystal speed correct.
- Get the schematics, including PIC, MAX232, etc working correctly.
- Run HyperTerm, using the supplied com1-19200.ht link.
  - The link is set up with:
     - COMx, N,8,1, 19200bps, no flow control
        - Local echo on, send line ends with line feeds, wrap lines (file..
          properties.. settings.. ascii setup.. "echo typed characters locally" and "send
          line ends ..." and "wrap lines"
- Apply power to the PIC, and you should see the following come up in HyperTerm:

>     PICTest (c)2001 Shane Tolmie - see http://www.workingtex.com/htpic
>     Starting up serial @ 19200 baud, N,8,1, no flow control ...
>
>     This program tests the serial port.  It displays the text string '[alive]'
>     every few seconds, and echoes back to the user the ascii value of the pressed
>     key, plus one (+1), ie: putch(getch()+1)
> 
>     If the following test returns [pass] the EEPROM has been all initialized to
>     0xEE by the downloaded .hex file (see eep_init.c). If [fail] it prints out the
>     EEPROM contents for your examination.
> 
>     Testing EEPROM ... [pass]
> 
>     Key pressed:
> 
>     [alive] [alive] [alive] [alive] [alive] 12 [alive] 34


- As you can see, the PIC is communicating with the host computer.  Notice how it echoes back everything you type, +1 ascii character, so typing '1' echos back '2'.
- To work out how Visual Basic connects to the PIC, see the attached archive 'visual basic 6 terminal example.zip'. It is taken directly from the MSDN archive.

# PIC18F252 or PIC18F452

*From readme.txt:*

How to interface a PIC18F242 or PIC18F452 to a computer via RS232 serial comms, with Hi-Tech C and VB 6 source code.

What you need:

- PIC18F242 or PIC18F452 on a breadboard.
- Schematic diagram for hardware(see the .gif file and the Protel 99 .sch file).
- A 20Mhz crystal (or something else), with 22pF capacitors. See datasheet.
- A 10k pullup on pin 1 of the micro. 
- MAX232 or SIPEX232 or MAX3222 (theres a lot of them around) serial chip for
  converting 5/0V logic levels of PIC to +13V/-13V logic levels of the RS232 port
  on a PC. Four capacitors above 1uF or more.
- A terminal program, such as HyperTerm for Windows for examining output from
  RS232 port.

## Instructions

- Program your PIC with the supplied .hex file.  Remember to get the crystal speed correct.
- Get the schematics, including PIC, MAX232, etc working correctly.
- Run HyperTerm, using the supplied **com1-19200.ht** link.
- The link is set up with:
   - COMx, N,8,1, 19200bps, no flow control
   - Local echo on, send line ends with line feeds, wrap lines (File.. Properties.. Settings.. ASCII setup.. "echo typed characters locally" and "send line ends ..." and "wrap lines")

4.  Apply power to the PIC, and you should see the following come up in HyperTerm:

> Serial tester program for PIC18F252 by Shane Tolmie    
>     From: http://www.workingtex.com/htpic/     
>     Starting up serial @ 19200 baud, N,8,1, no flow control ...
>     [alive] [alive] [alive] [alive] [alive] [alive] [alive] [alive] [alive] [alive] [alive] 
>     [key pressed: d] [alive] 

- As you can see, the PIC is communicating with the PC.  Notice how it echoes back everything you type.

## More C Sample Code

For more sample code, see [www.MicrochipC.com](http://www.MicrochipC.com/).