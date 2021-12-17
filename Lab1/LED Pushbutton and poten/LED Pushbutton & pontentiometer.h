//LED blinking

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
} 


------------------------------------------------------

//LED pushbutton

int isPressed = 0;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  isPressed = digitalRead(2);
  if (isPressed == HIGH){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
}

----------------------------------------------------------

//LED potentiometer

void setup()
{ 
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop(){
  int analog = analogRead(A0);
  int brightness = map(analog,0,1023,0,255);
  
  analogWrite(9,brightness);
  
  Serial.println((String)"Analog: "+analog
                 +" Brightness: "+brightness);
  
  delay(500);
}

------------------------------------------------------------
