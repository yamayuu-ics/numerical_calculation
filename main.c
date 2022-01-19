#include <stdio.h>

#include "chap01.h"

int main(){
    double ans;

    //ans = nibun(0.0,1.0);
    ans = newton(1.0);
    printf("ans = %.9lf\n",ans);

    return 0;
}