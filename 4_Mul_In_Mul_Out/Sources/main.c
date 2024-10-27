#include <stdio.h>
#include <stdlib.h>
//#include "..\Headers\simple_neural_network.h"
#include "simple_neural_network.c"

#define sad 0.9
#define SAD_PREDICTION_INDEX 0
#define SICK_PREDICTION_INDEX 1
#define ACTIVE_PREDICTION_INDEX 2

#define IN_LEN 3
#define OUT_LEN 3
double predicted_results[3];

double weights[OUT_LEN][OUT_LEN] = {{-2,9.5,2.01},
                                    {-0.6,7.2,6.3},
                                    {-0.5,0.45,0.9}};

double inputs[IN_LEN] = {30,87,110};

int main(){

  multiple_input_multiple_output(inputs,IN_LEN,predicted_results,OUT_LEN,weights);

  printf("Sad prediction %f\n",predicted_results[SAD_PREDICTION_INDEX]);
  printf("Sick prediction %f\n",predicted_results[SICK_PREDICTION_INDEX]);
  printf("Active prediction %f\n",predicted_results[ACTIVE_PREDICTION_INDEX]);

  return 0;
}