#include <stdio.h>

#include "chap01.h"
#include "chap02.h"

int main(){

    double a[3][3+1] = {
        {2,1,3,13},
        {1,3,2,13},
        {3,2,1,10}
    };
    //double ans;
    //int n = 4;
    //double a[] = {1,-2,2,-50,62};
    //ans = nibun(0.0,1.0);
    //ans = newton(1.0);
    //printf("ans = %.9lf\n",ans);
    //bairstow_main(n,a);


    // 02
    gj(3,a);
    return 0;
}