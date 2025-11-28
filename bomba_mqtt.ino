//Codigo 2 led 
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "IP_AWS"; 

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

// Função que recebe a ordem
void callback(char* topic, byte* payload, unsigned int length) {
  String mensagem = "";
  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }
  
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
    // ID único diferente do sensor
    if (client.connect("ESP32_Bomba_Anna_Final")) { 
      Serial.println("Bomba Conectada!");
      client.subscribe("irrigacao/comando"); // Assina o tópico
    } else delay(5000);
  }
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();
}
