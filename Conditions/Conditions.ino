/*
  EXAMPLE: Control the built-in LED with "on" and "off".

  Board: classic Arduino Nano. No extra components are needed.

  Open Serial Monitor and select:
    Baud rate:   9600
    Line ending: Newline

  Type a command and press Send:
    on  -> the LED turns on.  Serial Monitor shows LED ON.
    off -> the LED turns off. Serial Monitor shows LED OFF.
    ?   -> Serial Monitor shows UNKNOWN COMMAND.
           The LED stays in its current state.
*/

void setup() {
  // Arduino runs setup() once when the board starts or resets.
  // LED_BUILTIN is the name of the pin connected to the built-in LED.
  // OUTPUT lets the sketch set that pin to HIGH or LOW.
  pinMode(LED_BUILTIN, OUTPUT);

  // On a classic Nano, LOW turns the built-in LED off.
  // Start with the LED off.
  digitalWrite(LED_BUILTIN, LOW);

  // Start Serial at 9600 baud. Use the same setting in Serial Monitor.
  Serial.begin(9600);
  Serial.println("Send on or off");
}

void loop() {
  // Arduino calls loop() repeatedly after setup() finishes.
  // Serial.available() tells us how many received bytes are ready to read.
  // If the answer is zero, return ends this pass through loop().
  // Arduino will call loop() again and check for data again.
  if (Serial.available() == 0) {
    return;
  }

  // String holds text. With Newline selected, Serial Monitor sends
  // a newline character ('\n') after the word when you press Send.
  // readStringUntil() reads the text up to that character.
  // If the newline does not arrive, the read can wait for its timeout.
  String command = Serial.readStringUntil('\n');

  // Remove spaces and other whitespace at the start and end.
  // For example, " on " becomes "on". Letter case stays the same.
  command.trim();

  // int holds a whole number. We use three numbers as internal codes:
  //   0 means unknown command.
  //   1 means turn the LED on.
  //   2 means turn the LED off.
  // You type words in Serial Monitor. The sketch chooses the number.
  int action;

  // Two equals signs (==) compare values and give true or false.
  // A single equals sign (=) stores a value in a variable.
  if (command == "on") {
    // The text matches "on". Store the number for turning the LED on.
    action = 1;
  } else if (command == "off") {
    // Arduino checks this condition only if the first one was false.
    action = 2;
  } else {
    // Neither word matched. Store the number for an unknown command.
    action = 0;
  }

  // switch looks at the number in action.
  // A matching case marks where execution starts.
  switch (action) {
    case 1:
      // HIGH turns the built-in LED on.
      digitalWrite(LED_BUILTIN, HIGH);

      // break exits the switch. Without this break, execution would
      // continue into case 2 and turn the LED right back off.
      break;

    case 2:
      // LOW turns the built-in LED off.
      digitalWrite(LED_BUILTIN, LOW);
      break;

    default:
      // default runs here when neither numbered case matches.
      // Print the error without changing the LED.
      Serial.println("UNKNOWN COMMAND");

      // Unlike break above, return ends this whole pass through loop().
      // That skips the LED status message below.
      return;
  }

  // A valid command reaches this part after break exits the switch.
  // digitalRead() reads the logic level at the LED pin.
  // if / else lets us print one message for HIGH and one for LOW.
  if (digitalRead(LED_BUILTIN) == HIGH) {
    Serial.println("LED ON");
  } else {
    Serial.println("LED OFF");
  }
}
