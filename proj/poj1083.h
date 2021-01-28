
#include<stdio.h>
#include<string.h>
int main(){
    int n, tables, corridor[200], i, j, start, end, time, x, y;
    scanf("%d", &n);
    while (n-->0){
        memset(corridor, 0, sizeof(corridor));
        time = 0;
        scanf("%d", &tables);
        for (i = 0; i<tables; i++){
            scanf("%d%d", &x, &y);
            start = ((x<y ? x : y) - 1) / 2;
            end = ((x>y ? x : y) - 1) / 2;
            for (j = start; j <= end; j++)
                corridor[j] += 10;
        }
        for (i = 0; i<200; i++)
            time = corridor[i]>time ? corridor[i] : time;
        printf("%d\n", time);
    }
    getchar();
    return 0;
}

