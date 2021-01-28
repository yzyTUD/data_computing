#include <iostream>
#include <cmath>
int main(){
    
    int num=2;
    while(num<101){
        bool isprime=true;
        for(int i=2;i<num;i++){
            if(num%i==0)
                isprime=false;
        }
        if(isprime)
            std::cout<<"a prime found: "<< num<<std::endl;
        num++;
    }
    return 0;
}