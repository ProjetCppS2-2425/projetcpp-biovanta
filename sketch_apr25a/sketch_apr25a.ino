int B = 13; // Broche du buzzer
int analogPin = A0; // Broche du capteur analogique
int analogVal; // Valeur lue par le capteur
int seuilDetection = 500; // Seuil pour détecter la flamme

void setup() {
  pinMode(B, OUTPUT); // Buzzer en sortie
  Serial.begin(9600); // Démarrer la communication série
}

void loop() {
  analogVal = analogRead(analogPin); // Lire la valeur du capteur

  if (analogVal < seuilDetection) {
    Serial.println("Flamme détectée"); // Message clair
    digitalWrite(B, HIGH); // Allumer le buzzer
  } else {
    Serial.println("Aucune flamme détectée"); // Message clairs
    digitalWrite(B, LOW); // Éteindre le buzzer
  }

  delay(100); // Pause de 100 ms
}