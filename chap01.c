
#include <stdio.h>
#include <math.h>

int test(int a){
    int ret;
    printf("a\n");

    //ret = test(1);

    return 0;
}

#define EPS 0.0001

double func(double x){
    return pow(x,3.0) + x - 1;
}

double nibun(double a,double b){
    double c;

    do{
        c = (a+b) / 2.0;
        if((func(c) * func(a)) < 0){
            b = c;
        }
        else{
            a = c;
        }
    }while (fabs(a-b) > EPS);

    return c;    
}