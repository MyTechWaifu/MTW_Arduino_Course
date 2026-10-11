/*
  EXAMPLE 6: Read a decimal value with parseFloat().

  Set Serial Monitor to 9600 baud and select No line ending.
  Send 23.75 and wait for Received: 23.75.
  Then try -12.5: the reply will be Received: -12.50.
  Use a period as the decimal separator, not a comma.
*/

void setup() {
  Serial.begin(9600);

  // Allow up to 50 ms while waiting for another character.
  // This interval applies to each wait for a character,
  // not to the total duration of the complete parsing operation.
  Serial.setTimeout(50);

  Serial.println("Send one decimal number. Use No line ending.");
}

void loop() {
  // Do not start parsing until at least one received byte is waiting.
  if (Serial.available() > 0) {
    // parseFloat() combines text characters into a floating-point value.
    // For example, '2', '3', '.', '7', and '5' produce approximately 23.75.
    // The result is a float, which has limited precision.
    float number = Serial.parseFloat();

    // Print the label without adding a line ending yet.
    Serial.print("Received: ");

    // For a floating-point value, the second argument selects decimal places.
    // Two places turn the displayed -12.5 into -12.50.
    // Formatting does not increase the variable's stored precision.
    Serial.println(number, 2);
  }

  // Like parseInt(), parseFloat() can wait for input and return 0 on timeout.
  // This example demonstrates reading; it does not validate complete commands.
  // Send short ordinary decimal numbers, one at a time, and wait for each reply.
  // To keep other loop tasks responsive, use parsing that does not wait this way.
}
