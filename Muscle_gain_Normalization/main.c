#include <stdio.h>
#include <stdlib.h>

#include  "simple_neural_networks.h"

#define NUM_OF_FEATURES 2
#define NUM_OF_SAMPLES 3


double x1[NUM_OF_SAMPLES] = {2,5,1};
double _x1[NUM_OF_SAMPLES];
double x2[NUM_OF_SAMPLES] = {8,5,8};
double _x2[NUM_OF_SAMPLES];


double y[NUM_OF_SAMPLES] = {200,90,109};
double _y[NUM_OF_SAMPLES];

int main(){

  normalize_data(x1,_x1,NUM_OF_SAMPLES);
  normalize_data(x2,_x2,NUM_OF_SAMPLES);
  normalize_data(y,_y,NUM_OF_SAMPLES);


  printf("Raw x1 data: \n\r");
  for(int i=0;i<NUM_OF_SAMPLES;i++){
    printf(" %f ",x1[i]);
  }
  printf(" \n ");

  printf("Normalised x1 data: \n\r");
  for(int i=0;i<NUM_OF_SAMPLES;i++){
    printf(" %f ",_x1[i]);
  }
  printf(" \n ");

  printf("Raw x2 data: \n\r");
  for(int i=0;i<NUM_OF_SAMPLES;i++){
    printf(" %f ",x2[i]);
  }
  printf(" \n ");

  printf("Normalised x2 data: \n\r");
  for(int i=0;i<NUM_OF_SAMPLES;i++){
    printf(" %f ",_x2[i]);
  }
  printf(" \n ");


  printf("Raw y data: \n\r");
  for(int i=0;i<NUM_OF_SAMPLES;i++){
    printf(" %f ",y[i]);
  }
  printf(" \n ");

  printf("Normalised x1 data: \n\r");
  for(int i=0;i<NUM_OF_SAMPLES;i++){
    printf(" %f ",_y[i]);
  }
  printf(" \n ");


  return 0;
}
