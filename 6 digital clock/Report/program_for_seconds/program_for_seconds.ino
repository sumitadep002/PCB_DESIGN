//Anode Common 4-Digit 7-segment Needed or make your own using 7-segemnt display
//for detailed video visit to my channel creative inventor http://www.youtube.com/creativinventor1
// you can follow me on instagram- https://www.instagram.com/creative_inventor/

#include <TimeLib.h>

int digit1 = 8; 
int digit2 = 9; 
int digit3 = 10; 
int digit4 = 11;
int digit5 = 12; 
int digit6 = 13;  


int segA = 1;//Display pin A
int segB = 2;//splay pin b
int segC = 3; //Display pin c
int segD = 4; //Display pin d
int segE = 5; //Display pin e
int segF = 6; //Display pin f
int segG = 7; //Display pin g

//input pins for push buttons
byte SW0 = A0; //connect jumper or switch for time adjust connected with Gnd
byte SW1 = A1; // Hour Switch - connected with Gnd
byte SW2 = A2; // Minute Switch - connected with Gnd


void setup() {

  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);


  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(digit5, OUTPUT);
  pinMode(digit6, OUTPUT);
 Serial.begin(9600);

  pinMode(SW0, INPUT);  
  pinMode(SW1, INPUT);  
  pinMode(SW2, INPUT);  

  digitalWrite(SW0, HIGH); 
  digitalWrite(SW1, HIGH);
  digitalWrite(SW2, HIGH);
}

void loop() {
  
   unsigned int hr = hour();
   unsigned int hourFormat12();           // the hour now in 12 hour format
   unsigned int hourFormat12(time_t t);
   unsigned int timp = ( (hr>12)?(hr%12):hr)*10000+minute()*100+second();
   Serial.println(timp);
  
// display parts
   for(int i = 250 ; i>0  ; i--) {
     if ((timp/100) > 100) displayNumber01(timp);
     else displayNumber02(timp);
   }

   for(int i = 250 ; i >0  ; i--) {
     if (timp > 100) displayNumber03(timp);
     else displayNumber04(timp);
   }
   for(int i = 250 ; i >0  ; i--) {
     if (timp > 100) displayNumber05(timp);
     else displayNumber06(timp);
   }

  if (!(digitalRead(SW0))) set_time();
}


void set_time()   {
  
  byte minutes1 = 0;
  byte hours1 =0;
  byte second1=0;
  byte minutes = minute();
  byte hours = hour();
  byte seconds=second();

  while (!digitalRead(SW0)) 
  {
    minutes1=minutes;
    hours1=hours;
    second1=seconds;
  
  while (!digitalRead(SW1))
    {
     hours++;

     if (hours > 12) hours = 1;

     for(int i = 20 ; i >0  ; i--) {
     int timp= hours*10000+minutes*100+seconds;
     if ((timp/100) > 10000) displayNumber01(timp);
     else displayNumber02(timp);
     }

    delay(150);
    }
    while (!digitalRead(SW2)) 
    {
     minutes++;

    if (minutes > 59) minutes = 0;
     for(int i = 20 ; i >0  ; i--) {
       int timp= hours*10000+minutes*100+seconds;
     if ((timp/100) > 10000) displayNumber01(timp);
     else displayNumber02(timp);
     }
     delay(150);
    }
     for(int i = 20 ; i >0  ; i--) {
     displayNumber01(hours*10000+minutes*100+seconds);
     }
     setTime(hours,minutes,second,0,0,0,0,0,0);

//     delay(150);

  }

}

void displayNumber01(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 6 ; digit > 0 ; digit--) {

  
    switch(digit) {
    case 1:
     digitalWrite(digit1, DIGIT_ON);
      break;
   case 2:
      digitalWrite(digit2, DIGIT_ON);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      break;
    case 5:
      digitalWrite(digit5, DIGIT_ON);
      break;
    case 6:
      digitalWrite(digit6, DIGIT_ON);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

  
    lightNumber(10);

    
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
    digitalWrite(digit5, DIGIT_OFF);
    digitalWrite(digit6, DIGIT_OFF);
}
}

void displayNumber02(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 6 ; digit > 0 ; digit--) {

    
    switch(digit) {
    case 1:
     lightNumber(10);
     digitalWrite(digit1, DIGIT_ON);
     break;
   case 2:
      digitalWrite(digit2, DIGIT_ON);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      break;
    case 5:
      digitalWrite(digit5, DIGIT_ON);
      break;
    case 6:
      digitalWrite(digit6, DIGIT_ON);
      break;
      
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

    
    lightNumber(10);

    
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
    digitalWrite(digit5, DIGIT_OFF);
    digitalWrite(digit6, DIGIT_OFF);
}
}

void displayNumber03(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 6 ; digit > 0 ; digit--) {

    
    switch(digit) {
    case 1:
     digitalWrite(digit1, DIGIT_ON);
      break;
   case 2:
      digitalWrite(digit2, DIGIT_ON);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      break;
    case 5:
      digitalWrite(digit5, DIGIT_ON);
      break;
    case 6:
      digitalWrite(digit6, DIGIT_ON);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

    
    lightNumber(10);

   
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
    digitalWrite(digit5, DIGIT_OFF);
    digitalWrite(digit6, DIGIT_OFF);
}
}

void displayNumber04(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 6 ; digit > 0 ; digit--) {

    
    switch(digit) {
    case 1:
     lightNumber(10);
     digitalWrite(digit1, DIGIT_ON);
     break;
     case 2:
      digitalWrite(digit2, DIGIT_ON);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      
      break;
    case 5:
      digitalWrite(digit5, DIGIT_ON);
      
      break;
    case 6:
      digitalWrite(digit6, DIGIT_ON);
      
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

     //Turn off all segments
    lightNumber(10);

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
    digitalWrite(digit5, DIGIT_OFF);
    digitalWrite(digit6, DIGIT_OFF);
}
}
void displayNumber05(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 6 ; digit > 0 ; digit--) {

    
    switch(digit) {
    case 1:
     lightNumber(10);
     digitalWrite(digit1, DIGIT_ON);
     
     break;
     case 2:
      digitalWrite(digit2, DIGIT_ON);
     
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      
      break;
      case 5:
      digitalWrite(digit5, DIGIT_ON);
      
      break;
      case 6:
      digitalWrite(digit6, DIGIT_ON);
      
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

     //Turn off all segments
    lightNumber(10);

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
    digitalWrite(digit5, DIGIT_OFF);
    digitalWrite(digit6, DIGIT_OFF);
}
}

void displayNumber06(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 6 ; digit > 0 ; digit--) {

    
    switch(digit) {
    case 1:
     lightNumber(10);
     digitalWrite(digit1, DIGIT_ON);
     
     break;
     case 2:
      digitalWrite(digit2, DIGIT_ON);
     
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      
      break;
      case 5:
      digitalWrite(digit5, DIGIT_ON);
      
      break;
      case 6:
      digitalWrite(digit6, DIGIT_ON);
      
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

     //Turn off all segments
    lightNumber(10);

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
    digitalWrite(digit5, DIGIT_OFF);
    digitalWrite(digit6, DIGIT_OFF);
}
}

void lightNumber(int numberToDisplay) {

#define SEGMENT_ON  LOW
#define SEGMENT_OFF HIGH

  switch (numberToDisplay){

  case 0:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 1:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 2:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_OFF);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 3:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 4:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 5:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 6:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 7:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 8:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 9:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  
  case 10:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_OFF);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  }
}
