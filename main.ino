#include <Wire.h>
#include <LiquidCrystal.h>
#include <SparkFun_TB6612.h>

//===== Sensor =====//
#define kiri4  A7
#define kiri3  A5 // kiri2
#define kiri2  A4 // kanan2
#define kiri1  A3 // kanan1
#define kanan1 A2 // kiri1
#define kanan2 A1 // kiri2
#define kanan3 A0 // kanan3
#define kanan4 A6

const unsigned int datasensor [8] = {kiri4, kiri3, kiri2, kiri1, kanan1, kanan2, kanan3, kanan4};
//int threshold_atas[8]  = {500,250,700,400,400,460,550,700};
int threshold_bawah[8] = {200, 60, 600, 150, 150, 250, 250, 400};

int kiri4Value, kiri3Value, kiri2Value, kiri1Value, kanan1Value, kanan2Value, kanan3Value, kanan4Value;

//===== Driver Motor TB6612FNG =====//
#define PWMA 44
#define PWMB 46
#define AIN1 27
#define AIN2 29
#define BIN1 25
#define BIN2 23
#define STBY 31

//======BUTTON======//
  #define UP 41
  #define DOWN 45
  #define SELECT 47
  #define CANCEL 49

Motor motorR (AIN1, AIN2, PWMA, 1, STBY);
Motor motorL (BIN1, BIN2, PWMB, 1, STBY);

//int menu = 0, prev_menu, cursor;
int kp_buffer, ki_buffer, kd_buffer;
int lcd_loop_counter = 0;

//===== PID =====//
int i;
int val [8] ;
double kp = 30, kd = 0.5;
int maxspeed = 100;
//int threshold = 880;  // nilai ADC tertinggi
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double cumError, rateError;

//PID pid(&input, &output, &setpoint, kp, ki, ki, DIRECT);

//Deklarasi LCD
const int rs = 24, en = 13, d4 = 12, d5 = 11, d6 = 10, d7 = 9;
const int red = 53;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

//buzzer
const int buzzer = 26;
void setup()
{
  inisialisasi();
//  tutup(); delay(10);
//  buka();
}

void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
//  tombol_counter();
//  LCDgue();
  digitalWrite(red, LOW);
  run_PID();

}

// movement programs, choose which one do you prefer
int readsensor()
{
  int bitsensor = 0;
  for (i = 0; i < 8; i++)
  {
    val [i] = analogRead(datasensor[i]) ;

    // val [i] = map(val [i], 200 , 500,  0, 1);         //baca nilai Analog write
    Serial.print(val[i]); Serial.print("\t");

    if (val[i] >= threshold_bawah[i])
    {
      val[i] = 1;
      bitsensor = bitsensor | (0b10000000 >> i); //right shift (digeser sejauh i iterasi)
    }

    else
    {
      val [i] = 0;
    }

    Serial.print(val[i]);
    Serial.print("\t");      //baca nilai setelah treshold
  }

//  Serial.println(" ");
  return bitsensor;
}
