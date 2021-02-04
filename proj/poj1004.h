/*
test input:


*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float sum = 0,n ;
    for ( int i = 0; i < 12; i++){
        cin >> n;
        sum += n;
    }


    cout << "$" << fixed << setprecision(2 )<< sum / 12;

    return 0 ;
}

