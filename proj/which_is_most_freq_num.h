
#include <stdio.h>
#include <string.h>
#define M 10000
int main(){

    int n,val,ans=0,num=0;
    scanf("%d",&n);
    int f[M];

    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        f[val]++;
    }

    for(int i=0;i<M;i++)
    {
        if(f[i]>num)
        {
            num=f[i];
            ans= i;
        }
    }

    printf("%d\n",ans);
    return 0;
}

