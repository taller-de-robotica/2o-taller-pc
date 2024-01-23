int estado = "";
const int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);    // Arduino One sólo tiene un serial
}

void loop() {
  // Ejemplo: prende led
  digitalWrite(LED, HIGH);

  if(Serial.available() > 0) {
    estado = Serial.read();
    Serial.println("Estado" + estado);
    String teststr = Serial.readString();  //read until timeout
    teststr.trim();                        // remove any \r \n whitespace at the end of the String
    if (teststr == "led") {
      Serial.println("Prende/apaga led");
      // TODO: prender y apagar led
    } else {
      Serial.println("Ignorar");
    }
  }
}
