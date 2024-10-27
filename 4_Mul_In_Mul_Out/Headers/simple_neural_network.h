#ifndef __SIMPLE_NEURAL_NETWORKS_H

#define __SIMPLE_NEURAL_NETWORKS_H


double single_in_single_out(double input, double weight);
double multiple_input_single_output(double *input, double *weight, int LEN);
void single_in_multiple_out(double input_scalar, double *weight_vector, double *output_vector, int LEN);
void multiple_input_multiple_output(double *input_vector,
                                    int INPUT_LEN,
                                    double *output_vector,
                                    int OUTPUT_LEN,
                                    double weight_matrix[OUTPUT_LEN][INPUT_LEN]);

#endif
