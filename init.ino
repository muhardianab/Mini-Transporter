void inisialisasi()
{
  //Set sensor pin to input
  pinMode(kiri4, INPUT);
  pinMode(kiri3, INPUT);
  pinMode(kiri2, INPUT);
  pinMode(kiri1, INPUT);
  pinMode(kanan1, INPUT);
  pinMode(kanan2, INPUT);
  pinMode(kanan3, INPUT);
  pinMode(kanan4, INPUT);
  //BUZZER
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
  delay(100);

  //LED Enable
  pinMode(red, OUTPUT);
  //motor driver
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  //button
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  pinMode(CANCEL, INPUT_PULLUP);
  //LCD
  lcd.begin(16, 2);
  //servo
  servo_inisialisasi();
  //serial
  Serial.begin(115200);

}
