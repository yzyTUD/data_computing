



#include<stdio.h>

//--------------------------预定义与全局变量------------------------------------
#define MAX_VETEX_SIZE 20                              //程序能接受的最大顶点数目

int REAL_SIZE;                                         //程序中实际的顶点数目
int m[MAX_VETEX_SIZE][MAX_VETEX_SIZE + 1][2];            //保存最大最小值(第二维表示链中顶点个数)
int v[MAX_VETEX_SIZE];                                 //顶点（数值）
char op[MAX_VETEX_SIZE];                               //边（符号）


//--------------------------初始化m数组-----------------------------------------
void init_m(){
    int i;
    for (i = 0; i<REAL_SIZE; i++){
        m[i][1][0] = v[i];                             //链中只有一个顶点i
        m[i][1][1] = v[i];
    }
}


//-----------------------返回四个数中的最值---------------------------------------------
void getMin_Max(int n1, int n2, int n3, int n4, int* min, int* max){
    //返回四个操作数中的最大最小值
    *min = (n1>n2) ? ((n2>n3) ? (n3>n4 ? n4 : n3) : (n2>n4 ? n4 : n2))
        : ((n1>n3) ? (n3>n4 ? n4 : n3) : (n1>n4 ? n4 : n1));

    *max = (n1<n2) ? ((n2<n3) ? (n3<n4 ? n4 : n3) : (n2<n4 ? n4 : n2))
        : ((n1<n3) ? (n3<n4 ? n4 : n3) : (n1<n4 ? n4 : n1));
}


//-----------------------获取有断点的最大最小值--------------------------------------
void minMax(int i, int s, int j, int* minf, int* maxf){
    //p[i,j]从s处断开的最大值maxf 与 最小值minf
    //    int e[4];                                          //ac，ad，bc，bd 的值
    int a, b, c, d, r;
    a = m[i][s][0];                                    //a 保存从i 到 i+s顶点构成链的最小值
    b = m[i][s][1];

    r = (i + s) % REAL_SIZE;

    c = m[r][j - s][0];
    d = m[r][j - s][1];
    //printf("i=%d; s=%d; j=%d; r=%d\n",i,s,j,r);
    if (op[r] == '+'){                                  //处理加号
        *minf = a + c;
        *maxf = b + d;
    }
    else{                                              //处理乘法
        getMin_Max(a*c, a*d, b*c, b*d, minf, maxf);         //获取ac，ad，bc，bd 的最大最小值
    }
}

//------------------------------获取结果-------------------------------------------------
int Poly_Max(){
    int minf, maxf, temp;
    int i, j, s;
    for (j = 2; j <= REAL_SIZE; j++){                         //控制每个链中的顶点个数
        for (i = 0; i<REAL_SIZE; i++){                       //控制每个链中的顶点的起始位置
            for (s = 1; s<j; s++){
                minMax(i, s, j, &minf, &maxf);
                if (m[i][j][0] > minf) m[i][j][0] = minf;
                if (m[i][j][1] < maxf) m[i][j][1] = maxf;
            }
            //此时已经获得了从i到i+j的顶点所有s对应的值中最大和最小
        }
    }

    //求所有长度为REAL_SIZE个顶点的链中，值最大的
    temp = 0;
    for (i = 1; i<REAL_SIZE; i++){
        if (m[i][REAL_SIZE][1] > m[temp][REAL_SIZE][1]){
            temp = i;
        }
    }

    return m[temp][REAL_SIZE][1];
}



//---------------------------------主函数--------------------------------------------------
void main(){
    int i = 0;

    REAL_SIZE = 3;                       
    v[2] = 1;
    op[2] = '*';

    v[1] = 3;
    op[1] = '+';

    v[0] = 2;
    op[0] = '+';
    //1 x 3 + 2 +
    init_m();

    printf("%d\n", Poly_Max());                     //输出为 9
}
