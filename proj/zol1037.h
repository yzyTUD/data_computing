
#include <stdio.h>
#include <math.h>
#include "common.h"

int zol1037()
{
    int n ,a, b,c =1;
        scanf("%d" ,&n);
    while (n--){
        scanf("%d %d" , & a, &b);
        printf("Scenario #%d:\n" ,c);
        if ( a % 2 == 0 || b % 2 == 0 )
            printf("%.2f\n\n" ,a*b);
        else
            printf("%.2f\n\n" , a*b-1+ sqrt(2.0 ));
        c++;
    }
    return 0 ;
}

