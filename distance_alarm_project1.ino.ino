#include <LiquidCrystal.h>
int rs=7;
int E=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,E,d4,d5,d6,d7);  //object lcd by using the library liquidcrystal has been made to include the variables made above.
int trigpin=5;
int echopin=4;
int pingtraveltime;
float pingtraveldistance;
float distancetothetarget;
int buzzpin=2;
int redpin=3;
int whitepin=6;

void setup() {
  // put your setup code here, to run once:
 pinMode(trigpin,OUTPUT);
 pinMode(echopin,INPUT);
 pinMode(buzzpin,OUTPUT);
 Serial.begin(9600);
 lcd.begin(16,2);    //letting the ino know that the lcd bar graph we're using have 16 columns and 2 rows.
}

void loop() {
 //put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  pingtraveltime=pulseIn(echopin,HIGH);  //pulseIn function is being used to measure the length of the ping basically measuring the time and high is written there cause we're looking for the high kind of pulse.
  pingtraveldistance=0.013*pingtraveltime;
  distancetothetarget=pingtraveldistance/2;
  lcd.setCursor(0,0);
  lcd.print("DISTANCE: ");
  lcd.print((int)distancetothetarget);
  lcd.println(" inch");
  lcd.setCursor(0,1);
  if (distancetothetarget <= 6 ){
    digitalWrite(buzzpin,HIGH);
    delay(100);
    digitalWrite(buzzpin,LOW);
    delay(100);
    analogWrite(redpin,5);
    analogWrite(whitepin,0);
    lcd.print("STOP!! TOO CLOSE");
    }
    else{analogWrite(whitepin,5);
         analogWrite(redpin,0);
         lcd.print("Safe Distance!! ");
    }  
} 
