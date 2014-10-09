#include <stdint.h>
#include "bsp/bsp.h"

/**
 * @brief Delay por software
 *
 * @param nCount Numero de ciclos del delay
 */
void Delay(volatile uint32_t nCount);

/**
 * @brief Se encarga de prender un led y apagarlo luego de un tiempo
 *
 * @param led    Numero de led a pulsar
 * @param tiempo Numero de ciclos del delay entre prendido y apagado
 */
void pulsoLed(uint8_t led, uint32_t tiempo);
void vumetro(uint16_t led);

/**
 * @brief Aplicacion principal
 */
int main(void) {
	bsp_init();
	uint16_t potenciometro;
	int flag = 0;
	while (1) {

		potenciometro=leer_pote();
		vumetro(potenciometro);



	}
}
void vumetro(uint16_t led){
	uint8_t i;

for(i=3;i<(led+4);i++){
	led_on(i);
}
for(i=(led+4);i<12;i++){
	led_off(i);

}



}


void pulsoLed(uint8_t led, uint32_t tiempo){
	led_on(led);
	Delay(tiempo);
	led_off(led);
}

void Delay(volatile uint32_t nCount) {
	while (nCount--) {
	}
}


void APP_ISR_sw(void){

}

void APP_ISR_1ms(void){
	static uint16_t count_1s = 1000;
	count_1s--;
	if (!count_1s) {
		led_toggle(0);

	}
}
