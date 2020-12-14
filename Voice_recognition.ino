#include <SoftwareSerial.h>
#define M1pos 2
#define M1neg 3    //base motor
#define M4pos 6
#define M4neg 7    //wrist motor

SoftwareSerial BLU(11,10);
String voice;
void setup() {

Serial.begin(9600);
pinMode(M1pos, OUTPUT);
pinMode(M1neg, OUTPUT);

pinMode(M4pos, OUTPUT);
pinMode(M4neg, OUTPUT);

BLU.begin(9600); 
}

void loop() {
 voice="";       //to read the command only once
while (BLU.available()){  //Check if there is an available byte to read
  Serial.println("here");
  delay(10); //Delay added to make thing stable 
  char c = BLU.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c

}
if (voice.length() > 0) {
    Serial.println(voice); 


 if(voice =="*plastic")
{
  plastic();
  Serial.println("1");
  
}
else if(voice =="*paper")
{
  paper();
  Serial.println("2");
  
}
else if(voice =="*metal")
{
  metal();
  Serial.println("3");
  
}
else if(voice =="*glass")
{
  glass();
  Serial.println("3");
  
}}


}

void glass()
{
  Serial.println("1'");
  digitalWrite(M1pos, HIGH);  //Base motor rotation 
  digitalWrite(M1neg, LOW);
  delay(1000);
  digitalWrite(M1pos, LOW); 
  digitalWrite(M1neg, LOW);
  delay(1000);
  digitalWrite(M4pos, HIGH); //wrist rotation
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M4pos, LOW);
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M4pos, LOW); //wrist rotation
  digitalWrite(M4neg, HIGH);
  delay(1100);
  digitalWrite(M4pos, LOW);
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M1pos, LOW);  //Base motor rotation 
  digitalWrite(M1neg, HIGH);
  delay(1000);
  digitalWrite(M1pos, LOW); 
  digitalWrite(M1neg, LOW);
  delay(1000);
  
}

void paper()
{
  Serial.println("2'");
  digitalWrite(M1pos, LOW);  //Base motor rotation 
  digitalWrite(M1neg, HIGH);
  delay(1000);
  Serial.println("yes");
  digitalWrite(M1pos, LOW); 
  digitalWrite(M1neg, LOW);
  delay(1000);
  digitalWrite(M4pos, HIGH); //wrist rotation
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M4pos, LOW);
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M4pos, LOW); //wrist rotation
  digitalWrite(M4neg, HIGH);
  delay(1000);
  digitalWrite(M4pos, LOW);
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M1pos, HIGH);  //Base motor rotation 
  digitalWrite(M1neg, LOW);
  delay(1000);
  digitalWrite(M1pos, LOW); 
  digitalWrite(M1neg, LOW);
  delay(1000);
  
}
void metal()
{
  Serial.println("1'");
  digitalWrite(M1pos, LOW);  //Base motor rotation 
  digitalWrite(M1neg, HIGH);
  delay(3000);
  digitalWrite(M1pos, LOW); 
  digitalWrite(M1neg, LOW);
  delay(1000);
  digitalWrite(M4pos, HIGH); //wrist rotation
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M4pos, LOW);
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M4pos, LOW); //wrist rotation
  digitalWrite(M4neg, HIGH);
  delay(1000);
  digitalWrite(M4pos, LOW);
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M1pos, HIGH);  //Base motor rotation 
  digitalWrite(M1neg, LOW);
  delay(2500);
  digitalWrite(M1pos, LOW); 
  digitalWrite(M1neg, LOW);
  delay(1000);
  
}
void plastic()
{
  Serial.println("2'");
  digitalWrite(M1pos, HIGH);  //Base motor rotation 
  digitalWrite(M1neg, LOW);
  delay(3000);
  digitalWrite(M1pos, LOW); 
  digitalWrite(M1neg, LOW);
  delay(1000);
  digitalWrite(M4pos, HIGH); //wrist rotation
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M4pos, LOW);
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M4pos, LOW); //wrist rotation
  digitalWrite(M4neg, HIGH);
  delay(1100);
  digitalWrite(M4pos, LOW);
  digitalWrite(M4neg, LOW);
  delay(1000);
  digitalWrite(M1pos, LOW);  //Base motor rotation 
  digitalWrite(M1neg, HIGH);
  delay(2000);
  digitalWrite(M1pos, LOW); 
  digitalWrite(M1neg, LOW);
  delay(1000);
  
}
