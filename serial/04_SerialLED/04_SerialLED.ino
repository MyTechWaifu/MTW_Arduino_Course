/*
  EXAMPLE 4: Control the built-in LED through Serial.

  Board: classic Arduino Nano. No external LED is required.
  Set Serial Monitor to 9600 baud. For your first test, select No line ending.
  Send 1: the LED turns on and the board replies LED ON.
  Send 0: the LED turns off and the board replies LED OFF.
*/

void setup() {
  Serial.begin(9600);

  // LED_BUILTIN names the onboard LED pin defined by the selected board package.
  // OUTPUT makes the pin an output, allowing the program to set its logic level.
  // pinMode() configures the pin's mode; it is not an "LED on" command.
  pinMode(LED_BUILTIN, OUTPUT);

  // Establish the initial state. On a classic Nano, LOW turns this LED off.
  digitalWrite(LED_BUILTIN, LOW);

  // Print the user instructions once at startup.
  Serial.println("Send 1 for ON, 0 for OFF.");
}

void loop() {
  // Check for received data before processing a command.
  if (Serial.available() > 0) {
    // Read one command byte.
    int incoming = Serial.read();

    // == compares values. Assignment uses a single = instead.
    // '1' in single quotes identifies the character sent by Serial Monitor.
    // The plain integer 1 would have a different value.
    if (incoming == '1') {
      // On a classic Nano, HIGH turns the onboard LED on.
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED ON");  // Acknowledge that the command was handled.
    } else if (incoming == '0') {
      // else if checks this alternative when the first condition was false.
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED OFF");
    }

    // Other characters cause no action because no branch handles them.
    // This also ignores appended carriage return and line feed bytes: CR and LF.
  }

  // No delay() here: return quickly to checking for the next command.
}
