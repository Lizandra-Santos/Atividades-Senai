#include <Arduino.h>
#include "temporiza.h"
#include <WiFi.h>
#include <ArduinoJson>
#include <PubSubClient.h>

const char *mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char *mqtt_client_id = "esp/senai134/Liza2320";
const char *mqtt_topic_sub = "senai134/mesa04/Lizandra/espsub";
const char *mqtt_topic_pub = "senai134/mesa04/Lizandra/esppub";

WiFiClient espClient;
PubSubClient client(espClient);


void setup() 
{
 Serial.begin(9600);
}

void loop()
{
 
}
void callback(char *topic, byte *payload, unsigned int length)
{

  Serial.print("mensagem recebida em ");
  Serial.print(topic);
  Serial.print(": ");
  String mensagem = "";

  static unsigned long tempoInicial = 0;
  unsigned long tempoAtual = millis();

  for (int i = 0; i < length; i++)
  {
    char c = (char)payload[i];
    mensagem += c;
  }
  Serial.println(mensagem);

  }

void conectaMQTT()
{
  while (!client.connected())
  {
    Serial.print("Conectando ao MQTT...");
    if (client.connect(mqtt_client_id))
    {
      Serial.println("Conectado!");
      client.subscribe(mqtt_topic_sub);
    }
    else
    {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}
