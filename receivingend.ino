#include"ServoTimer2.h"

#include <DataCoder.h>
#include <VirtualWire.h>


const int rx_pin = 5;
const int led_pin = 3;
const int baudRate = 1000;
int valx = 0;
int valy = 0;


ServoTimer2 myservo;
ServoTimer2 myservol;
ServoTimer2 myservor;

void setup()
{
  delay(1000);
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  digitalWrite(led_pin,LOW);
  SetupRFDataRxnLink(rx_pin, baudRate);
  
 // myservol.attach(SERVO_PIN_B);
  //myservor.attach(SERVO_PIN_C); 
  
  
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  union RFData inDataSeq;
  
  float inArray[2];
  int posd=90;
  
  if(vw_get_message(buf,&buflen))
  {
        digitalWrite(led_pin, HIGH);
        
        for(int i =0; i< buflen; i++)
        {
          inDataSeq.s[i] = buf[i];
        }
        
        Serial.println();
        
        digitalWrite(led_pin, LOW);
      
        DecodeRFData(inArray, inDataSeq);
        
        //Do something with the elements that have been received
        valx = (int)inArray[0];
        valy = (int)inArray[1];
        digitalWrite(led_pin, HIGH);
        servomove(valx);
        servomovelr(valy);
        digitalWrite(led_pin, LOW);
        
  }
}

void servomove(int pos){
  myservo.attach(11);
  myservo.write((int)(750 + (pos*8.33)));
  delay(450);
  myservo.detach();
}
void servomovelr(int pos){
  myservol.attach(12);
  myservor.attach(13);
  myservol.write((int)(750 + (pos*8.33)));
  myservor.write((int)(750 + ((180 - pos)*8.33)));
  delay(450);
  myservol.detach();
  myservor.detach();
}

