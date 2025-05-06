int B = 13; // Broche du buzzer
int analogPin = A0; // Broche du capteur analogique
int analogVal; // Valeur lue par le capteur
int seuilDetection = 500; // Seuil pour détecter la flamme
unsigned long previousMillis = 0;  // For timing
int tonePhase = 0;  // For alternating tones

void setup() {
  pinMode(B, OUTPUT); // Buzzer en sortie
  Serial.begin(9600); // Démarrer la communication série
}

void loop() {
  analogVal = analogRead(analogPin); // Lire la valeur du capteur

  if (analogVal < seuilDetection) {
    Serial.println("Flamme détectée");
    
    // 🔥 Emergency siren (wee-woo) - ONLY ADDED THIS BLOCK
    if (millis() - previousMillis >= (tonePhase ? 300 : 200)) {
      tone(B, tonePhase ? 1200 : 1600); // Alternate 1600Hz and 1200Hz
      tonePhase = !tonePhase; // Switch phase
      previousMillis = millis();
    }
    
  } else {
    Serial.println("Aucune flamme détectée");
    noTone(B); // IMMEDIATE silence
    digitalWrite(B, LOW); // Original fallback
  }

  delay(100); // Pause de 100 ms (kept original timing)
}