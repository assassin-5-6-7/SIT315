#include <IRremote.h>

// C++ code
//
int val = 0;

IRrecv irrecv(3);
decode_results results;


void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  irrecv.enableIRIn();


  attachInterrupt(digitalPinToInterrupt(2),ISR2,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),iii,CHANGE);

}

void loop()
{



}



void ISR2()
{
  
	val = digitalRead(2);
  	digitalWrite(4,val);
	
  	if(val == HIGH)
  	{
      Serial.println("Motion detected!");
    }
  	else
  	{
      Serial.println("Motion Stoped!");
    }
}

void iii(){
    	
    if(irrecv.decode(&results)){
      if (results.value==16580863){
        digitalWrite(5,HIGH);
        Serial.println("resived signal,LED on");
      } 
    		
      irrecv.resume();
    }
  
}