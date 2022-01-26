#include <stdio.h>
#include <math.h>

#define EPS 0.001

int gj(int N,double a[][4]){
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