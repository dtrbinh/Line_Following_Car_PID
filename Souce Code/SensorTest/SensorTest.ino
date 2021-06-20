#define Sensor_HIGH  300

bool Line[10] = {true};
const int Sensors[10] = {A0, A1, A2, A3, A4, A5, A7, A8, A9, A10};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(Sensors[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  GetSensorDigital();
}

void GetSensorDigital() {
  GetSensorStatus();
  for (int i = 0; i < 10; i++) {
    Serial.print(Line[i]);
  }
  Serial.println();
}

void GetSensorAnalog() {
  for (int i = 0; i < 10; i++) {
    Serial.print(analogRead(Sensors[i]));
    Serial.print("  ");
  }

  Serial.println();
}

void GetSensorStatus() { //Get all the sensor status
  for (int i = 0; i < 10; i++) {
    Line[i] = ReadLine(i);
  }
}

bool ReadLine(int index) { //Get the sensor status for each sensor
  int temp = analogRead(Sensors[index]);
  if (temp <= Sensor_HIGH) {
    return true;
  }
  else {
    return false;
  }
}
