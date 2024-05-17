## Digital Output
Esta biblioteca tem como objetivo permitir o usuário a manipular as saídas digitais da Industrialli Hub.

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
