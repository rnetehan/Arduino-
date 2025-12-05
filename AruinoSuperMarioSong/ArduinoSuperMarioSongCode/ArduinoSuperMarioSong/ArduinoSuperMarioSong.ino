int speakerPin = 12;
int ledPin = 13;

int length = 295; // the number of notes  
char notes[] = "EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb  GNFR E uaC aCD GNFR E 1 11   GNFR E aC aCD L  D C   CC C CD EC ag  CC C CDE  CC C CD EC ag  EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb EC g u aF Fa  bAAAGFEC ag  EC g u aF Fa  bF FFEDCe ec  ";

float beats[] = { 
  1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  1,2,1,1,1,1,2,
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
  2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
  1,1,1,1,1,1,1,1,1,1,2,1,1,2,
  1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
  1,1,1,1,2,1,1,1,1,1,1,1,1,2,1.3,1.3,1.3,1.3,1.3,1.3,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2,
  1,1,1,1,1.3,1.3,1.3,1,1,1,1,1,1,2
};

int tempo = 95;

void playTone(int ton1, int duration) {
  tone(speakerPin, ton1);
  digitalWrite(ledPin, LOW);  // SES ÇALIYOR → LED SÖNÜK
  delay(duration);
  noTone(speakerPin);
}

void playNote(char note, int duration) {
  char names[] = { ' ', '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 
                   'c', 'd', 'e', 'f', 'g', 'a', 'b',
                   'C','D','E','F','G','A','B','i','N','R','u','1','L','k'};

  int tones[] = { 0,1046,138,146,155,164,174,184,195,207,220,233,246,
                  261,293,329,349,391,440,493,
                  523,587,659,698,783,880,987,
                  466,740,622,415,1046,622,227 };

  for (int i = 0; i < 34; i++) {

    if (names[i] == note) {

      if (tones[i] == 0) {
        // REST (BOŞLUK)
        noTone(speakerPin);
        digitalWrite(ledPin, HIGH);     // BOŞLUKTA LED → YANIYOR
        delay(duration);
      } 
      else {
        playTone(tones[i], duration);   // NOTA → LED SÖNÜK
      }
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {

    if (notes[i] == ' ') {
      // REST
      noTone(speakerPin);
      digitalWrite(ledPin, HIGH);      // BOŞLUK → LED YANAR
      delay(beats[i] * tempo);
    } 
    else {
      playNote(notes[i], beats[i] * tempo);
    }

    // Nota sonrası kısa boşluk
    digitalWrite(ledPin, HIGH);        // KISA BOŞLUKTA DA YANAR
    delay(tempo / 2);
  }
}
