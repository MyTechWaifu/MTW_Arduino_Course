/*
  EXAMPLE 2: Number formats, print(), and write().

  Goal: display the same value in different formats.
  Set Serial Monitor to 9600 baud.
  All messages are printed once in setup().
  Press Reset with Serial Monitor open to repeat the demonstration.
*/

void setup() {
  // Prepare Serial before printing anything.
  Serial.begin(9600);

  // int stores a whole number; float stores a value with a fractional part.
  // temperature is a demonstration value, not a real sensor reading.
  // The f suffix makes 23.75 a float literal.
  int number = 255;
  float temperature = 23.75f;

  // For an integer, the second println() argument selects the number base.
  // The written representation changes; number itself remains 255.
  Serial.print("DEC: ");
  Serial.println(number, DEC);  // Decimal: 255.

  Serial.print("HEX: ");
  Serial.println(number, HEX);  // Hexadecimal: FF.

  Serial.print("OCT: ");
  Serial.println(number, OCT);  // Octal: 377.

  Serial.print("BIN: ");
  Serial.println(number, BIN);  // Binary: 11111111.

  // BIN still prints text characters: '1', '1', and so on.
  // It does not send one raw byte with the value 255.

  // For a floating-point value, the second argument has a different purpose:
  // it selects how many digits to print after the decimal point.
  // With one decimal place, 23.75 is rounded for display to 23.8.
  Serial.print("One decimal place: ");
  Serial.println(temperature, 1);

  // With two decimal places, the display shows 23.75.
  // More printed digits do not increase the variable's stored precision.
  Serial.print("Two decimal places: ");
  Serial.println(temperature, 2);

  // print(65) converts the integer to the text "65": two characters.
  Serial.print("print(65): ");
  Serial.print(65);
  Serial.println();  // No argument: add only a line ending.

  // write(65) sends one raw byte with the value 65.
  // In ASCII, 65 is the code for uppercase A, so the monitor displays A.
  Serial.print("write(65): ");
  Serial.write(65);
  Serial.println();
}

void loop() {
  // Nothing to repeat automatically in this example.
  // Arduino still calls loop(), but this block contains no instructions.
}
