#include <IRremote.h>

// C++ code
//
const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;

int LED1 = 4;
int LED2 = 5;
int LED3 = 7;

int motion1 = 11;
int motion2 = 10;

int A = LOW;
int C = LOW;


IRrecv irrecv(3);
decode_results results;


void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  irrecv.enableIRIn();
  
  PCICR |= B00000001;
  PCMSK0 |= B00111100; 
  
  TCCR1B &= ~(1 << WGM13);
  TCCR1B |= (1 << WGM12);
  
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);
  
  TCNT1= t1_load;
  OCR1A= t1_comp;
  
  TIMSK1 = (1 << OCIE1A);

  sei();
	

}

void loop()
{

  delay(50);

}

ISR(PCINT0_vect)
{
  A = digitalRead(motion1);
  C = digitalRead(motion2);
}


void iiii()
{
  if(A == HIGH)
  {
    Serial.println("motion1 detected");
    digitalWrite(LED1,HIGH);
  }
  digitalWrite(LED1,LOW);
  if(C == HIGH)
  {
    Serial.println("motion2 detected");
    digitalWrite(LED2,HIGH);
  }
  digitalWrite(LED2,LOW);
  if(irrecv.decode(&results))
  {
    if (results.value==16580863)
    {
      digitalWrite(LED3,HIGH);
      Serial.println("resived signal,LED on");
    } 
    		
    irrecv.resume();
  }
  digitalWrite(LED3,LOW);
}

ISR(TIMER1_COMPA_vect)
{
  iiii();
}




