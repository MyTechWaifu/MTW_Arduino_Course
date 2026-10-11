/*
  EXAMPLE 5: Read a whole integer with parseInt().

  Set Serial Monitor to 9600 baud and select No line ending.
  Send 123 and wait for Received: 123. Then try -12 or 42.
  Send one short decimal integer at a time and wait for its reply.

  On a classic Nano, long has the range -2147483648 through 2147483647.
  Use small values within this range for this beginner demonstration.
*/

void setup() {
  Serial.begin(9600);

  // Set the timeout for reading methods that wait for the next character.
  // The unit is milliseconds. 50 ms suits our short Serial Monitor messages.
  // This does not change the baud rate or insert a delay(50) pause here.
  // A slower sender may require a longer timeout.
  Serial.setTimeout(50);

  Serial.println("Send one decimal integer. Use No line ending.");
}

void loop() {
  // Begin parsing when at least one received byte is waiting.
  // The remaining characters may still be on their way.
  if (Serial.available() > 0) {
    // parseInt() combines several text characters into one integer.
    // For example, '1', '2', and '3' become the integer 123.
    // The return type is long. A leading minus sign is supported.
    // number is a local variable inside this if block.
    long number = Serial.parseInt();

    // With No line ending, the parser may wait after the final digit.
    // When the wait for another character times out, parseInt() returns.
    // While it is waiting, the next instruction in loop() cannot run.

    // Print a label and the numeric result together on one line.
    Serial.print("Received: ");
    Serial.println(number);
  }

  // Important details about this simple parsing demonstration:
  // 1. By default, parseInt() skips leading characters that do not start a number.
  // 2. If it finds no digits before timeout, it returns 0.
  // 3. A genuine input of 0 also returns 0: this is not input validation.
  // 4. With Newline, a leftover LF can trigger another parse and an extra 0.
  // For this example, select No line ending and send only integers.
}
