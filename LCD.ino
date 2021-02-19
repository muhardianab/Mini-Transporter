int counter =1;
int menu = 0;
int upstate = 0;
int lastupstate = 0 ;
int downstate=0;
int lastdownstate = 0;
int selectstate=0;
int lastselectstate = 0;
int cancelstate=0;
int lastcancelstate = 0;
int counterselect=0;

void tombol_counter()
{
  //button list
  upstate = digitalRead(UP);
  downstate = digitalRead(DOWN);
  selectstate =  digitalRead(SELECT);
  cancelstate = digitalRead(CANCEL);
     
  //button UPDOWN
  if(upstate != lastupstate || downstate != lastdownstate)
  {
    if(upstate == LOW)
    {
      counter++; 
    }  
  }

  if(downstate != lastdownstate)
  {
    if(downstate == LOW)
    {
      counter--;
    }  
  }

    if(counter >4)
  {
    counter = 1;  
  }
  
//button OKE
  if(selectstate != lastselectstate)
  {
    if(selectstate == LOW)
    {
      counterselect++;
    }  
  }
  
   if(counterselect >1)
  {
    counterselect = 0;  
  }
  

  
  lastupstate = upstate;
  lastdownstate = downstate;
  lastselectstate = selectstate;
  menu = counter;
  int okeValue = counterselect;
 
}


void LCDgue()
{
	switch(menu)
	{

		case 1:
		//lcd.clear();
		lcd.setCursor(1,0);
		lcd.print(" >TIM  PID");
		lcd.setCursor(1,1);
		lcd.print("  START  CP");
		break;

		case 2:
		//lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("  TIM  >PID");
    lcd.setCursor(1,1);
    lcd.print("  START   CP");
		break;


		case 3:
		//lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("  TIM   PID");
    lcd.setCursor(1,1);
    lcd.print(" >START   CP");
		break;


		case 4:
		//lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("  TIM   PID");
    lcd.setCursor(1,1);
    lcd.print("  START  >CP");
		break;
	}

   //_____PID setting//
//  if(menu == 3 && counterselect ==1)
//  {
////    kp = kp+(counter*0.1);
//    lcd.clear();
//    lcd.setCursor(1,0);
//    lcd.print("GOGOGOGOGO!!");
//    run_PID();
//  }
}
