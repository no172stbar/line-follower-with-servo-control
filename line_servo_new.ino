#include<Servo.h>
Servo servo;

int ir1 = 4;
int ir2= 5;
int ir3 = 6;
int ir4 = 7;
int right1 =8;
int right2=9;
int left1=10;
int left2=11;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(3);
  pinMode(right1,OUTPUT);
  pinMode(right2,OUTPUT);
  pinMode(left1,OUTPUT);
  pinMode(left2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ir1=digitalRead(4);
  Serial.print("infrared 1= ");
  Serial.print(ir1);
  
  ir2=digitalRead(5);
  Serial.print("infrared 2= ");
  Serial.print(ir2);

  ir3=digitalRead(6);
  Serial.print("infrared 3= ");
  Serial.print(ir3);
  
  ir4=digitalRead(7);
  Serial.print("infrared 4= ");
  Serial.print(ir4);
  Serial.print("   ");
  Serial.print("angle = ");

  if(ir1==HIGH&&ir2==LOW&&ir3==LOW&&ir4==HIGH){
    servo.write(90);
    Serial.print(" 90");
    }
  else if(ir1==HIGH&&ir2==HIGH&&ir3==LOW&&ir4==HIGH){
     servo.write(60);
     Serial.print(" 60");
    }
  else if(ir1==HIGH&&ir2==HIGH&&ir3==LOW&&ir4==LOW){
    servo.write(30);
    Serial.print("30"); 
    }  
  else if(ir1==HIGH&&ir2==LOW&&ir3==HIGH&&ir4==HIGH){
    servo.write(120);
    Serial.print(" 120"); 
    }
  else if(ir1==LOW&&ir2==LOW&&ir3==HIGH&&ir4==HIGH){
    servo.write(150);
    Serial.print(" 150"); 
    }
    else if(ir1==HIGH&&ir2==HIGH&&ir3==HIGH&&ir4==HIGH){
      digitalWrite(right1,LOW);
      digitalWrite(right2,HIGH);
      digitalWrite(left1,LOW);
      digitalWrite(left2,HIGH);
     }
  else{
    Serial.print("wrong");
  }
    

}
