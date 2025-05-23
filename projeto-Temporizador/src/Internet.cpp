#include <Arduino.h>
#include <WiFi.h>
#include "Internet.h"
#include "senhas.h"
//* Configuracao do WiFi


const unsigned long TempoEsperaConexao = 15000;
const unsigned long tempoEsperaReconexao = 5000;

void conectaWiFi()
{
  Serial.printf("Conectando ao Wifi: %s", SSID);
  WiFi.begin(SSID, SENHA);
  unsigned long TempoInicial = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - TempoInicial < TempoEsperaConexao)
  {
    Serial.print(".");
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("\n WiFi Conectado Com Sucesso");
    Serial.print("Endereco IP: ");
    Serial.println(WiFi.localIP());
  }

  else
  {
    Serial.println("falha ao conectar no WiFi. Verifique o nome da rede e da senha");
    checkWiFi;
  }
}

void checkWiFi()
{
  unsigned long tempoAtual = millis();
  static unsigned long tempoUltimaConexao = 0;
  if (tempoAtual - tempoUltimaConexao > TempoEsperaConexao)
  {
    if (WiFi.status() != WL_CONNECTED)
    {
      Serial.println("\n conexao perdida!, tentando reconectae.....");
      conectaWiFi();
    }
    tempoUltimaConexao = tempoAtual;
  }
}
