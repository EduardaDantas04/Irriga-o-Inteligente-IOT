#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "44.192.34.245"; 

const int pinoBomba = 2; // LED

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(pinoBomba, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

// Ouve a ordem da AWS
void callback(char* topic, byte* payload, unsigned int length) {
  String mensagem = "";
  for (int i = 0; i < length; i++) mensagem += (char)payload[i];
  
  Serial.print("Comando Recebido: ");
  Serial.println(mensagem);

  if (mensagem == "LIGAR") {
    digitalWrite(pinoBomba, HIGH);
  } else if (mensagem == "DESLIGAR") {
    digitalWrite(pinoBomba, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    // ID Diferente para não dar conflito
    if (client.connect("ESP32_BOMBA_ANNA")) { 
      Serial.println("BOMBA Conectada!");
      client.subscribe("irrigacao/comando"); // Assina o tópico
    } else delay(5000);
  }
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();
}
