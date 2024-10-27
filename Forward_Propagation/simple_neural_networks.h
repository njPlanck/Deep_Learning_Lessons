#ifndef __SIMPLE_NEURAL_NETWORKS_H

#define __SIMPLE_NEURAL_NETWORKS_H

#define HID_LEN 3


double hidden_pred_vector[HID_LEN];

double single_in_single_out(double input, double weight);
double multiple_input_single_output(double *input, double *weight, int LEN);
void single_in_multiple_out(double input_scalar, double *weight_vector, double *output_vector, int LEN);
void multiple_input_multiple_output(double *input_vector,
                                    int INPUT_LEN,
                                    double *output_vector,
                                    int OUTPUT_LEN,
                                    double weight_matrix[OUTPUT_LEN][INPUT_LEN]);


void hidden_layer(double *input_vector,
                  int INPUT_LEN,
                  int HIDDEN_LEN,
                  double in_to_hid_weights[HIDDEN_LEN][INPUT_LEN],
                  int OUTPUT_LEN,
                  double hid_to_out_weights[OUTPUT_LEN][HIDDEN_LEN],
                  double *output_vector);


double find_error(double input, double weight, double expected_value);
double find_error_simple(double yhat, double y);

void brute_force_learning(double input,
                          double weight,
                          double expected_values,
                          double step_amount,
                          int itr);



void normalize_data(double *input_vector, double *output_vector, int LEN);
void weight_random_initialisation(int HIDDEN_LEN,
                                  int INPUT_LEN,
                                  double weights_matrix[HIDDEN_LEN][INPUT_LEN]);


void normalize_data_2d(int ROW, int COL, double input_matrix[ROW][COL],double output_matrix[ROW][COL]);
void weight_random_initialisation_1d(double *output_vector,int LEN);


void vector_sigmoid(double *input_vector,double *output_vector, int LEN);
double sigmoid(double x);
#endif
