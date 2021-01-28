#include <stdio.h>
#include <string.h>
#define N 10

char a[N][N];
int S;

void sort(){
    char q[N];
    for(int i=0;i<S-1;i++)
        for(int j=i+1;j<S;j++){
            if(strcmp(a[i],a[j])>0){
                strcpy(q,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],q);
            }
        }
}

int main(){
        FILE  *p ;
         if((p=fopen("data.txt" ,"r"))==NULL){
               perror( "Error\n");
        }

        FILE  *pout ;
         if((pout=fopen("dataout.txt" ,"w"))==NULL){
               perror( "error opening output file\n" );
        }
        

         char ch[N];int i=0;
         while(!feof(p)){
               fscanf(p, "%s",&ch);
               strcpy(a[i],ch);
               i++;
        }S=i;


        sort();


         for(int i=0;i<S;i++)
               puts(a[i]);

         for(int i=0;i<S;i++)
               fprintf(pout, "%s\n",a[i]);



        fclose(p);
}
