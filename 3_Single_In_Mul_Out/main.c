#include <stdio.h>
#include <stdlib.h>
#include  "simple_neural_networks.h"


double temperature[]={12,23,50,-4,-7,18};
double weight  = -2;

int main()
{
    printf("The first predicted value is %f: \r\n",single_in_single_out(temperature[0],weight));
    printf("The second predicted value is %f: \r\n",single_in_single_out(temperature[1],weight));
    printf("The third predicted value is %f: \r\n",single_in_single_out(temperature[2],weight));
    return 0;
}
