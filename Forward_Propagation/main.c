#include <stdio.h>
#include <stdlib.h>

#include  "simple_neural_networks.h"

#define NUM_OF_FEATURES 2
#define NUM_OF_SAMPLES 3
#define NUM_OF_HID_NODES 3
#define NUM_OF_OUT_NODES 1


double raw_x[NUM_OF_FEATURES][NUM_OF_SAMPLES]={{2,5,1},
                                               {8,5,8}};

double raw_y[1][NUM_OF_SAMPLES]={{200,90,190}};


//Train x

double train_x[NUM_OF_FEATURES][NUM_OF_SAMPLES];
double train_y[1][NUM_OF_SAMPLES];


double syn0[NUM_OF_HID_NODES][NUM_OF_FEATURES];

double syn1[NUM_OF_HID_NODES];


double train_x_eg1[NUM_OF_FEATURES];
double train_y_eg1;
double z1_eg1[NUM_OF_HID_NODES];
double a1_eg1[NUM_OF_HID_NODES];
double z2_eg1;
double yhat_eg1;


int main(){

  normalize_data_2d(NUM_OF_FEATURES,NUM_OF_SAMPLES,raw_x,train_x);
  normalize_data_2d(1,NUM_OF_SAMPLES,raw_y,train_y);

  train_x_eg1[0] = train_x[0][0];
  train_x_eg1[1] = train_x[1][0];

  train_y_eg1 = train_y[0][0];

  printf("train_x_eg1 is [%f %f]",train_x_eg1[0],train_x_eg1[1]);
  printf("\n\r");
  printf("\n\r");

  printf("train_y_eg1 is %f",train_y_eg1);
  printf("\n\r");
  printf("\n\r");

  weight_random_initialisation(NUM_OF_HID_NODES,NUM_OF_FEATURES,syn0);

   printf("synapse 0 weights \n");
  for (int i=0;i<NUM_OF_HID_NODES;i++){
    for(int j=0;j<NUM_OF_FEATURES;j++){
        printf(" %f ",syn0[i][j]);
    }
    printf("\n\r");
    printf("\n\r");
  }

  weight_random_initialisation_1d(syn1,NUM_OF_OUT_NODES);
  printf("\n\r");
  printf("\n\r");
  for(int i=0;i<NUM_OF_OUT_NODES;i++){
    printf("synapse 1 [%f  %f  %f]", syn1[0],syn1[1],syn1[2]);

  }
  printf("\n\r");
  printf("\n\r");

  multiple_input_multiple_output(train_x_eg1,NUM_OF_FEATURES,z1_eg1,NUM_OF_HID_NODES,syn0);
  printf("\n\r");
  printf("\n\r");

  printf("z_eg1 = [%f  %f  %f]",z1_eg1[0],z1_eg1[1],z1_eg1[2]);
  printf("\n\r");
  printf("\n\r");

  vector_sigmoid(z1_eg1,a1_eg1,NUM_OF_HID_NODES);

  printf("a1_eg1 = [%f  %f  %f]",a1_eg1[0],a1_eg1[1],a1_eg1[2]);
  printf("\n\r");
  printf("\n\r");

  z2_eg1 = multiple_input_single_output(a1_eg1,syn1,NUM_OF_HID_NODES);
  printf("\n\r");
  printf("\n\r");

  printf("z2_eg1: %f",z2_eg1);

  printf("\n\r");
  printf("\n\r");

  yhat_eg1 = sigmoid(z2_eg1);

  printf("\n\r");
  printf("\n\r");

  printf("yhat_eg1 : %f",yhat_eg1);

  printf("\n\r");
  printf("\n\r");
//    printf("synapse 1 weights \n");
//   for (int i=0;i<NUM_OF_OUT_NODES;i++){
//    for(int j=0;j<NUM_OF_HID_NODES;j++){
//        printf(" %f ",syn1[i][j]);
//    }
//    printf("\n\r");
//    printf("\n\r");
//  }
  return 0;
}
