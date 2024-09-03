#include "industrialli_hub.hpp"

industrialli_hub hub;

void setup(){
    /* Inicializa a industrialli hub e algumas bibliotecas
     * padrões da Industrialli Hub, incluindo a biblioteca 
     * de leds.
     */
    hub.begin();

    /* Inicializa a biblioteca de saídas digitais.
     */
    digital_output.begin();

    /* Habilita o CI que controla as saídas digitais
     * isoladas.
     */
    digital_output.enable();
}

void loop(){

    /* O motor de passo nesse exemplo necessita
     * de 400 pulsos para realizar uma volta completa.
     *
     * Este loop envia 400 pulsos para o motor de passo
     * através da saída digital Q02.
     */
    for (size_t i = 0; i < 400; i++){

        /* Inverte o estado da saída digital isolada Q02.
         */
        digital_output.toggle(Q02);
        digital_output.update();
        leds.update();
        delayMicroseconds(350);
    }

    delay(1000);

    /* Inverte o sentido de rotação do motor de passo através
     * da saída digital Q03.
     */
    digital_output.toggle(Q03);

    /* Envia o estado das saídas digitais para o CI.
     */
    digital_output.update();
    leds.update();

    for (size_t i = 0; i < 400; i++){
        digital_output.toggle(Q02);
        digital_output.update();
        leds.update();
        delayMicroseconds(350);
    }
}