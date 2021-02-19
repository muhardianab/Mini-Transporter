//kontrol PID

void run_PID()
{
  int   sensor = readsensor();

  currentTime = millis(); //get current time
  elapsedTime = (double)(currentTime - previousTime);

  if (sensor == 0b00000000 || sensor == 0b11111111)
  {
    brake(motorR, motorL);
    error = 0;
    Serial.println("brake");
  }

  else
  {
    switch (sensor)
    {
      case 0B10000000: error = 7; Serial.println("<<<<<<<"); break;
      case 0B11000000: error = 6; Serial.println("<<<<<"); break;
      case 0B01000000: error = 5; Serial.println("<<<<<"); break;
      case 0B01100000: error = 4; Serial.println("<<<<"); break;
      case 0B00100000: error = 3; Serial.println("<<<"); break;
      case 0B00110000: error = 2; Serial.println("<<"); break;
      case 0B00010000: error = 1; Serial.println("<"); break;
      case 0B00011000: error = 0;  Serial.println("-"); break;
      case 0B00001000: error = -1;  Serial.println(">"); break;
      case 0B00001100: error = -2;  Serial.println(">>"); break;
      case 0B00000100: error = -3;  Serial.println(">>>"); break;
      case 0B00000110: error = -4;  Serial.println(">>>>"); break;
      case 0B00000010: error = -5;  Serial.println(">>>>>"); break;
      case 0B00000011: error = -6;  Serial.println(">>>>>>"); break;
      case 0B00000001: error = -7;  Serial.println(">>>>>>>"); break;
    }

    //cumError += error * elapsedTime;                // compute integral
    rateError = (error - lastError) / elapsedTime; // compute derivative
    double moveval = (error * kp) + (rateError * kd);
    double m1 = maxspeed + moveval;
    double m2 = -maxspeed + moveval;
    motorR.drive(m1);
    motorL.drive(m2);
    delay(15);
    lastError = error;                                //remember current error
    previousTime = currentTime;
  }
}

//void drive(int speed)
//{
//  digitalWrite(STBY, HIGH);
//  speed = speed * 1;
//  if (speed>=0) fwd(speed);
//  else rev(-speed);
//}
//
//void fwd(int speed)
//{
//   digitalWrite(AIN1, HIGH);
//   digitalWrite(AIN2, LOW);
//   analogWrite(PWMA, speed);
//
//}
//
//void rev(int speed)
//{
//   digitalWrite(AIN1, LOW);
//   digitalWrite(AIN2, HIGH);
//   analogWrite(PWMA, speed);
//}
