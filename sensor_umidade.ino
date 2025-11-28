/Codigo sensor umidade
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "IP_AWS"; 

const int pinoSensor = 34; 

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(pinoSensor, INPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void reconnect() {
  while (!client.connected()) {
    // ID único para não dar conflito
    if (client.connect("ESP32_Sensor_Anna_Final")) { 
      Serial.println("Sensor Conectado!");
    } else delay(5000);
  }
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  int valorBruto = analogRead(pinoSensor);
  int umidade = map(valorBruto, 0, 4095, 0, 100);

  // Envia SÓ O NÚMERO (Sem %)
  char msg[50];
  sprintf(msg, "%d", umidade);
  
  client.publish("irrigacao/sensor/umidade_solo", msg);
  
  Serial.print("Umidade Enviada: ");
  Serial.println(msg);
  
  delay(5000); 
}
