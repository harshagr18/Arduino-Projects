// The key to this lock is 1 2 4 5

int button,i,reading[6],flag=0;
void setup()
{
  Serial.begin(9600);  
  pinMode(2, INPUT_PULLUP);//Button to start taking input
  pinMode(8, OUTPUT);//red indicator for input begin.
  pinMode(9, OUTPUT);//green indicator for correct knock.
  pinMode(10, OUTPUT);//red indicator for incorrect knock.
}

void loop() 
{
 button= digitalRead(2);
 flag=0;
 if(button==0) // To start when button is pressed
 {
  for(i=0;i<6;i++) // When the red LED glows, keep tapping.
  {
    digitalWrite(8,HIGH);
    delay(1000);
    reading[i]=analogRead(A9);    
    digitalWrite(8,LOW);
    delay(1000);
  }
  if(reading[0]=0)
  {
    flag=1;
  }
  if(reading[1]=0)
  {
    flag=1;
  }
  if(reading[2]>=0)
  {
    flag=1;
  }
  if(reading[3]=0)
  {
    flag=1;
  }
  if(reading[4]=0)
  {
    flag=1;
  }
  if(reading[5]>=0)
  {
    flag=1;
  }
  if(flag==0)
  {
   digitalWrite(9,HIGH)
   delay(2000);
   digitalWrite(9,LOW)
   delay(2000);
  }
  if(flag==1)
  {
   digitalWrite(10,HIGH)
   delay(2000);
   digitalWrite(10,LOW)
   delay(2000);
  }
 }
}
