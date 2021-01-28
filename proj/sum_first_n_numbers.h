#include <iostream>
int main(){
    int n,sum=0;
    std::cin>>n;
    for(int i=0;i<n;i++){
        sum+=i+1;
    }
    std::cout<<sum;

    return 0;
}   