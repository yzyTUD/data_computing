
#include <stdio.h>

int main(){
    //get in the info
    int n,m,val,k;
    scanf("%d%d",&n,&m);
    int M[n][m],N[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf("%d",&val);
            M[i][j]=val;
            N[i][j]=val;
        }


    //from left to right
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j>(m-2))//if there are less than three token left
                continue;
            k=2;
            if(M[i][j]==M[i][j+1]){//if this one and the next one equals
                while(M[i][j]==M[i][j+k]&&j+k<m){//dont go to far
                    k++;
                }
                if(k>2){
                    for(int l =0;l<k;l++){//use l to count the numbers
                        M[i][j+l]=0;
                    }
                }
            }
        }
    }


    //from top to bottom
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j>(n-2))
                continue;
            k=2;
            if(N[j][i]==N[j+1][i]){
                while(N[j][i]==N[j+k][i]&&j+k<n){
                    k++;
                }
                if(k>2){
                    for(int l =0;l<k;l++){
                        N[j+l][i]=0;
                    }
                }
            }
        }
    }



    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(N[i][j]==0)
                M[i][j]=0;//M  or  N    取交集
            printf("%d ",M[i][j]);
        }

        printf("\n");
    }

    return 0;
}

