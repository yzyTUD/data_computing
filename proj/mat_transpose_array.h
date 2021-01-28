#include <iostream>
int main(){
    int N;
    std::cin>>N;
    int arr[N*N];
    int arr2[N*N];
    for(int i=0;i<N*N;i++){
        arr[i]=i;
    } 

    for(int i=0;i<N*N;i++){
        std::cout<<"\t"<<arr[i]<<",";
        if((i+1)%N==0)
            std::cout<<"\n";
    }

    //rotate 90 deg
    //arr[i][j]=arr[j][i]
    //arr[i*N+j]=arr[j*N+i]

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr2[i*N+j]=arr[j*N+i];
        }
    }

    std::cout<<"after rotate :"<<std::endl;
    for(int i=0;i<N*N;i++){
        std::cout<<"\t"<<arr2[i]<<",";
        if((i+1)%N==0)
            std::cout<<"\n";
    }
    

    return 0;
}