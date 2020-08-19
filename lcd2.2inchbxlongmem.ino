#include <EEPROM.h>
char  buttonState = 0;
char i=1,j=1,v=1;
 int m=1;  
void setup() {
    pinMode(A0, OUTPUT); 
    pinMode(10, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(12, OUTPUT);
     pinMode(A3, INPUT); 

      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
       digitalWrite(12, LOW);
      digitalWrite(A0, LOW);
      digitalWrite(13, LOW);
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(A3, HIGH);
  
  }
void loop() {

  int value = analogRead(A5);   //đọc giá trị điện áp ở chân A0 
  int voltage;
  voltage = map(value,0,1023,0,50);   //chuyển thang đo của value 
  

 
    if(voltage==15||voltage==16)
      {
         EEPROM.write(1,EEPROM.read(1)+1);
        delay(5);
        if(EEPROM.read(1)>=4)
        {
         EEPROM.write(1,1);
        }
        if(EEPROM.read(1)==1)
        {
         digitalWrite(6, HIGH);
          delay(150);
          digitalWrite(6, LOW);
          delay(150);
        }
     if(EEPROM.read(1)==2)
        {
         digitalWrite(6, HIGH);
          delay(150);
          digitalWrite(6, LOW);
          delay(150);
           digitalWrite(6, HIGH);
          delay(150);
          digitalWrite(6, LOW);
        }
        
           if(EEPROM.read(1)==3)
        {
         digitalWrite(6, HIGH);
          delay(150);
          digitalWrite(6, LOW);
          delay(150);
           digitalWrite(6, HIGH);
          delay(150);
          digitalWrite(6, LOW);
          digitalWrite(6, HIGH);
          delay(150);
          digitalWrite(6, LOW);
        }
      }


      if(EEPROM.read(1)==1&&j==1&&digitalRead(A3)==0)
       {  
    
          digitalWrite(A0, HIGH);
          digitalWrite(10, 1);
          delay(200); 
           digitalWrite(A0,LOW);  
           digitalWrite(10,0);
       
          j=2;
         
       }
          
    if(EEPROM.read(1)==1&&j==2&&digitalRead(A3)==0)
     {  
          digitalWrite(10, 1);
      
          delay(200);
          digitalWrite(10, 0);
          j=1;
          delay(300);
      }
           
    if(EEPROM.read(1)==2&&digitalRead(A3)==0)
    {
      
        digitalWrite(A0, HIGH);        
        delay(200); 
        digitalWrite(A0, LOW); 
         delay(300);  
      
    }
   if(EEPROM.read(1)==3&&digitalRead(A3)==0)
    {
        
        digitalWrite(10,1);
        delay(200);
        digitalWrite(10,0);
         delay(300);
    }

         if(voltage==21||voltage==22)
       {
         digitalWrite(8, HIGH); 
       
         
         delay(200);
         digitalWrite(8, LOW);
       
        }
        
      if(voltage==24 ||voltage==25)
       {
         digitalWrite(10, 1);//z-
         delay(200);
         digitalWrite(10, LOW); 
        }
       if(voltage==18||voltage==19)
       {
         
          digitalWrite(9, HIGH);
        
         delay(200);
         
         digitalWrite(9, LOW); 
      
        }

      }
         
   
