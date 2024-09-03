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
    /* Esse exemplo simula um semáforo ligando e desligando
     * as luzes verde (Q04), amarelo (Q05) e vermelho (Q06).
     */

    /* Altera o estado da saída digital Q06 para LOW.
     */
    digital_output.write(Q06, LOW);

    /* Altera o estado da saída digital Q04 para HIGH.
     */
    digital_output.write(Q04, HIGH);

    /* Envia a configuração das saídas digitais para o
     * CI.
     */
    digital_output.update();
    leds.update();
    delay(1000);

    digital_output.write(Q04, LOW);
    digital_output.write(Q05, HIGH);
    digital_output.update();
    leds.update();
    
    delay(3000);

    digital_output.write(Q05, LOW);
    digital_output.write(Q06, HIGH);
    digital_output.update();
    leds.update();
    
    delay(1000);
}