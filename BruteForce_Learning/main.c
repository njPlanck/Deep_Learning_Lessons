#include <stdio.h>
#include <stdlib.h>

#include  "simple_neural_networks.h"


#define SAD_PREDICTION_INDEX     0
#define SICK_PREDICTION_INDEX    1
#define ACTIVE_PREDICTION_INDEX  2


#define IN_LEN   3
#define HID_LEN    3
#define OUT_LEN    3

double predicted_results[3];

double input_to_hidden_weights[HID_LEN][IN_LEN] = {{-2,9.5,2.01},
                                                   {-0.6,7.2,6.3},
                                                   {-0.5,0.45,0.9}};

double hidden_to_output_weights[OUT_LEN][HID_LEN]= {{-1.0,1.15,0.11},
                                                    {-0.18,0.15,-0.01},
                                                    {0.25,-0.25,-0.1}};

double inputs[IN_LEN] = {30,87,110};
double expected_values[OUT_LEN] = {600,10,-90};

int main(){

  hidden_layer(inputs,IN_LEN,HID_LEN,input_to_hidden_weights,OUT_LEN,hidden_to_output_weights,predicted_results);

  printf("Sad prediction: %f\n",predicted_results[SAD_PREDICTION_INDEX]);
  printf("Sad error: %f\n",find_error_simple(predicted_results[SAD_PREDICTION_INDEX],expected_values[SAD_PREDICTION_INDEX]));

  printf("Sick prediction %f\r\n",predicted_results[SICK_PREDICTION_INDEX]);
  printf("Sick error %f\r\n",find_error_simple(predicted_results[SICK_PREDICTION_INDEX],expected_values[SICK_PREDICTION_INDEX]));

  printf("Active prediction %f\r\n",predicted_results[ACTIVE_PREDICTION_INDEX]);
  printf("Active error %f\r\n",find_error_simple(predicted_results[ACTIVE_PREDICTION_INDEX],expected_values[ACTIVE_PREDICTION_INDEX]));

  return 0;
}
