#include <stdio.h>
#include <math.h>
#include "chap02.h"

#define EPS 0.001
#define MAX_LOOP 30

int gj(int N,double a[][_N+1]){
    double pivot,del;
    int i,j,k,l;

    for(i=0;i<N;i++){
        pivot = a[i][i];
        if(fabs(pivot) < EPS){
            printf("Err\n");
            return 1;
        }
        for(j=i;j<N+1;j++){
            a[i][j] = a[i][j] / pivot;
        }
        for(k=0;k<N;k++){
            del = a[k][i];
            for(j=i;j<N+1;j++){
                if(k != i){
                    a[k][j] -= del*a[i][j];
                }
            }
        }
    }
    for(l=0;l<N;l++){
        printf("x%d = %6.2lf\n",l,a[l][N]);
    }

    return 0;
}

int gz(int N,double a[][_N+1]){
    double x[_N],y[_N],s,q;
    int i,j,k;

    for(i=0;i<_N;i++){
        x[i] = 1.0;
    }
    for(k=0;k<MAX_LOOP;k++){
        q = 0.0;
        for(i=0;i<_N;i++){
            s = 0.0;
            for(j=0;j<_N;j++){
                if(i!=j){
                    s += a[i][j] * x[j];
                }
            }
            y[i] = (a[i][_N] - s) / a[i][i];
            q += fabs(x[i] - y[i]);
            x[i] = y[i];
        }
        if(q < EPS){
            for(i=0;i<_N;i++){
                printf("x%d = %9.6lf\n",i,x[i]);
            }
            return 0;
        }
    }
    printf("収束せず\n");
    return 1;

}