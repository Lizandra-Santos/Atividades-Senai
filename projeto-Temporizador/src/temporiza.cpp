#include "temporiza.h"
#include <Arduino.h>


/**
 * @brief construtor da classe temporizador
 */
temporiza::temporiza(unsigned long tempo_ms)
{
     intervalo = tempo_ms;
  tempoInicial = 0;
  ativo = false;
}

/**
 * @brief inicia o temporizador mostrando que e true
 */
void temporiza::begin()
{
 tempoInicial = millis();
 ativo = true;
}

/**
 * @brief para o temporizador,recebendo false
 */
void temporiza::parar();
{
  ativo = false;
}
/**
 * @brief reinicia o temporizador
 */
void temporiza::reiniciar()
{
 tempoInicial = millis();
 ativo = true;
}

bool temporiza::Estapronto()
{
  if (!ativo) return false;
  unsigned long agora = millis();
  return (agora - tempoInicial) >= intervalo;
}

bool temporiza::EstaAtivo()
{
  return ativo;
}

void definirIntervalo(unsigned long tempo_ms)
{
  intervalo = tempo_ms;
}

