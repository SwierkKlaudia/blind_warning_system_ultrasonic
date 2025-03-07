/*
  ******************************************************************************
  * @file           : GP2Y0A02YK0F.c
  * @brief          : This file provides code for GP2Y0A02YK0F module
  ******************************************************************************
 */

#include "GP2Y0A02YK0F.h"
#include <math.h>
#include <string.h>


static uint8_t sample_counter = 0;
static uint32_t avg_distance = 0;

static uint32_t buffor[NUMBER_OF_SAMPLES] = {0};


static uint32_t Average(uint32_t *tab, int N)
{
	uint32_t avg = 0;

    for (int i = 0; i < N; i++)
    {
        avg += tab[i];
    }

    return (avg/(uint32_t)N);
}


uint32_t Average_Distance(const uint32_t distance)
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

