## Digital Output
Esta biblioteca manipula as saídas digitais via SPI (Serial Peripheral Interface) e fornece uma camada de abstração para facilitar a utilização das saídas digitais da Industrialli Hub.

### Exemplo

```c
#include <Arduino.h>

#include "industrialli_hubInit.h"
#include "industrialli_ledsHub.h"
#include "industrialli_digital_output.h"

industrialli_hubInit hub;
industrialli_ledsHubCtrl ledsCtrl;
industrialli_digital_output iso;

void setup(){
	hub.begin();
	ledsCtrl.begin();

	iso.begin();
	iso.enable();
}

void loop(){
  iso.write(Q03, HIGH);
  iso.update();	
}
```

### Funções

Segue abaixo as funções desta biblioteca.

<details>
<summary>begin</summary>

Inicializa a biblioteca.

**Parâmetros:** void

**Retorno:** void
</details>

<details>
<summary>enable</summary>

Habilita as saídas digitais da Hub.

**Parâmetros:** void

**Retorno:** void
</details>

<details>
<summary>disable</summary>

Desabilita as saídas digitais da Hub.

**Parâmetros:** void

**Retorno:** void
</details>

<details>
<summary>update</summary>

Atualiza as saídas digitais da hub. Está função envia os valores de todas as saídas digitais para o CI via SPI.

**Parâmetros:** void

**Retorno:** void
</details>

<details>
<summary>write</summary>

Está função atualiza o valor da saída digital para ser enviada posteriormente pela função update.

**Parâmetros:** 

- uint8_t _port: número da porta da saída digital. 
- bool _value: valor.

**Retorno:** void
</details>

<details>
<summary>set_power_leds_status</summary>

Seta os leds da alimentação conforme seu status.

**Parâmetros:** void

**Retorno:** void
</details>

<details>
<summary>output_1_to_8_status</summary>

Retorna verdadeiro para operação normal e falso para anomalia nas saídas de 1 a 8.

**Parâmetros:** void

**Retorno:** bool
</details>

<details>
<summary>output_9_to_16_status</summary>

Retorna verdadeiro para operação normal e falso para anomalia nas saídas de 9 a 16.

**Parâmetros:** void

**Retorno:** void
</details>
