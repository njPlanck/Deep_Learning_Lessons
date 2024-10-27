#include <stdio.h>
#include <stdlib.h>
//#include "..\Headers\simple_neural_network.h"
#include "simple_neural_network.c"

#define NUM_OF_INPUTS 3
double temperature[] ={12,23,50,-10,16};
double humidity[] ={60,67,50,65,63};
double air_quality[] ={60,47,167,187,94};

double weight[] = {-2,2,1};

int main(){

  double training_eg1[] = {temperature[0],humidity[0],air_quality[0]};

  printf("Prediction from the first training example is: %f\n",multiple_input_single_output(training_eg1,weight,NUM_OF_INPUTS));

  return 0;
}