[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# industrialli digital output

Biblioteca para manipulação das saídas digitais da Industrialli Hub, com a utilização da biblioteca Hardware Abstraction Layer (HAL).

> [!IMPORTANT]  
> Consulte a biblioteca geral da Industrialli Hub.

## Exemplo
No exemplo abaixo, é inicializado a biblioteca de saídas digitais e ativado o CI que controla as saídas digitais isoladas, logo em seguida as saídas Q01, Q08 e Q16 são ativadas, e as saídas Q05 e Q14 são desativadas.

```cpp
#include "industrialli_hub.hpp"

industrialli_hub hub;

int main(){
    hub.begin();

    digital_output.begin();
    digital_output.enable();
    digital_output.write(Q01, HIGH);
    digital_output.write(Q05, LOW);
    digital_output.write(Q08, HIGH);
    digital_output.write(Q14, LOW);
    digital_output.write(Q16, HIGH);
    digital_output.update();
    digital_output.update_power_leds_status();
    leds.update();
  
    while(1){
    }
}
```

## Funções

Segue abaixo as funções disponíveis para a manipulação das saídas digitais isoladas da Industrialli Hub.

<details>
<summary>begin</summary>

Inicializa as saídas digitais.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
digital_output.begin();
```
</details>

<details>
<summary>enable</summary>

Ativa o CI que controla as saídas digitais isoladas.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
digital_output.enable();
```
</details>

<details>
<summary>disable</summary>

Desativa o CI que controla as saídas digitais isoladas.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
digital_output.disable();
```
</details>


<details>
<summary>update</summary>

Envia as configurações de quais saídas devem ser ativadas ou desativadas para o CI.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
digital_output.update();
```
</details>

<details>
<summary>write</summary>

Configura uma saída digital como ligada ou desligada.

**Parâmetros:** 
- DIGITAL_PIN: Enum das saídas digítais: Q01, Q02, ... Q16.
- bool: Valor da saída digital: 0/LOW para desligar a saída digital e 1/HIGH para ligar a saída digital.

**Retorno:** void

**Exemplo**
```cpp
digital_output.write(Q01, HIGH);
digital_output.write(Q05, LOW);
digital_output.write(Q08, HIGH);
digital_output.write(Q14, LOW);
digital_output.write(Q16, HIGH);
```
</details>

<details>
<summary>update_power_leds_status</summary>

Configura os leds de indicação da alimentação das saídas digitais. As saídas digitais Q01 ... Q08 possuem alimentação dedicada, com led indicador V01. E as saídas digitais Q09 ... Q016 possuem alimentação dedicada, com led indicador V02.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
digital_output.update_power_leds_status();
leds.update();
```
</details>
  
