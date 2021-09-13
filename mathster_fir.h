class FIR_filter
{
    public:
        FIR_filter(float* filter_coefficients, int filter_size);
        float filter_value(float new_sample);

    private:
        float filter_coefficients[100];
        float circular_buffer[100];
        int FILTER_SIZE;
        int oldest_sample = 0;
};