int in1 = 7; //upper right 
int in2 = 8; // lower right 
int ENAA = 5;
int in3 = 13; // upper left 
int in4 = 12; // lower left 
int ENAB = 6;
int Speed = 100;

char incomingByte;
void forward(){
    
    analogWrite(ENAA,Speed);
    analogWrite(ENAB,Speed);
 }

 void backward(){
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);

    analogWrite(ENAA,Speed);
    analogWrite(ENAB,Speed);
  }

 void left(){
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);


    analogWrite(ENAA,Speed);
  }

  void right(){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);

    analogWrite(ENAB,Speed);
   }

  void Stop(){
    analogWrite(ENAA,0);
    analogWrite(ENAB,0);
    }

 
void setup(){
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.print(incomingByte);

    // say what you got:
    if (incomingByte == 'F'){
        
         forward();
      }
    else if (incomingByte == 'B'){
         backward();
      }
    else if (incomingByte == 'L'){
         left();
      }
    else if (incomingByte == 'R'){
        right();
      }
    else if (incomingByte == 'S'){
        Stop();
      }
     
  }
  
}
