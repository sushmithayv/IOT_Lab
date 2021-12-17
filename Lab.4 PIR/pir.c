//PIR
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;
//the time when the sensor outputs a low impulse
long unsigned int lowIn;
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int pirPin = 3; //the digital pin connected to the PIR sensor&#39;s output
int ledPin = 13;

void setup(){
Serial.begin(9600);
pinMode(pirPin, INPUT);
pinMode(ledPin, OUTPUT);
digitalWrite(pirPin, LOW);
//give the sensor some time to calibrate
Serial.print(&quot;calibrating sensor &quot;);
for(int i = 0; i &lt; calibrationTime; i++){
Serial.print(&quot;.&quot;);
delay(1000);
}
Serial.println(&quot; done&quot;);
Serial.println(&quot;SENSOR ACTIVE&quot;);
delay(50);
}

//LOOP
void loop(){
if(digitalRead(pirPin) == HIGH){

digitalWrite(ledPin, HIGH);
if(lockLow){

//makes sure we wait for a transition to LOW before any further output is made:
lockLow = false;
Serial.println(&quot;---&quot;);
Serial.print(&quot;motion detected at &quot;);
Serial.print(millis()/1000);
Serial.println(&quot; sec&quot;);
delay(50);
}
takeLowTime = true;
}
if(digitalRead(pirPin) == LOW){
digitalWrite(ledPin, LOW); //the led visualizes the sensors output pin state
if(takeLowTime){
lowIn = millis(); //save the time of the transition from high to LOW
takeLowTime = false; //make sure this is only done at the start of a LOW phase
}
//if the sensor is low for more than the given pause,
//we assume that no more motion is going to happen
if(!lockLow &amp;&amp; millis() - lowIn &gt; pause){
//makes sure this block of code is only executed again after
//a new motion sequence has been detected
lockLow = true;
Serial.print(&quot;motion ended at &quot;); //output
Serial.print((millis() - pause)/1000);
Serial.println(&quot; sec&quot;);
delay(50);
}
}
}
