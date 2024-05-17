# PRÁCTICA 3: WIFI  y BLUETOOTH  

## Práctica A: Generación de una página web  

### INFORME

 Vamos a analizar este código paso por paso para ver como funciona. 
 Más tarde analizaremos el código HTML más en profundidad.

 Código utilizado en la práctica:

```c
#include <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>

// SSID & Password
const char* ssid = "Xiaomi_11T_Pro"; // Enter your SSID here
const char* password = "12345678"; //Enter your Password here
WebServer server(80);

void handle_root();

// Object of WebServer(HTTP port, 80 is defult)
void setup() {
Serial.begin(115200);
Serial.println("Try Connecting to ");
Serial.println(ssid);
// Connect to your wi-fi modem
WiFi.begin(ssid, password);
// Check wi-fi is connected to wi-fi network
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected successfully");
Serial.print("Got IP: ");
Serial.println(WiFi.localIP()); //Show ESP32 IP on serial
server.on("/", handle_root);
server.begin();
Serial.println("HTTP server started");
delay(100);
}
void loop() {
server.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>Pagina web Ruben Garcia y Joan Gallardo &#128522;</h1>\
<img src=\"https://www.mouser.es/images/espressifsystems/images/ESP32-DevKitC-32E_SPL.jpg\" alt=\"Mi imagen\">\
</body>\
</html>";

// Handle root url (/)
void handle_root() {
server.send(200, "text/html", HTML);
}
``` 

1. Se incluyen las bibliotecas <Wifi.h> y <WebServer.h> para la creación del servidor.
2. Se definen las credenciales ssid y passwords. En este caso hemos utilizado las credenciales para tener acceso al servidor proporcionado por el profesor.
3. Se crea un objeto de la clase WebServer llamado server que escucha en el puerto HTTP por defecto (80).
4. En la función `setup()`:
    - Se inicializa la comunicación serial a 115200 baudios.
    - Se imprime en la consola un mensaje: Intentando conectar a Xiaomi_11T_Pro, que es el nombre del servidor.
    - Se espera hasta conectar, pero mientras tanto `while (WiFi.status() != WL_CONNECTED)` va imprimiendo un punto indicando que está en proceso de conectarse.
    - Una vez establecida la conexión, se imprime la dirección IP.
    - Se define un manejador de ruta `handle_root` que se llama cuando se accede a la raíz del servidor `/`.
    - Se inicializa el servidor.
    - Se imprime que el servidor se ha inicializado.
5. En la función `loop()` se llama al método `handleClient()` sel objeto server.
6. Se escribe el código HTML que queremos que se muestre en la página web.
7. La función `handle_root()` es un manejador de ruta. 
    - Dentro se utiliza el método `server.send()` para enviar una respuesta HTTP al cliente que realizó la solicitud. En este caso, se envía una respuesta con el código de estado HTTP 200, que significa OK y se establece el tipo de contenido como "text/html". El tercer parámetro es el contenido HTML que enviaremos al servidor y que hemos escrito anteriormente. 

Ahora vamos a ver el código HTML que enviamos a la web:
```
<!DOCTYPE html>\
<html>\
<body>\
<h1>Pagina web Ruben Garcia y Joan Gallardo &#128522;</h1>\
<img src=\"https://www.mouser.es/images/espressifsystems/images/ESP32-DevKitC-32E_SPL.jpg\" alt=\"Mi imagen\">\
</body>\
</html>
``` 
1. En la primera línea `<!DOCTYPE html>` declaramos el tipo de documento como HTML5. Es necesario al principio de cada documento HTML5 para especificar su tipo.
2. La etiqueta `<html>` marca el comienzo del documento HTML.
3. La etiqueta `<body>` marca el inicio del cuerpo del documento HTML.
4. `<h1>Pagina web Ruben Garcia y Joan Gallardo &#128522;</h1>`: Esta línea representa el encabezado de nivel 1, que se utiliza para títulos principales.
5. `<img src=\"https://www.mouser.es/images/espressifsystems/images/ESP32-DevKitC-32E_SPL.jpg\" alt=\"Mi imagen\">`: Esta línea con la etiqueta `<img>` se utiliza para insertar una imagen a la página web.
6. `</body>`: Esta etiqueta marca el final del cuerpo del documento HTML.
7. `</html>:`: Esta etiqueta marca el final del documento HTML.


