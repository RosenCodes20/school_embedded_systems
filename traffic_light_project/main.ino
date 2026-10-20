int r1 = 13;
int y1 = 12;
int g1 = 11;
int r2 = 10;
int y2 = 9;
int g2 = 8;
int r3 = 7;
int y3 = 6;
int g3 = 5;
int r4 = 4;
int y4 = 3;
int g4 = 2;

int persong1 = A0;
int personr1 = A1;
int persong2 = A2;
int personr2 = A3;

int person1Btn = A5;
int person2Btn = A4;

bool btn1Requested = false;
bool btn2Requested = false;

void setup() {
  pinMode(r1, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(y3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(y4, OUTPUT);
  pinMode(g4, OUTPUT);
  
  pinMode(persong1, OUTPUT);
  pinMode(personr1, OUTPUT);
  pinMode(persong2, OUTPUT);
  pinMode(personr2, OUTPUT);

  pinMode(person1Btn, INPUT);
  pinMode(person2Btn, INPUT);  
}

void waitAndCheckButtons(int durationMs) {
  int elapsed = 0;
  while (elapsed < durationMs) {
    if (digitalRead(person1Btn) == HIGH) {
      btn1Requested = true;
    }
    
    if (digitalRead(person2Btn) == HIGH) {
      btn2Requested = true;
    }

    delay(100);
    elapsed += 100;
  }
}

void loop() { 
  digitalWrite(g1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(g3, HIGH);
  digitalWrite(r4, HIGH);

  digitalWrite(personr1, HIGH); 
  digitalWrite(persong1, LOW); 

  if (btn2Requested) {
    digitalWrite(persong2, HIGH);
    digitalWrite(personr2, LOW);
  } else {
    digitalWrite(personr2, HIGH);
    digitalWrite(persong2, LOW);
  }

  waitAndCheckButtons(9000);

  btn2Requested = false;

  digitalWrite(g1, LOW); 
  digitalWrite(r2, LOW);
  digitalWrite(g3, LOW); 
  digitalWrite(r4, LOW);
  digitalWrite(persong2, LOW); 
  digitalWrite(personr2, LOW);
  digitalWrite(personr1, LOW); 
  digitalWrite(persong1, LOW);

  digitalWrite(y1, HIGH); 
  digitalWrite(y2, HIGH);
  digitalWrite(y3, HIGH); 
  digitalWrite(y4, HIGH);

  waitAndCheckButtons(3000);

  digitalWrite(y1, LOW); 
  digitalWrite(y2, LOW);
  digitalWrite(y3, LOW); 
  digitalWrite(y4, LOW);

  digitalWrite(r1, HIGH);
  digitalWrite(g2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(g4, HIGH);

  digitalWrite(personr2, HIGH); 
  digitalWrite(persong2, LOW);  

  if (btn1Requested) {
    digitalWrite(persong1, HIGH);
    digitalWrite(personr1, LOW);
  } else {
    digitalWrite(personr1, HIGH);
    digitalWrite(persong1, LOW);
  }

  waitAndCheckButtons(9000);

  btn1Requested = false;

  digitalWrite(r1, LOW); 
  digitalWrite(g2, LOW);
  digitalWrite(r3, LOW); 
  digitalWrite(g4, LOW);
  digitalWrite(personr2, LOW); 
  digitalWrite(persong2, LOW);
  digitalWrite(personr1, LOW); 
  digitalWrite(persong1, LOW);

  digitalWrite(y1, HIGH); 
  digitalWrite(y2, HIGH);
  digitalWrite(y3, HIGH); 
  digitalWrite(y4, HIGH);

  waitAndCheckButtons(3000);

  digitalWrite(y1, LOW); 
  digitalWrite(y2, LOW);
  digitalWrite(y3, LOW); 
  digitalWrite(y4, LOW);
}