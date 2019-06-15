#define BUZZER 6 

int tones[] = {440, 880, 220};
int durs[]  = {100, 100, 100};


void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i=0; i<3; i++)
  { 
    tone(6, tones[i], durs[i]);
    delay( durs[i] * 2 );
  } 
  
}
