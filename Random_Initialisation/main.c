#include <stdio.h>
#include <stdlib.h>

#include  "simple_neural_networks.h"

#define NUM_OF_FEATURES 2
#define NUM_OF_SAMPLES 3
#define NUM_OF_HID_NODES 3
#define NUM_OF_OUT_NODES 1

double x1[NUM_OF_SAMPLES] = {2,5,1};
double _x1[NUM_OF_SAMPLES];
double x2[NUM_OF_SAMPLES] = {8,5,8};
double _x2[NUM_OF_SAMPLES];


double y[NUM_OF_SAMPLES] = {200,90,109};
double _y[NUM_OF_SAMPLES];

double syn0[NUM_OF_HID_NODES][NUM_OF_FEATURES];

double syn1[NUM_OF_OUT_NODES][NUM_OF_HID_NODES];

int main(){

  weight_random_initialisation(NUM_OF_HID_NODES,NUM_OF_FEATURES,syn0);
  weight_random_initialisation(NUM_OF_OUT_NODES,NUM_OF_HID_NODES,syn1);

   printf("synapse 0 weights \n");
  for (int i=0;i<NUM_OF_HID_NODES;i++){
    for(int j=0;j<NUM_OF_FEATURES;j++){
        printf(" %f ",syn0[i][j]);
    }
    printf("\n\r");
    printf("\n\r");
  }
    printf("synapse 1 weights \n");
   for (int i=0;i<NUM_OF_OUT_NODES;i++){
    for(int j=0;j<NUM_OF_HID_NODES;j++){
        printf(" %f ",syn1[i][j]);
    }
    printf("\n\r");
    printf("\n\r");
  }
  return 0;
}
