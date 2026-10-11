/*
  EXAMPLE 3: Receive a byte, inspect ASCII, and convert one digit.

  Set Serial Monitor to 9600 baud and select No line ending.
  Type 5 without quotation marks, then click Send.

  Expected reply:
    Peek: 53
    Read: 53
    Character: 5
    Digit value: 5

  The character '5' has the code 53. The number 5 is a different value.
*/

void setup() {
  Serial.begin(9600);
  Serial.println("Send one character. Use No line ending.");
}

void loop() {
  // available() counts received bytes waiting to be read.
  // > 0 means at least one byte is waiting.
  // It does not guarantee that an entire message has arrived.
  if (Serial.available() > 0) {
    // peek() inspects the next byte without removing it from the buffer.
    int preview = Serial.peek();

    // read() removes the next byte from the buffer.
    // Here it retrieves the same byte that peek() just inspected.
    // int can hold both a byte value from 0 to 255 and the special value -1.
    int incoming = Serial.read();

    // -1 means there was no byte to read.
    // With our available() check, this is normally unnecessary here,
    // but it explicitly protects the processing code from missing input.
    if (incoming < 0) {
      // Leave this call to loop(); do not stop the whole program.
      // Arduino will call loop() again.
      return;
    }

    // For an int, print()/println() display the byte's numeric value.
    Serial.print("Peek: ");
    Serial.println(preview);
    Serial.print("Read: ");
    Serial.println(incoming);

    // write() sends the byte itself, which the monitor displays as a character.
    Serial.print("Character: ");
    Serial.write(incoming);
    Serial.println();

    // Convert only characters in the range '0' through '9'.
    // && means both comparisons must be true.
    // This prevents letters and other characters from being treated as digits.
    if (incoming >= '0' && incoming <= '9') {
      // ASCII digit codes are consecutive. The code for '0' is 48.
      // For the character '5', the calculation is 53 - 48 = 5.
      int digit = incoming - '0';
      Serial.print("Digit value: ");
      Serial.println(digit);
    }

    // Process one byte per pass through loop().
    // Sending 123 produces three separate byte reports: '1', '2', and '3'.
    // To obtain the whole integer 123, use parsing: see example 5.
  }
}
