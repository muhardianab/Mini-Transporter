#include <Servo.h>

Servo servo_grip;
Servo servo_putar;
Servo servo_lift;

void servo_inisialisasi()  {
  servo_grip.attach(7);
  servo_putar.attach(35);
  servo_lift.attach(8);
}

void normal()  // default, angkat, buka, putar 0 deg
{
  servo_grip.write(10);
  delay(5);
  servo_putar.write(0);
  delay(5);
  servo_lift.write(30);
  delay(5);
}

void buka()  {
  servo_grip.write(60);
  delay(5);
}

void tutup()  {
  servo_grip.write(20);
  delay(5);
}

void putar1()  {
  servo_putar.write(180);
  delay(5);
}

void putar2()  {
  servo_putar.write(0);
  delay(10);
}

void angkat()  {
  servo_lift.write(30);
  delay(10);
}

void turun()  {
  servo_lift.write(20);
  delay(10);
}

//void servo_ambil() //tanpa putar
//{
//  turun();
//  tutup();
//  angkat();
//}
//
//void servo_taruh1() //tanpa putar warna sama
//{
//  turun();
//  buka();
//  normal//();
//}
//
//void servo_taruh2() //putar beda warna
//{
//  putar1();
//  turun();
//  normal();
//}
