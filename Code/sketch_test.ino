int OSEPin = 2;
int MosPin = 11;

bool BTurn = true;
int turns = 0;
float TurnSpeed = 0;
long StartMillis = 0;
long PreviousLoopMillis = 0;
int PreviousState = 0;
float Turn = 0;

float TargetSpeed = 1700;

bool MosState = 0;
long PreviousSwitch = 0; 

int Speed = 40;
float MSpeed = 512

void setup() {
  Serial.begin(9600);
  pinMode(OSEPin,INPUT);
  pinMode(MosPin,OUTPUT);
}

void loop() {
  int OpRead = digitalRead(2);
  if(BTurn){
    //read turn speed
    if(OpRead != PreviousState){
      Turn++;
      PreviousState = OpRead;
    }
    if(turn/4 == 10){   
      long TimeDifference = StartMillis - millis();
      StartMillis = millis();
      Turn = 60000/TimeDiffrence*10 / 4;
      TurnSpeed = Turn;
      Turn = 0;
      if(abs(TurnSpeed-TargetSpeed) > 20){
        if(MSpeed > 0 && TurnSpeed  > TargetSpeed){
          MSpeed = MSpeed - 10;
        }else if(MSpeed < 1024 && TurnSpeed < TargetSpeed){
          MSpeed = MSpeed + 10;
        }
        float Speed = MSpeed
        map(Speed,0,1024,30,50)
        analogWrite(MosPin,Speed);
       }
       )
     }
  }else{
    analogWrite(MosPin,0);
  }
}

