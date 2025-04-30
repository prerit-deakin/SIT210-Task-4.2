
// Pin definitions
const int buttonPin = 2;     // Push button input (Interrupt 1)
const int sensorPin = 3;     // Digital sensor input (Interrupt 2)
const int led1Pin = 5;       // LED1 controlled by push button
const int led2Pin = 6;       // LED2 controlled by sensor

// State variables (must be volatile for ISR)
volatile bool led1State = LOW;
volatile bool led2State = LOW;

void setup() {
  // Setup pins
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(sensorPin, INPUT);         // Sensor input pin
  pinMode(led1Pin, OUTPUT);          // Output to LED1
  pinMode(led2Pin, OUTPUT);          // Output to LED2

  // Start serial monitor
  Serial.begin(9600);
  delay(1000);  // Ensure Serial Monitor is ready

  // Attach interrupts
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING); // Falling edge for button press
  attachInterrupt(digitalPinToInterrupt(sensorPin), sensorISR, RISING);  // Rising edge for sensor signal

  Serial.println("System Ready: Waiting for interrupts...");
}

// Interrupt Service Routine: Push Button
void buttonISR() {
  led1State = !led1State;  // Toggle LED1 state
  digitalWrite(led1Pin, led1State);
  Serial.println("Interrupt: Button Pressed - LED1 Toggled");
}

// Interrupt Service Routine: Sensor
void sensorISR() {
  led2State = !led2State;  // Toggle LED2 state
  digitalWrite(led2Pin, led2State);
  Serial.println("Interrupt: Sensor Triggered - LED2 Toggled");
}

void loop() {
  // Empty loop - all logic handled by interrupts
}
