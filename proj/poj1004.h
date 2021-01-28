
#include <iostream>
#include <iomanip>
using namespace std;
int poj1004(){
                 float sum = 0,n ;
                 for ( int i = 0; i < 12; i++){
                                 cin >> n;
                                 sum += n;
                 }


                 cout << "$" << fixed << setprecision(2 )<< sum / 12;

                 return 0 ;
}

