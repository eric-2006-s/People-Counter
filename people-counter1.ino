const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 11;
const int trigPin2 = 5;
const int echoPin2 = 6;
const int ledPin2 = 7;
long duration2;
int distance2;
long duration;
int distance;
int count = 0;
int strt=0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin2, OUTPUT);
   pinMode(12, OUTPUT);    
  pinMode(8, OUTPUT);  
 Serial.begin(9600);
}

void loop() { 
   if (Serial.available() > 0) {             
    char incomingByte = Serial.read();      
    Serial.print("Received: ");             
    Serial.println(incomingByte);           

    if (incomingByte == '0') {              
      
      count==0; 
      Serial.println(count);             
    } else if (incomingByte == '1') {       
      count=count+1; 
      Serial.println(count);              
    }
    else if (incomingByte == '2') {       
      count=count-1; 
       if (count<0)
    {count=0;} 
      Serial.println(count);             
    }
    else if (incomingByte == '3') {       
      strt=1;               
    }
    else if (incomingByte == '4') {       
      strt=0;               
    }

  }
  if(strt==1)
  {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
  distance = duration * (0.034 / 2);
  if (distance <5)  {
    digitalWrite(ledPin, HIGH); 
    count=count+1; 
    Serial.println(count);
    delay(1500);
  } else {
    digitalWrite(ledPin, LOW);   
  }
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * (0.034 / 2);
  if (distance2 <5)  {
    digitalWrite(ledPin2, HIGH); 
    count=count-1; 
    if (count<0)
    {count=0;}
    Serial.println(count);
    delay(1500);
  } else {
    digitalWrite(ledPin2, LOW);   
  }
  delay(200);
  }
}
