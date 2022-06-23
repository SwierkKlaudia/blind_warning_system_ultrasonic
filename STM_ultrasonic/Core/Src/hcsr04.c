/*
  ******************************************************************************
  * @file           : hcsr04.c
  * @brief          : This file provides code for HC-SR04 module
  ******************************************************************************
 */

#include "hcsr04.h"
#include <math.h>
#include <string.h>


#define NUMBER_OF_SAMPLES 10U

static uint8_t sample_counter = 0;
static dist avg_distance = 0;

static dist buffor[NUMBER_OF_SAMPLES] = {0};


static dist Average(dist *tab, int N)
{
    dist avg = 0;

    for (int i = 0; i < N; i++)
    {
        avg += tab[i];
    }

    return (avg/(dist)N);
}


dist Average_Distance(const dist distance)
{
	if (sample_counter < NUMBER_OF_SAMPLES)
	{
		buffor[sample_counter] = distance;
		sample_counter++;
	}
	else
	{
		avg_distance = Average(buffor, NUMBER_OF_SAMPLES);
		sample_counter = 0;
	}
	return avg_distance;
}


void Reset_Counter(Meas_distance_T *struct_counter)
{
	struct_counter->debounce_counter = 0;
	struct_counter->invalid_msg = false;
}
