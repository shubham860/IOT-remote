#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);


void setup()
{
  Serial.begin(9600);
  
   lcd.begin(16,2);
       lcd.setCursor(0,0);
      lcd.print("Smart");
      lcd.setCursor(0,1);
      lcd.print("Fridge");
       delay(2000);
       lcd.clear();

        pinMode(5, INPUT);        //relay
      digitalWrite(5, HIGH);
      
       
      pinMode(6, OUTPUT);        //relay
      digitalWrite(6, HIGH);
      pinMode(4, OUTPUT);        //relay
      digitalWrite(4, HIGH);
      delay(300);      //Let system settle 
      analogReference(DEFAULT);
      delay(700);      //Wait rest of 1000ms recommended delay before
  
}

void loop()
{
      
     int x = analogRead(A0)*0.49;
     int y = analogRead(A1)*0.49;
     lcd.setCursor (0,0);
                lcd.print("Temp. IN:"); 
                lcd.print(x);
                 lcd.print(" ");
         lcd.setCursor (0,1);
                lcd.print("Temp. OUT:"); 
                lcd.print(y);
                 lcd.print(" ");
              Serial.println(x); 
              if(x<15)
              {
                 digitalWrite(4, LOW);
              }
               if(x>15)
              {
                 digitalWrite(4, HIGH);
              }
         if(digitalRead(5)==0)
      {
         digitalWrite(6, LOW);
      }                   
      if(digitalRead(5)==1)
      {
         digitalWrite(6, HIGH);
      }     
  delay(500);
}
