#include  "simple_neural_networks.h"
#include <math.h>
#include <stdio.h>

double single_in_single_out(double input, double weight){
  return (input * weight);
}



double weighted_sum(double *input, double *weight, int LEN){
  double output;

  for(int i=0;i<LEN;i++){
    output += input[i]*weight[i];
  }

  return output;
}

double multiple_input_single_output(double *input, double *weight, int LEN){
  double predicted_value;
  predicted_value = weighted_sum(input,weight,LEN);

  return predicted_value;
}


void elementwise_multiply(double input_scalar, double *weight_vector, double *output_vector,int LEN){
  for(int i=0;i<LEN;i++){
    output_vector[i] = input_scalar * weight_vector[i];
  }
}


void single_in_multiple_out(double input_scalar, double *weight_vector, double *output_vector, int LEN){
  elementwise_multiply(input_scalar,weight_vector,output_vector,LEN);
}



void matrix_vector_multiply(double *input_vector,
                            int INPUT_LEN,
                            double *output_vector,
                            int OUTPUT_LEN,
                            double weight_matrix[OUTPUT_LEN][INPUT_LEN]){

  for(int k=0;k<OUTPUT_LEN;k++){
    for(int i=0;i<INPUT_LEN;i++){
      output_vector[k] += input_vector[i] * weight_matrix[k][i];
    }
  }

}



void multiple_input_multiple_output(double *input_vector,
                                    int INPUT_LEN,
                                    double *output_vector,
                                    int OUTPUT_LEN,
                                    double weight_matrix[OUTPUT_LEN][INPUT_LEN]){

  matrix_vector_multiply(input_vector,INPUT_LEN,output_vector,OUTPUT_LEN,weight_matrix);

}


void hidden_layer(double *input_vector,
                  int INPUT_LEN,
                  int HIDDEN_LEN,
                  double in_to_hid_weights[HIDDEN_LEN][INPUT_LEN],
                  int OUTPUT_LEN,
                  double hid_to_out_weights[OUTPUT_LEN][HIDDEN_LEN],
                  double *output_vector){


  matrix_vector_multiply(input_vector,INPUT_LEN,hidden_pred_vector,HIDDEN_LEN,in_to_hid_weights);
  matrix_vector_multiply(hidden_pred_vector,HIDDEN_LEN,output_vector,OUTPUT_LEN,hid_to_out_weights);

}



double find_error(double input, double weight, double expected_value){
  return powf(((input * weight)- expected_value),2);
}


double find_error_simple(double yhat, double y){

  return powf((yhat - y),2);
}

void brute_force_learning(double input,
                          double weight,
                          double expected_values,
                          double step_amount,
                          int itr)
{
    double prediction,error;
    double up_prediction,up_error,down_prediction,down_error;

    for(int i = 0;i<itr;i++){
        prediction =input*weight;
        error = powf((prediction-expected_values),2);

        printf("Error: %f Prediction: %f \r\n", error, prediction);

        up_prediction = input * (weight+step_amount);
        up_error = powf((expected_values-up_prediction),2);

        down_prediction = input * (weight-step_amount);
        down_error = powf((expected_values-down_prediction),2);

        if (down_error < up_error){
            weight = weight-step_amount;
        }
        if (down_error>up_error){
            weight = weight + step_amount;
        }
    }
}


void normalize_data(double *input_vector, double *output_vector, int LEN){
    int i;
    //find max

    double max = input_vector[0];

    for (i=1;i<LEN;i++){
        if(input_vector[i]> max){
            max = input_vector[i];
        }
    }
    //normalize

    for (i=0;i<LEN;i++){
        output_vector[i] = input_vector[i]/max;
    }

}
