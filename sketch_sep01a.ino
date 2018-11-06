#include <DataCoder.h>
#include <VirtualWire.h>

const int transmit_pin = 10;
const int led_pin = 13;
const int baudRate = 1000;

int JoyX = 0;
int JoyY = 1;
int Joyvalx;
int Joyvaly;

void setup()
{
  pinMode(led_pin,OUTPUT);
  
  SetupRFDataTxnLink(transmit_pin, baudRate);

}

void loop()
{
  float outArray[2];

  Joyvalx = analogRead(JoyX);
  Joyvalx = map(Joyvalx,0,1023,0,180);

  Joyvaly = analogRead(JoyY);
  Joyvaly = map(Joyvaly,0,1023,0,180);
  
  outArray[0] = Joyvalx;
  outArray[1] = Joyvaly;
  
  union RFData outDataSeq;
 
  EncodeRFData(outArray, outDataSeq); 
  
  TransmitRFData(outDataSeq);  
  
  digitalWrite(led_pin, HIGH);
  
  delay(100);
  
  digitalWrite(led_pin,LOW);
  
  delay(500);
  
}
