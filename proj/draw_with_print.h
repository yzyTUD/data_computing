
#include <stdio.h>
#define MAXSIZE 100
#define MAXJ 100.0
typedef struct {
                 int height ;
                 char sign ;
                 char figure [MAXSIZE][ MAXSIZE];
} Graph;

void Init( Graph * G, int h , char s){
                 G->height = h;
                 G->sign = s;
                 for ( int i = 0; i < h; i++)
                 for ( int j = 0; j < h; j++)
                                 G->figure [i][ j] = ' ' ;
}

void PaintZhong( Graph * G){
                 for ( int i = 0; i < G-> height; i++)//中间一行
                                 G->figure [i][( int)(G ->height* 0.5)] = G ->sign;

                 for ( int i = (int)( G->height *0.25); i<( int)(G ->height* 0.5); i++)//纵向两条
                                 G->figure [i][( int)(G ->height* 0.2)] = G ->sign;
                 for ( int i = (int)( G->height *0.25); i<( int)(G ->height* 0.5); i++)
                                 G->figure [i][( int)(G ->height* 0.8)] = G ->sign;

                 for ( int i = (int)( G->height *0.2); i <(int)( G->height * 0.8); i++)//横向两条
                                 G->figure [(int)( G->height *0.25)][ i] = G ->sign;
                 for ( int i = (int)( G->height *0.2); i <(int)( G->height * 0.8); i++)
                                 G->figure [(int)( G->height *0.5)][ i] = G ->sign;

}

void PaintTree( Graph * G){

                 for ( int j = 0; j <( int)(G ->height* 0.6); j++){
                                 if ( 2 * j>( int)(G ->height* 0.8) - ( int)(G ->height * 0.4 ) - 1)
                                                 G->figure [j][( int)(G ->height* 0.8) - j - 1] = '/' ;
                                 for ( int i = (int)( G->height *0.8) - j; i < (int )(G-> height * 0.4) + j; i++){

                                                 G->figure [j][ i] = G ->sign;
                                 }
                                 if ( 2 * j>( int)(G ->height* 0.8) - ( int)(G ->height * 0.4 ) - 1)
                                                 G->figure [j][( int)(G ->height * 0.4 ) + j] = '\\';
                 }
                 /*for (int j = 0; j < 100; j++){
                for (int i = (int)(G->height*0.5) - (int)(G->height*0.4*(j / MAXJ));i < (int)(G->height * 0.3*(j / MAXJ)) + (int)(G->height * 0.5); i++){
                G->figure[(int)(G->height*0.5*(j / MAXJ))][i] = G->sign;
                }

                }*/

                 //for (int i = (int)(G->height*0.4); i <(int)(G->height * 0.7); i++)//右侧树
                 //    G->figure[(int)(G->height*0.35)][i] = G->sign;
                 //for (int i = (int)(G->height*0.35); i <(int)(G->height * 0.75); i++)//右侧树
                 //    G->figure[(int)(G->height*0.4)][i] = G->sign;
                 //for (int i = (int)(G->height*0.3); i <(int)(G->height * 0.8)   ; i++)//右侧树
                 //    G->figure[(int)(G->height*0.5)][i] = G->sign;

                 for ( int i = (int)( G->height *0.6); i < G ->height; i++){ //中间
                                 G->figure [i][( int)(G ->height* 0.58)] = G ->sign;
                                 G->figure [i][( int)(G ->height* 0.58) + 1 ] = G-> sign;
                 }
}

void Show( Graph * G){
                 for ( int i = 0; i < G-> height; i++){
                                 for ( int j = 0; j < G-> height; j++){
                                                 printf("%c" , G ->figure[ i][j ]);
                                 }
                                 printf("\n" );
                 }
}

int main(){
                 int h ;
                 char s ;
                 Graph * G = new Graph;

                 while ( 1){
                                 printf("请输入图的高度以及绘图所用符号，格式：（高度 符号）");
                                 scanf("%d %c" , & h, &s);
                                 Init(G , h , s );
                                 PaintZhong(G );
                                 Show(G );
                 }

                 return 0 ;
}

