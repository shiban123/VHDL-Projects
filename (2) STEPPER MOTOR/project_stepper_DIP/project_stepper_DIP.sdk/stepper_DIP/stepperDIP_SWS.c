/*
 * stepperDIP_SWS.c
 *
 *  Created on: May 7, 2017
 *      Author: Kunal Shahu
 */
#include <xparameters.h>
#include "xstatus.h"
#include "xgpio.h"

#define STEPPER_ID 		XPAR_GPIO_0_DEVICE_ID
#define PUSHBUTTONS_ID  XPAR_GPIO_1_DEVICE_ID
#define SWS_ID XPAR_GPIO_2_DEVICE_ID

#define STEPPER_CHANNEL 	1
#define PUSHBUTTONS_CHANNEL 1
#define SWS_CHANNEL 1
#define SPEED 100000

int push_button_value;
sws_value;
XGpio Gpio;
XGpio Gpio1;
XGpio Gpio2;

void delay(void);
int Initialize_GPIO(void);

void main() {

	Initialize_GPIO();

	while (1) {

		push_button_value = XGpio_DiscreteRead(&Gpio1, PUSHBUTTONS_CHANNEL);
		sws_value = XGpio_DiscreteRead(&Gpio2, SWS_CHANNEL);
		int i;

		if (push_button_value == 2 || sws_value == 0x02) {

			for (i = 0; i < 50; i++) {
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 12);
				delay();
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 9);
				delay();
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 3);
				delay();
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 6);
				delay();
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 12);

			}

		} else if (push_button_value == 4 || sws_value == 0x04) {

			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 12);
			delay();
			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 9);
			delay();
			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 3);
			delay();
			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 6);
			delay();
			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 12);

		} else if (push_button_value == 8 || sws_value == 0x08) {

			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 12);
			delay();
			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 6);
			delay();
			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 3);
			delay();
			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 9);
			delay();
			XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 12);

		} else if (push_button_value == 16 || sws_value == 0x16) {

			for (i = 0; i < 50; i++) {
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 12);
				delay();
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 6);
				delay();
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 3);
				delay();
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 9);
				delay();
				XGpio_DiscreteWrite(&Gpio, STEPPER_CHANNEL, 12);

			}

		}

	}
}

delay() {
	int i;
	int x;
	for (i = 0; i < SPEED; i++) {
		x = x + 0;

	}
}

int Initialize_GPIO() {

	int Status;
	Status = XGpio_Initialize(&Gpio, STEPPER_ID);
	if (Status != XST_SUCCESS)
		return XST_FAILURE;
	Status = XGpio_Initialize(&Gpio1, PUSHBUTTONS_ID);
	if (Status != XST_SUCCESS)
		return XST_FAILURE;
	Status = XGpio_Initialize(&Gpio2, SWS_ID);
	if (Status != XST_SUCCESS)
		return XST_FAILURE;
	XGpio_SetDataDirection(&Gpio, STEPPER_CHANNEL, 0x00);
	XGpio_SetDataDirection(&Gpio1, PUSHBUTTONS_CHANNEL, 0x1f);
	XGpio_SetDataDirection(&Gpio2, SWS_CHANNEL, 0xFF);

	return Status;
}

