#ifndef TEMPORIZA_H
#define TEMPORIZA_H


class temporiza
{
    private:
 unsigned long intervalo = 0;
 float tempoAcumulado = 0;
 unsigned long tempoInicial =false;
 bool ativo = false;

    public:
temporiza(unsigned long tempo_ms = 1000);
    
    void begin();
    void parar();
    void reiniciar();
    void definirIntervalo(unsigned long tempo_ms);

    bool estaPronto();
    bool EstaAtivo();
     
    
};



#endif