
#include <stdio.h>
#include <math.h>

#define EPS 0.001

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

void root(double p,double q){
    double d,f;
    double r1,r2,i1,i2;

    d = p * p -4.0*q;
    if(d<=0){
        f = sqrt(-d);
        r1 = -p/2.0;
        r2 = -p/2.0;
        i1 = f/2.0;
        i2 = -f/2.0;
    }
    else{
        f = sqrt(d);
        r1 = (-p + f)/2.0;
        r2 = (-p - f)/2.0;
        i1 = 0.0;
        i2 = 0.0;
    }
    printf("%8.5lf\t%8.5lf\n%8.5lf\t%8.5lf\n",r1,i1,r2,i2);
}

void bairstow(double *p,double *q,double a[],int n){
    double b[n+1],c[n+1];
    double dp,dq,e;
    int k,i;

    *p = 1.0;
    *q = 1.0;

    do{
        b[0] = a[0];
        b[1] = a[1] - *p * b[0];

        for(k=2;k<=n;k++){
            b[k] = a[k] - *p * b[k-1] - *q * b[k-2];
        }
        c[0] = b[0];
        c[1] = b[1] - *p * c[0];
        for(k=2;k<=n;k++){
            c[k] = b[k]-*p*b[k-1] - *q*b[k-2];
        }
        e = c[n-2] * c[n-2] - b[n-3] * (c[n-1] - b[n-1]);

        dp = (b[n-1] * c[n-2] - b[n] * c[n-3]) / e;
        dq = (b[n] * c[n-2] - b[n-1] * (c[n-1] - b[n-1])) / e;
        *p += dp;
        *q += dq;
    }while((fabs(dp) > EPS) && (fabs(dq) > EPS));

    for(i=0;i<=n-2;i++){
        a[i] = b[i];
    }
}

double bairstow_main(int n,double a[]){
    int jisuu=n;
    double p,q;
    printf("Re\t\tIm\n");
    while (1){
        if(jisuu == 1){
            printf("%.5lf\t\t%.5lf\n",-a[1]/a[0],0.0);
            return 0;
        }
        if(jisuu==2){
            root(a[1],a[2]);
            return 0;
        }
        if(jisuu==0) return 0;

        bairstow(&p,&q,a,jisuu);
        root(p,q);
        jisuu-=2;

    }
    
}