
#include <stdio.h>
#include <string.h>
#define M 20
int main(){

    int n;
    scanf("%d",&n);
    int a[n][n];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)//set the ones
    {
        a[i][0]=1;
        a[i][i]=1;
    }

    for(int i=2;i<n;i++)//start from the (2,1)  to  (i,i) end with (n-1,i)
        for(int j=1;j<i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }

    for(int i=0;i<n;i++){//start from (0,0) -> (i,i)
        for(int j=0;j<=i;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }



    return 0;
}

