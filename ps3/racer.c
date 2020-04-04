#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main (){
    double n = 0;
    double t = 0;
    double s = 0;
    double v = 0;
    double medzi = 0;
    double k = 0;
    scanf("%lf",&n);
    scanf("%lf",&t);
    for (int c = 0; c <= n - 1; c++){
        scanf("%lf",&s);
        scanf("%lf",&v);
        medzi = s / (t / (n));
        k = k + (medzi - v) / n;
    }
    printf("%.10f\n",k);
}