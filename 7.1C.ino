char m;
 
void setup() {
pinMode(7,OUTPUT);   //left motors forward
pinMode(8,OUTPUT);   //left motors reverse
pinMode(9,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse 
Serial.begin(9600);
 
} 
 
void loop() {
if(Serial.available()){
  m = Serial.read();
  Serial.println(m);
}
 
if(m == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(9,HIGH);
  digitalWrite(7,HIGH);
}
 
else if(m == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(8,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(m == 'L'){      
  digitalWrite(9,HIGH);   //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
}
 
else if(m == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(7,HIGH);
}


else if(m == 'S'){      //STOP (all motors stop)
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(10,LOW);
}


delay(100);
}
