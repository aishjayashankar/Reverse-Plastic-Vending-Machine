#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
long randno,randno1,randno2,randno3,randno4;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
SoftwareSerial mySerial(9, 10);
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor for Bin sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor for Bin Sensor
const int ping1=30; // trig of bottle detect
const int echo1=29; //echo of bottle detect
bool check = true;
int b=0;
int c,d;
long distance;
long distance1;
int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9
                                       

void Num_Write(int);
void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(ping1,OUTPUT);
  pinMode(echo1,INPUT);
  randomSeed(analogRead(0));
  pinMode(22, OUTPUT);   
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("I work");
}
void loop()
{
  
  lcd.setCursor(0,0);
  lcd.print("Welcome to IVM");
  Serial.print("IVM");
  lcd.setCursor(0, 1);
 distance = calc(ping1,echo1);
 //Serial.println(distance);
  Serial.println(distance);
  if(distance<10 && distance>0)
  {//Serial.println("Within Range");
    check =false;}
    if(check==false){
  Serial.println("botalllllllllllllllllllllllllllllllllllll");
  b=b+1;
  Serial.print("botal ");
  Serial.print(b);
  //Num_Write(b);
  delay(2000);
    }


if(check==false)
{
  randno=random(100,200);
  if(randno%3==0)
  {
  randno1=random(98,121);
  randno2=random(30,60);
  randno3=random(98,121);
  char r=(char)randno1;
  char r2=(char)randno3;
  lcd.setCursor(0,1);
  Serial.println("reward");
  delay(2000);
  lcd.print("Promo:");
  lcd.print(randno2);
  lcd.print(r);
  lcd.print(r2);
  lcd.print(randno1);
  delay(3000);
  lcd.println("Welcome to IVM");
  lcd.setCursor(0, 1);
  lcd.println("Inverse Vending");
  }
  else
  {
    lcd.println("Won No Reward!!!");
    Serial.println("Won No Reward");
    delay(2000);
    lcd.println("Welcome to IVM");
    lcd.setCursor(0, 1);
  lcd.println("Inverse Vending");
  }
  check=true;
}
//  distance1 = calc(pingPin,echoPin);
////  Serial.println("distance is ");
////  Serial.println(distance1);
////  delay(1000);
//  if(distance1<15 && distance1>10)
//  {
//  Serial.println("Warning");
//    }
//  if(distance1<9 && distance1>0)
//  {
//  Serial.println("Full");
//  SendMessage();
//  }  
}
long calc(int x, int y)
{ 
  long dist,duration;
  digitalWrite(x,LOW);
  delayMicroseconds(2);
  digitalWrite(x, HIGH);
  delayMicroseconds(10); 
  digitalWrite(x, LOW);
  duration = pulseIn(y, HIGH);
  dist = (duration/2) / 29.41;
  return dist;
} 
 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919514832760\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Bin is full, kindly retrieve bin!");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


