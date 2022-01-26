#include <stdio.h>

#include "chap01.h"

int main(){
    //double ans;
    int n = 4;
    double a[] = {1,-2,2,-50,62};
    //ans = nibun(0.0,1.0);
    //ans = newton(1.0);
    //printf("ans = %.9lf\n",ans);


    bairstow_main(n,a);

    return 0;
}