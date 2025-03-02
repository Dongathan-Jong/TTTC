#include <HCSR04.h>
#include <Servo.h>

UltraSonicDistanceSensor distanceSensor(13, 12);  // Initialize sensor that uses digital pins 13 and 12.
UltraSonicDistanceSensor otherdistanceSensor(6, 5);

Servo myservo;
Servo otherservo;
Servo keyboardservo;

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
     myservo.attach(9);
     myservo.write(0); 
     otherservo.attach(8);
     otherservo.write(0);
     keyboardservo.attach(3);
     keyboardservo.write(0);
     otherservo.write(60);
     pinMode(2, INPUT_PULLUP);
}

void loop () {
    if(distanceSensor.measureDistanceCm() == -1 )
    {
      myservo.write(0);
    }
    else if(distanceSensor.measureDistanceCm() <= 40 && distanceSensor.measureDistanceCm() > 0)
    {
      myservo.write(80);
    }
    else
    {
      myservo.write(0);
    }
    Serial.println(otherdistanceSensor.measureDistanceCm());

    if(digitalRead(2) == LOW)
    {
      otherservo.write(180);
      
      for(int i = 0; i < 50; i++)
      {
        if(otherdistanceSensor.measureDistanceCm() < 25)
      {
        keyboardservo.write(30);
        delay(100);
      otherservo.write(90);
      delay(200);
      otherservo.write(0);
      delay(200);
      otherservo.write(90);
      delay(200);
      otherservo.write(0);
      delay(200);
      otherservo.write(90);
      delay(200);
      otherservo.write(0);
      delay(200);
      otherservo.write(90);
      delay(200);
      otherservo.write(60);
      }
      
      

      }
      
      
      otherservo.write(0);

      delay(1000);
      otherservo.write(60);

      

    }

    if(otherdistanceSensor.measureDistanceCm() < 30)
      {
        keyboardservo.write(30);
        delay(1000);
      }
      else
      {
        keyboardservo.write(0);
      }
    delay(50);

}
