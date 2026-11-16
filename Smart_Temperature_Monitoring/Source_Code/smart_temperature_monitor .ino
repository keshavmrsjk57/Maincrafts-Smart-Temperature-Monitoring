
/*
  SMART TEMPERATURE MONITORING SYSTEM
  Board: Arduino UNO R3
  Sensor: TMP36
  Output: LED
*/

const int TEMP_PIN = A0;
const int LED_PIN = 8;

const float THRESHOLD = 30.0;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);

  Serial.println("Smart Temperature Monitoring System");
  Serial.println("-----------------------------------");
}

void loop() {

  int sensorValue = analogRead(TEMP_PIN);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperature = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  if (temperature >= THRESHOLD) {

    digitalWrite(LED_PIN, HIGH);

    Serial.println("ALERT: High Temperature!");
    Serial.println("LED STATUS: ON");

  } else {

    digitalWrite(LED_PIN, LOW);

    Serial.println("Temperature Normal");
    Serial.println("LED STATUS: OFF");

  }

  Serial.println("---------------------------");

  delay(1000);
}
