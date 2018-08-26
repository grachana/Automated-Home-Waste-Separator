int moisture_sensor = A0;
int ir_sensor=4;
int metal_sensor=A2;
int output_value ;

void moisture();
void ir();
void metal();
int pos=0;
int pos1=0; 
float metalDetected;
int monitoring;


#include <Servo.h>
Servo myservo;
Servo mservo;

void setup() {

Serial.begin(115200);
pinMode(13,OUTPUT);
pinMode(ir_sensor,INPUT);
myservo.attach(9);
mservo.attach(10);
Serial.println("Reading From the Sensor ...");

delay(2000);

}

void loop()
{
Serial.println("processing...");
   ir();
  // metal();
  // moisture();
}

void ir()
{
if(digitalRead(ir_sensor)==HIGH)      //Check the sensor output
{
digitalWrite(13, HIGH);
Serial.println("WASTE NOT DETECTED");
//set the LED on
}
else if(digitalRead(ir_sensor)==LOW)
{
digitalWrite(13, LOW);    // set the LED off
Serial.println("WASTE DETECTED");
moisture();
metal();
}
delay(500);              // wait for a second
}


void metal()
{
monitoring = analogRead(metal_sensor);
metalDetected = (float) monitoring*100/1024.0;
/*Serial.print("14CORE METAL DETECTOR TEST");
delay(500);*/
Serial.print("Initializing Proximity Sensor");
delay(500);
Serial.print("Please wait...");
delay(1000);
Serial.print("Metal is Proximited = ");
Serial.print(metalDetected);
Serial.println("%");
if (monitoring <250)
{
Serial.println("Metal is Detected");


}

}

void moisture()
{
 
output_value= analogRead(moisture_sensor);
Serial.print("moisture:");
 Serial.println(output_value);

if(output_value<700)
{
Serial.println("Mositure is present");
{
mservo.write(45);
delay(15);
}
delay(3000);
{
{myservo.write(-90);delay(15);}
delay(4000);
{myservo.write(90);delay(15);}
}
delay(3000);
{
  mservo.write(90);
  delay(15);
}
}
else
{
Serial.println("DRY WASTE IS PRESENT");
for(pos1=90;pos1<=0;pos1--)
{
  mservo.write(pos1);
  delay(15);
}
delay(5000);
/*for(pos=0;pos<=90;pos++)
{
myservo.write(pos);
delay(15);
}*/
myservo.write(-90);
delay(3000);
myservo.write(90);
}
delay(1000);
}

  


/*void loop() {

output_value= analogRead(moisture_sensor);
 Serial.println(output_value);

if(output_value<700)
 {

Serial.println("Mositure");

}

delay(1000);

}*/
