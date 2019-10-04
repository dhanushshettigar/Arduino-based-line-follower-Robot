//------------------------------------------------------- SAMPLE CODE FOR WHITE LINE FOLLOWER BY DHANUSH- DTiLABZ----------------

//------------------------------------------------------- MOTORDRIVER -L298N
//------------------------------------------------------- IR SENSOR   -TCRT5000
int TRESH = 600;          //CHNAGE BASED ON YOUR PREFFERENCE

int rightSpeed = 40 ;     //PWM PIN 9
int leftSpeed = 40 ;      //PWM PIN 10

void moveForward()
{
  analogWrite(9, rightSpeed);
  analogWrite(10, leftSpeed);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  //Serial.println("FORWARD");
}
void moveBackward()
{
  analogWrite(9, rightSpeed);
  analogWrite(10, leftSpeed);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  //Serial.println("BACKWARD");
}
void arcRight()
{
  analogWrite(9, rightSpeed);
  analogWrite(10, leftSpeed);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  //Serial.println(" ARC RIGHT");
}
void arcLeft()
{
  analogWrite(9, rightSpeed);
  analogWrite(10, leftSpeed);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  //Serial.println(" ARC LEFT");
}

void spotRight()
{
  analogWrite(9, rightSpeed);
  analogWrite(10, leftSpeed);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  //Serial.println(" SPOT RIGHT");
}
void spotLeft()
{
  analogWrite(9, rightSpeed);
  analogWrite(10, leftSpeed);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  //Serial.println(" SPOT LEFT");
}
void Stop()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  Serial.println("STOPED");
}




void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  //Serial.begin(9600);
}

void loop()
{
  int R2 = analogRead(A0);   //EXTREME RIGHT SENSOR
  int R1 = analogRead(A1);   //RIGHT SENSOR
  int C = analogRead(A2);    //CENTER SENSOR
  int L1 = analogRead(A3);   //LEFT SENSOR
  int L2 = analogRead(A4);   //EXTREME LEFT SENSOR
  //  Serial.println();
  //  Serial.print(L2);
  //  Serial.print("\t");
  //  Serial.print(L1);
  //  Serial.print("\t");
  //  Serial.print(C);
  //  Serial.print("\t");
  //  Serial.print(R1);
  //  Serial.print("\t");
  //  Serial.println(R2);
  //  Serial.print("\t");
  if (L2  < TRESH && L1 > TRESH && C > TRESH && R1 > TRESH && R2 > TRESH)  //L2 ON WHITE LINE
  {
    spotLeft();
    //Serial.print(" spotleft");
  }
  else if (L2  > TRESH && L1 < TRESH && C > TRESH && R1 > TRESH && R2 > TRESH)  //L1 ON WHITE LINE
  {
    arcLeft();
    //Serial.print(" arcleft ");
  }
  else if (L2 > TRESH && L1 > TRESH && C < TRESH && R1 > TRESH && R2 > TRESH) // C ON WHITE LINE
  {
    moveForward();
    //Serial.print(" moveForward");
  }
  else if ( L2 > TRESH && L1 > TRESH && C > TRESH && R1 > TRESH && R2 < TRESH )  //R2 ON WHITE LINE
  {

    spotRight();
    // Serial.print("spotright");
  }
  else if ( L2 > TRESH && L1 > TRESH && C > TRESH && R1 < TRESH && R2 > TRESH )  //R1 ON WHITE LINE
  {

    arcRight();
    // Serial.print("spotright");
  }
  else
  {
    arcRight();      //PREFERENCE 
    // Serial.print("spotright");
  }

}
/*
--------------------SOME MORE CONDITIONS BASED ON LINE----------------------
--->BOTH L1 & L2 ON LINE
--->BOTH R1 & R2 ON LINE
--->L1 & L2 & C ON LINE
--->R1 & R2 & C ON LINE
--->L1 & C & R1 ON LINE
*/
