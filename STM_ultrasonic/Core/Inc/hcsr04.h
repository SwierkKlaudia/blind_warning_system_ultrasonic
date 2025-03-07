/*
  ******************************************************************************
  * @file           : hcsr04.h
  * @brief          : Header for hcsr04.c file
  ******************************************************************************
 */

#ifndef INC_HCSR04_H_
#define INC_HCSR04_H_

#include <stdbool.h>
#include <stdint.h>

#define DEBOUNCE_CYCLES 		UINT16_MAX

#define SOUND_SPEED 			34.38  /* [cm/ms] */

#define NUMBER_OF_SAMPLES 		5U

#define HCSR04_PWM_CHANNEL		TIM_CHANNEL_3
#define HCSR04_START_CHANNEL 	TIM_CHANNEL_1
#define HCSR04_STOP_CHANNEL 	TIM_CHANNEL_2

typedef float dist;

typedef struct Measurement
{
	bool invalid_msg;
	uint16_t debounce_counter;
	volatile dist distance;
}Meas_distance_T;

dist Average_Distance(const dist distance);

void Reset_Counter(Meas_distance_T *struct_counter);


#endif /* INC_HCSR04_H_ */
