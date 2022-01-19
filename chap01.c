
#include <stdio.h>
#include <math.h>

#define EPS 0.0001

double func(double x){
    return pow(x,3.0) + x - 1;
}

double func_d(double x){
    return 3*pow(x,2.0) + 1.0;
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


double newton(double a){
    double b;

    while (1){
        b = a - (func(a) / func_d(a));
        if(fabs(b-a) < EPS){
            break;
        }else{
            a = b;
        }
    }
    return b;
}