#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>



int main (){

    double a = 0;

    double b = 0;

    scanf("%lf",&a);

    scanf("%lf",&b);



    if (a == 0){

        for (int c = 0; c < b; c++){

        printf("%.7f\n", 100 / b);

        }

        return 0;

    }

    if (b == 0){

        printf("100.0000000\n");

        return 0;

    }



    for (int c = 0; c < b; c++){

        printf("%.7f\n", 100 / b);       

    }

    return 0;

}