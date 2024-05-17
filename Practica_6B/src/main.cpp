#include <SPI.h>
#include <MFRC522.h>

// Definición de pines para el lector RFID
#define RST_PIN 9
#define SS_PIN 10

// Crear un objeto MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  // Inicializar la comunicación serial a 9600 baudios
  Serial.begin(9600);
  
  // Inicializar el bus SPI
  SPI.begin();
  
  // Inicializar el lector RFID
  mfrc522.PCD_Init();
  
  // Imprimir mensaje de inicio
  Serial.println("Lectura del UID");
}

void loop() {
  // Comprobar si hay una nueva tarjeta presente
  if (mfrc522.PICC_IsNewCardPresent()) {
    // Si hay una nueva tarjeta, intentar leer su UID
    if (mfrc522.PICC_ReadCardSerial()) {
      // Imprimir mensaje indicando el inicio del UID
      Serial.print("Card UID:");
      
      // Recorrer cada byte del UID
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        // Imprimir el byte del UID en formato hexadecimal
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
      }
      
      // Imprimir nueva línea para separar los UID
      Serial.println();
      
      // Detener la comunicación con la tarjeta actual
      mfrc522.PICC_HaltA();
    }
  }
}
