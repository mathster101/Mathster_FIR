#include "mathster_fir.h"

FIR_filter::FIR_filter(float* filter_coefficients, const int filter_size)
{
	this->filter_coefficients = (float*)malloc(filter_size * sizeof(float));
    for (int i = 0; i < filter_size; i++)
    {
        this->filter_coefficients[i] = filter_coefficients[i];
        circular_buffer[i] = 0;
    }
    this->FILTER_SIZE = filter_size;
}

float FIR_filter::filter_value(float new_sample)
{
    float output = 0;
    circular_buffer[oldest_sample] = new_sample;
    for (int coeff_index = 0, sample_index = oldest_sample; coeff_index < FILTER_SIZE; coeff_index++)
    {
        output += filter_coefficients[coeff_index] * circular_buffer[sample_index];
        (sample_index == 0) ? sample_index = FILTER_SIZE - 1 : sample_index--;

    }

    (oldest_sample + 1) == FILTER_SIZE ? oldest_sample = 0 : oldest_sample++;
    return output;
}
