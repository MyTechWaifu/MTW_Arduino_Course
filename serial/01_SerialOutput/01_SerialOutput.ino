/*
  EXAMPLE 1: Your first message and a counter.

  Goal: send readable text and variable values from Arduino to your computer.
  Board: classic Arduino Nano. No external components are required.
  Set Serial Monitor to 9600 baud.

  Expected output:
    Hello, engineer!
    Count: 0
    Count: 1
    Count: 2

  Comments explain the program; the microcontroller does not execute them.
*/

// A global variable is declared outside the functions.
// It keeps its value between calls to loop().
// unsigned long stores a non-negative whole number. Start counting at zero.
unsigned long counter = 0;

// setup() runs once whenever the program starts or the board resets.
// Use this block to prepare communication and print a welcome message.
void setup() {
  // Start serial communication at 9600 baud.
  // Select the same baud rate in Serial Monitor.
  Serial.begin(9600);

  // Double quotes identify literal text: print these exact characters.
  // println() adds a line ending after the message.
  Serial.println("Hello, engineer!");
}

// Arduino calls loop() repeatedly after setup() finishes.
// This block prints the next counter value on each pass.
void loop() {
  // print() does not add a line ending.
  // The next output continues immediately after the space.
  Serial.print("Count: ");

  // Without quotes, counter means the value stored in the variable.
  // println() prints that value and ends the line.
  Serial.println(counter);

  // ++ increases the counter by one. After printing 0, it becomes 1.
  counter++;

  // Wait for 500 milliseconds: half a second.
  // This makes the demonstration easier to read.
  // Further instructions in loop() wait until delay() returns.
  delay(500);
}
