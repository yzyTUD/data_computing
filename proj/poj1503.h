
#include <stdio.h>
#include <string.h>
#define M 105

//declear arrays
char sum[M][M];
char str[M];
int poj1503(){
    int i,jin,he;
    //read from user input  -- 'gets()'
    //store numbers into  'sum'
    for( i = 0;; i++){
        //gets(str);
        if(str[0]=='0'&&str[1]==0)break;

        sum[i][0]=strlen(str);

        for(int j=1;j<=strlen(str);j++)
        {
            sum[i][j]=str[strlen(str)-j]-'0';
        }
    }

    //making addtion

    //int lines = i;
    for(int i=1;i<M;i++){
        jin=0,he=0;
        for(int j=1;j<M;j++){
           he= sum[0][j]+sum[i][j]+jin;
            sum[0][j] =he%10;
            jin = he/10;
        }
    }

    //printout
    for(i=M-1;sum[0][i]==0;i--){}

        for(;i>0;i--){
            printf("%d",sum[0][i]);

        }
    putchar('\n');

    return 0;
}

