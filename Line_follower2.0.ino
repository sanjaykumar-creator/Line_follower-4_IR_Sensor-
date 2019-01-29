#define sensor1 2 
#define sensor2 3
#define sensor3 4
#define sensor4 5

#define speedRight 9
#define speedLeft 10

#define out1 8
#define out2 11

#define out3 12
#define out4 13

#define green 6
#define red 7

void found();
void notfound();
void check();
void stopp();
int control();

static int n=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);

  pinMode(speedRight,OUTPUT);
  pinMode(speedLeft,OUTPUT);
  
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);

  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);

  analogWrite(speedRight,120);
  analogWrite(speedLeft,120);
  
  Serial.begin(9600);
}

void check()
{
 int t=10,speedd=80;
 
 while(speedd<120)
 { 
  digitalWrite(out1,LOW);
  digitalWrite(out4,LOW);
  analogWrite(out2,speedd);
  analogWrite(out3,speedd);
   speedd+=t;
   delay(5);
 }
  delay(10);
  //*****************Here it Checks If the line is present some Distance away*********************
  stopp();
  n++;
  }
  
int a=0;

void loop() {
  // put your main code here, to run repeatedly:
     a=control();
     switch(a)
     {
      case 0:
        notfound();
       if(n!=1&&n<1)
        check();    
      break;
      case 1:
      n=0;
      Serial.println("Short Left");
      analogWrite(speedLeft,150);
      digitalWrite(out1,LOW);
      digitalWrite(out2,HIGH);
      digitalWrite(out3,HIGH);
      digitalWrite(out4,LOW);
      delay(10);
      analogWrite(speedLeft,120);
      break;
      case 2:
      n=0;
      Serial.println("left");
      analogWrite(speedRight,80);
      analogWrite(speedLeft,120);
      digitalWrite(out1,LOW);
      digitalWrite(out2,LOW);
      digitalWrite(out3,HIGH);
      digitalWrite(out4,LOW);
     
      delay(10);
      break;
      
      case 3:
       n=0;
       Serial.println("Short Right");
       analogWrite(speedRight,150);
      digitalWrite(out1,LOW);
      digitalWrite(out2,HIGH);
      digitalWrite(out3,HIGH);
      digitalWrite(out4,LOW);
      delay(10);
      analogWrite(speedRight,120);
      break;
      
      case 4:
      n=0;
      Serial.println("run");
      digitalWrite(out1,LOW);
      digitalWrite(out2,HIGH);
      digitalWrite(out3,HIGH);
      digitalWrite(out4,LOW);
      delay(10);
      break;
     
      case 5:
      n=0;
      stopp();
      Serial.println("left");
       analogWrite(speedRight,80);
      analogWrite(speedLeft,120);
      digitalWrite(out1,LOW);
      digitalWrite(out2,LOW);
      digitalWrite(out3,HIGH);
      digitalWrite(out4,LOW);
      delay(10);
      break;
     
      case 6:
      n=0;
      stopp();
      Serial.println("Right");
       analogWrite(speedRight,120);
      analogWrite(speedLeft,80);
      digitalWrite(out1,LOW);
      digitalWrite(out2,HIGH);
      digitalWrite(out3,LOW);
      digitalWrite(out4,LOW);
      delay(10);
      break;
     
      case 7:
      n=0;
      stopp();
      Serial.println("Right");
       analogWrite(speedRight,120);
      analogWrite(speedLeft,80);
      digitalWrite(out1,LOW);
      digitalWrite(out2,HIGH);
      digitalWrite(out3,LOW);
      digitalWrite(out4,LOW);
      delay(10);
      break;
     
      case 8:
      if(n!=0)
      digitalWrite(red,HIGH);
      else
      {
      digitalWrite(red,LOW);
      found();
      }
      Serial.println("Stop");
      stopp();
        check();
      delay(10);
      break;

      case 9:
       Serial.println("Check");
       check();
      break;
     }
      delay(50);
     
}

int control()
{
  int s1,s2,s3,s4,result=0;
  s1=digitalRead(sensor1);
  s2=digitalRead(sensor2);
  s3=digitalRead(sensor3);
  s4=digitalRead(sensor4);

//*****troubleshooting*******
  
 // Serial.print(" sensor 1 :");
  Serial.print(s1);
 // Serial.print(" sensor 2 :");
  Serial.print(s2);
  //Serial.print(" sensor 3 :");
  Serial.print(s3);
  //Serial.print(" sensor 4 :");
  Serial.println(s4);

 //******************************

  int z=0;
  z=s1*1000+s2*100+s3*10+s4;
  Serial.print(" z :");
  Serial.println(z);

    if(z==0)
      result=0;
    else if(z==10)
      result=1;
    else if(z==11)
       result=2;
    else if(z==100)
      result=3;
    else if(z==110)
      result=4;
    else if(z==111)
      result=5;
    else if(z==1100)
      result=6;
    else if(z==1110)
      result=7;
    else if(z==1111)
      result=8;
    else
    result=9;
      
  Serial.println(result);
  return result;
  }
  void found()
{
   digitalWrite(red,LOW);
  digitalWrite(green, HIGH);
  delay(20);
  digitalWrite(green,LOW);
  }
void notfound()
{
  digitalWrite(green,LOW);
  digitalWrite(red,HIGH);
   delay(10);
  digitalWrite(red,LOW);
  }
void stopp()
{
  analogWrite(out1,LOW);
  analogWrite(out2,LOW);
  analogWrite(out3,LOW);
  analogWrite(out4,LOW);
  }
  
