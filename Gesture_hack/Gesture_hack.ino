long duration;
int udm[40];
int code[40]={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
int distance;
int thresholdLow=5;
int thresholdHigh=50;
int error=10;
int i;
int button=8;
int flag=0;
const int trigPin=11;
const int echoPin=12;
int alert=9;
int correct=10;
int lockmotor=3;
int ut;
int lt;
void setup()
{
   pinMode(button,INPUT_PULLUP);
   pinMode(trigPin,OUTPUT);
   pinMode(echoPin,INPUT);
   pinMode(alert,OUTPUT);
   pinMode(correct,OUTPUT);
   pinMode(lockmotor,OUTPUT);
   Serial.begin(9600);
}

 
void loop()
{
 recordGesture(); 
}
                       
void recordGesture()
{
flag=0;
label:  i=0; 
digitalWrite(alert,HIGH);
digitalWrite(correct,HIGH);
delay(1000);
digitalWrite(alert,LOW);
digitalWrite(correct,LOW);
  while(i<40)
  {
    
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    now=millis();
    duration= pulseIn(echoPin,HIGH);
    distance= duration*0.034/2;
  if(distance>=thresholdLow && distance<=thresholdHigh)
  {
    udm[i]=distance;
    i++;
    delay(25);
    Serial.println(distance);
  }
 }
 Serial.println("--------------------------------------------------------------------------------------------------");
if(digitalRead(button)==0)
  {
  savePass();  
  }
else
{
  validate();
}

if(now-startime>=1000)
{
goto label;
}
}
void savePass()
{
 i=0;
 Serial.println("Here's the new Gesture distances");
  while(i<40)
 { 
  code[i]= udm[i];
  Serial.println(code[i]);
  i++;
 }
 Serial.println("--------------------------------------------------------------------------------");

}
void validate()
{
  flag=0;
 i=0;
 while(i<40)
 {
  lt=code[i]-15;
  ut=code[i]+15;
 if(udm[i]<lt || udm[i]>ut)
 { 
  flag=1;
 }
 i++;
 }
 if(flag==1)
 {
  digitalWrite(alert,HIGH);
  delay(500);
  digitalWrite(alert,LOW);
  delay(500);
  digitalWrite(alert,HIGH);
  delay(500);
  digitalWrite(alert,LOW);
  delay(500);
  digitalWrite(alert,HIGH);
  delay(500);
  digitalWrite(alert,LOW);
  delay(500);
  }
  if(flag==0)
  {
    digitalWrite(lockmotor,HIGH);
    digitalWrite(correct,HIGH);
    delay(200);
    digitalWrite(lockmotor,LOW);
    delay(800);
    digitalWrite(correct,LOW);

  }
}
