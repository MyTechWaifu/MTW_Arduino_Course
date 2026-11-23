/*
  EXAMPLE: Blink the built-in LED with millis().

  Board: classic Arduino Nano. No external components are required.

  Expected result:
    - The built-in LED turns on in setup().
    - After about 1000 ms, it turns off.
    - After about another 1000 ms, it turns on again.
    - The pattern repeats. A full ON/OFF cycle takes about 2 seconds.

  How it works:
    On each pass through loop(), the sketch checks how much time has
    passed since the last LED change. If less than 1000 ms has passed,
    the sketch skips the LED update and continues through loop().
*/

// Time between two changes of the LED state, in milliseconds.
// 1000 ms = 1 second. This is how long each ON or OFF state lasts.
// const means this value stays fixed while the sketch runs.
const unsigned long interval = 1000;

// Stores the clock reading from the last time we changed the LED.
// We also fill it in setup() to start timing the first ON interval.
// It is outside loop() so we can use it in setup() and keep its value
// from one pass through loop() to the next.
unsigned long lastToggle;

// Remembers the level we want on the LED pin.
// On a classic Nano, HIGH means the built-in LED is on,
// and LOW means it is off. Setting this variable alone does not
// change the pin. digitalWrite() applies the value to the pin.
int ledState = HIGH;

void setup() {
  // Arduino runs setup() once when the board starts or resets.
  // LED_BUILTIN is the pin connected to the onboard LED.
  // OUTPUT configures that pin so the sketch can set its level.
  pinMode(LED_BUILTIN, OUTPUT);

  // ledState starts at HIGH. Write that value to the pin so the
  // first thing we see is the LED turning on.
  digitalWrite(LED_BUILTIN, ledState);

  // Save the current clock reading after turning the LED on.
  // This becomes the starting point for the first 1000 ms interval.
  lastToggle = millis();
}

void loop() {
  // Arduino calls loop() again and again after setup().
  // millis() reads the time since the sketch started, in milliseconds.
  // now is a snapshot for this pass. On the next pass we read it again.
  unsigned long now = millis();

  // now - lastToggle gives the time since the last LED change.
  //
  // Example: if we last changed the LED at 200 ms:
  //   now = 1199 ms -> 1199 - 200 =  999 ms -> skip this block.
  //   now = 1200 ms -> 1200 - 200 = 1000 ms -> enter this block.
  //
  // >= means "greater than or equal to". If the next check happens
  // at 1201 ms, the result is 1001 ms, so the block still runs.
  //
  // Both timestamps use unsigned long. On the classic Nano, unsigned
  // subtraction still gives the correct elapsed time when millis()
  // wraps to zero, provided less than one full counter cycle has passed.
  if (now - lastToggle >= interval) {
    // Use this pass's clock reading as the start of the next interval.
    // If now is 1200 ms, we save 1200. A check at 1201 ms will then
    // see just 1 ms elapsed, so the LED will not change again yet.
    lastToggle = now;

    // Choose the opposite of the saved LED state.
    // If it was HIGH, choose LOW. Otherwise choose HIGH.
    if (ledState == HIGH) {
      ledState = LOW;
    } else {
      ledState = HIGH;
    }

    // Send the new level to the physical pin.
    // This is the line that actually changes the light.
    digitalWrite(LED_BUILTIN, ledState);
  }

  // The sketch reaches this point on every pass, whether the LED
  // changed or stayed as it was. A short button check or another
  // task could run here without waiting for the next LED change.
}
