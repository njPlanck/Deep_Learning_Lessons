#include <stdio.h>
#include <stdlib.h>
//#include "..\Headers\simple_neural_network.h"
#include "simple_neural_network.c"

#define sad 0.9
#define TEMPERATURE_PREDICTION_INDEX 0
#define HUMIDITY_PREDICTION_INDEX 1
#define AIR_QUALITY_PREDICTON_INDEX 2

#define VECTOR_LEN 3
double predicted_results[3];
double weights[3] = {-20,95,201};

int main(){

  single_in_multiple_out(sad,weights,predicted_results,VECTOR_LEN);

  printf("Predicted temperature is: %f \n", predicted_results[TEMPERATURE_PREDICTION_INDEX]);
  printf("Predicted humidity is: %f \n", predicted_results[HUMIDITY_PREDICTION_INDEX]);
  printf("Predicted air_quality is: %f \n", predicted_results[AIR_QUALITY_PREDICTON_INDEX]);

  return 0;
}