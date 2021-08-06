// C++ code
//
int val = 0;


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
  attachInterrupt(0,pin_ISR,CHANGE);
}

void loop()
{

}

void pin_ISR()
{
	val = digitalRead(2);
  	digitalWrite(13,val);
	if(val == HIGH)
  	{
      Serial.println("Motion detected!");
    }
  	else
  	{
      Serial.println("Motion Stoped!");
    }
    
}