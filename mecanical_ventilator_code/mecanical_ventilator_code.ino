#include <LiquidCrystal.h>

const int rs = 32, en = 30, d4 = 22, d5 = 24, d6 = 26, d7 = 28;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;
int e1 = 10;
int e2 = 11;
int state1 = LOW;
int state2 = LOW;


void setup() {
  
  // put your setup code here, to run once:
  lcd.begin(16, 2); //We are using a 16*2 LCD display
  lcd.print("AUTO VENTILATOR"); //Display a intro message
  
  delay(3000); //Wait for display to show info
  
  lcd.clear(); //Then clean it
  
  lcd.print(" VOLUME CONTROL"); //Display a intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
lcd.print("MODE :"); //Display a intro message
  lcd.setCursor(0, 2);
  delay(2000);
  
  // lcd.clear();

 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
 pinMode (ENA, OUTPUT);
 pinMode (ENB, OUTPUT);
 pinMode (e1, INPUT);
 pinMode (e2, INPUT); 

 int state1 = digitalRead(e1);
  int state2 = digitalRead(e2);
 if(state1 == LOW){
   cw();
  }
  
}

void loop() {
   int state1 = digitalRead(e1);
  int state2 = digitalRead(e2);
if(state1 == HIGH){
   cw();
  }
  if(state2 == HIGH){
    ccw();
    }
    

}
  void cw(){
  analogWrite(ENB, 255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  }
   void ccw(){
     
  analogWrite(ENB, 255);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


//project under development some input featurs may added later*
