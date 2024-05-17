#include <Arduino.h>
#include <FreeRTOS.h>

const int led1 = 2; // Pin of the LED

// Function prototype
void toggleLED(void * parameter);

void setup()
{
  Serial.begin(115200); // Cambiado a una velocidad de transmisión más común
  pinMode(led1, OUTPUT); // Configura el pin del LED como salida
  
  // Creamos la tarea para controlar el LED
  xTaskCreate(
    toggleLED,          // Función de la tarea
    "Toggle LED",       // Nombre de la tarea
    10000,              // Tamaño de la pila de la tarea
    NULL,               // Parámetro de la tarea
    1,                  // Prioridad de la tarea
    NULL                // Manejador de la tarea (no utilizado)
  );
}

void loop()
{
  // No necesitamos un bucle loop() ya que vamos a usar FreeRTOS para manejar las tareas.
}

// Esta función se invoca cuando se crea la tarea toggleLED
void toggleLED(void * parameter)
{
  for (;;) // Bucle infinito
  {
    digitalWrite(led1, HIGH);   // Enciende el LED
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Espera 1 segundo
    digitalWrite(led1, LOW);    // Apaga el LED
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Espera 1 segundo
  }
}
