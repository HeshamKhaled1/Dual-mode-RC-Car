int m1a = 7;
int m1b = 8;
int m2a = 12;
int m2b = 13;
int ir_rigth=2;
int ir_left=3;
char val;
bool flag=false;       // flag to be used in switching between modes
void setup() 
{
pinMode(5, OUTPUT);    // Digital pin 5 set as output Pin
pinMode(6, OUTPUT);    // Digital pin 6 set as output Pin
pinMode(m1a, OUTPUT);  // Digital pin 7 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 8 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
pinMode(ir_rigth,INPUT);    // Digital pin 2 set as output Pin
pinMode(ir_left, INPUT);    // Digital pin 3 set as output Pin
Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
  val = Serial.read();
    
  Serial.println(val);
    if(val == 'W'){
    Serial.println(val);
    flag=true;
    while(flag)
      {   
        irMode();        
      }    
  }else if (val=='U'){
    flag=true;
    while(flag)  {  
    manualMode(); 
    }   
  }
  }

  
}
/*******************************************************************************************************************************/
/**********************                                  Manual MODE                                      **********************/
/*******************************************************************************************************************************/
void manualMode(){
    val=Serial.read();
if( val == 'F') // Forward
    {
      analogWrite(5,255);    
      analogWrite(6,255);  
      delay(5);          
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }
  else if(val == 'B') // Backward
    {
      analogWrite(5,255);    
      analogWrite(6,255);   
      delay(5);         
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
    }
  
    else if(val == 'R') //Left
    {
    analogWrite(5,255);    
    analogWrite(6,255);     
    delay(5);       
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
    else if(val == 'L') //Right
    {
    analogWrite(5,255);    
    analogWrite(6,255);
    delay(5);            
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
    
  else if(val == 'S') //Stop
    {
    analogWrite(5,255);    
    analogWrite(6,255);
    delay(5);      
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
  else if(val == 'G') //Forward Right
    {
    analogWrite(5,255);    
    analogWrite(6,255);
    delay(5);
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
  else if(val == 'H') //Backward Right
    {
    analogWrite(5,255);    
    analogWrite(6,255);
    delay(5);
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
   else if(val == 'I') //Forward Left
    {
    analogWrite(5,255);    
    analogWrite(6,255);
    delay(5);
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
  else if(val == 'J') //Backward Left
    {
    analogWrite(5,255);    
    analogWrite(6,255);
    delay(5);      
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH); 
    }else if(val == 'u'){
      Serial.println(val);
      flag=false;      
    } 
}

/*******************************************************************************************************************************/
/**********************                                  IR MODE                                          **********************/
/*******************************************************************************************************************************/
void irMode(){
  int X=digitalRead(2);
  int Y=digitalRead(3);
  if(X==1 and Y==1) // both motors clockwise
  {
    analogWrite(5,100);    
    analogWrite(6,100);
    delay(5); 
    digitalWrite(m1b,LOW);
    digitalWrite(m1a,HIGH);
    digitalWrite(m2b,LOW);
    digitalWrite(m2a,HIGH);
    delay (5);
    digitalWrite(m1b,HIGH);
    digitalWrite(m1a,LOW);
    digitalWrite(m2b,HIGH);
    digitalWrite(m2a,LOW);
  }
  if(X==1 and Y==0) // motor X clockwise and Y anti-clockwise
  {
    analogWrite(5,100);    
    analogWrite(6,100);
    delay(5); 
    digitalWrite(m1b,LOW);
    digitalWrite(m1a,HIGH);
    digitalWrite(m2b,HIGH);
    digitalWrite(m2a,LOW);
  }
  if(X==0 and Y==1) // motor Y clockwise and X anti-clockwise
  {
    analogWrite(5,100);    
    analogWrite(6,100);
    delay(5); 
    digitalWrite(m1b,HIGH);
    digitalWrite(m1a,LOW);
    digitalWrite(m2b,LOW);
    digitalWrite(m2a,HIGH);
  }
  if(X==0 and Y==0) // both motors anti-clockwise
  {
    analogWrite(5,100);    
    analogWrite(6,100);
    delay(5); 
    digitalWrite(m1b,LOW);
    digitalWrite(m1a,HIGH);
    digitalWrite(m2b,LOW);
    digitalWrite(m2a,HIGH);
  }
  val=Serial.read();
  if(val == 'w'){
    flag=false;
  }  
  
}