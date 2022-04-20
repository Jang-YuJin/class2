int RED_LED = 10;
int ORANGE_LED = 11;
int YELLOW_LED = 12;
int GREEN_LED = 13;
int TRIGER = 7;
int ECHO = 6;
void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(TRIGER, OUTPUT);
  pinMode(ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int distance = 0;
  digitalWrite(TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGER, LOW);
  
  distance = pulseIn(ECHO, HIGH);
  int cm = distance / 58;
  
  Serial.println(cm);
  
  if(cm > 100){
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }else if(cm <= 100 && cm > 70){
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }else if(cm <= 70 && cm > 40){
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(ORANGE_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }else{
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
}