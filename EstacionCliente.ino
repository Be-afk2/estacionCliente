
#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 4
#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "fh_ba5a78";
const char *password = "la clave la tiene la linda";
String mac;
const int PinEntrada = 4;

bool verificador = false;
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PinEntrada, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  dht.begin();
  digitalWrite(5, LOW);
  conectarWiFi();
  mac = WiFi.macAddress();
  mac.replace(":", "-");
}
 
void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
 // Serial.println("digitalRead(PinEntrada)");
  hacerPeticionGET("http://192.168.1.8:3000"+estacion()+"&mc="+mac);
  Serial.println("http://192.168.1.8:3000"+estacion()+"&mc="+mac);
  Serial.println(estacion());

}


String hacerPeticionGET(String url) {
  HTTPClient http;
  http.begin(url); // Iniciar conexión

  int codigoRespuesta = http.GET(); // Hacer GET

  if (codigoRespuesta > 0) {
    String cuerpo = http.getString();
    Serial.println("Código HTTP: " + String(codigoRespuesta));
    Serial.println("Respuesta: " + cuerpo);
    http.end();
    return cuerpo;
  } else {
    Serial.println("Error en la petición HTTP");
    http.end();
    return "";
  }
}


String estacion() {
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  String datos = "?tem=";
  datos += temperatura;
  datos += "&hum=";
  datos += humedad;
  Serial.println(datos);
  return datos;
}

void conectarWiFi() {
  Serial.print("Conectando a WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado.");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  digitalWrite(5, HIGH);
}
