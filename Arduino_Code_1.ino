*************************************************************************************************************************************************/
// the used PINs
const int s0=7;
const int s1=13;
const int s2=4;
const int s3=12;
const int sensorData=8;
int ir1=A0;
int ir2=A2;
int ledw1=10;
int ledw2=9;
int ledy1=5;
int ledy2=3;

// Global variable to store data
int data=0;


void setup() 
{
  // PINs configuration
   pinMode(s0,OUTPUT);
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(ir1,INPUT);
   pinMode(ir2,INPUT);
   pinMode(ledw1,OUTPUT);
   pinMode(ledw2,OUTPUT);
   pinMode(ledy1,OUTPUT);
   pinMode(ledy2,OUTPUT);
   
   pinMode(sensorData,INPUT);
  // Serial baude rate setup
   Serial.begin(9600);
  // Frequency scale
   digitalWrite(s0,HIGH);
   digitalWrite(s1,HIGH);
   
}

void loop()
{
/*********************** getting the RED COLOR data ************************/
  // Set S2 and S3 to LOW in order to sense the RED color
   digitalWrite(s2,LOW);
   digitalWrite(s3,LOW);
  // store data in the Global varibale
   data=pulseIn(sensorData,LOW);
  // Display data through the Serial monitor
   Serial.print("Red data= ");
   Serial.print(data);
   Serial.print(" ");
   delay(20);
/*********************** getting the GREEN COLOR data ************************/
   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   data=pulseIn(sensorData,LOW);
   Serial.print("Green data= ");
   Serial.print(data);
   Serial.print(" ");
   delay(20);
/*********************** getting the BLUE COLOR data ************************/

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   data=pulseIn(sensorData,LOW);
   Serial.print("Blue data= ");
   Serial.print(data);
   Serial.println(" ");
   delay(20);
   if(data<=10){
    analogWrite(ledy1,0);
    analogWrite(ledy2,0);
   }
   else{
    analogWrite(ledy1,255);
    analogWrite(ledy2,255);
   }
   delay(1000);
   delay(20);

   if(analogRead(ir1)>=100){
    analogWrite(ledw1,255);
    delay(500);
   }
   else{
    analogWrite(ledw1,10);
   }
   delay(20);

   if(analogRead(ir2)>=100){
    analogWrite(ledw2,255);
    delay(500);
   }
   else{
    analogWrite(ledw2,10);
   }

   
}
