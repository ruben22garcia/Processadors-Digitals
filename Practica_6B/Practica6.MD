# PRACTICA 5 :  Buses de comunicación II (SPI)  

El objetivo de la practica es comprender el funcionamiento del bus spi 

## Ejercicio Practico 2 LECTURA DE ETIQUETA RFID 

### 1. Descibir la salida por el puerto serie 
El código utilizado es el siguiente:

```c
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
```

Este programa permite que con un microprocesador y un lector RFID-RC522 detectar y leer el UID de las tarjetas RFID que se acercan al lector. 
El UID se muestra en el puerto serial (monitor) en formato hexadecimal.
Este código puede servir como base para implementar funcionalidades adicionales, como la autenticación o el control de acceso basado en tarjetas RFID.

### 2. Explicar el funcionamiento 

1. Librerías:
   - `<SPI.h>`: Biblioteca necesaria para la comunicación SPI.
   - `<MFRC522.h>`: Biblioteca que incluye soporte para el lector RFID-RC522.
2. Inicialización de pines:
   - Define el pin utilizado para el reinicio del lector RFID (RST_PIN 9).
   - Define el pin utilizado para la selección del esclavo del lector RFID (SS_PIN 10).
3. Creación del objeto MFRC522 utilizando los pines como parámetros.
4. Función `setup()`:
   - Se inicializa la comunicación serial a 9600 baudios.
   - Se inicializa el bus SPI.
   - Se inicializa el lector RFID con `mfrc522.PCD_Init()`.
   - Se imprime un mensaje de inicio.
5. Función `loop()`:
   - Se comprueba si hay una nueva tarjeta presente con `mfrc522.PICC_IsNewCardPresent()`.
   - Si es el caso de que existe una tarjeta nueva presente, se intenta leer el UID de esta con `mfrc522.PICC_ReadCardSerial()`.
   - Si la lectura es exitosa, el programa procede a imprimir el UID de la tarjeta en formato hexadecimal byte por byte. Recorre cada byte del UID utilizando un bucle for y lo imprime.
   - Después de imprimir el UID se detiene la comunicación con `mfrc522.PICC_HaltA();`.




 
 


