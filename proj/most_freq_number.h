#include <iostream>
int most_freq_number(){
    int a[]={23,4,21,3,4,5,6,7,8,8,4};
    int a_fre[]={0 ,0,0,0,0,0,0,0,0,0,0};

    int size = sizeof(a)/sizeof(*a);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(a[j]==a[i])
                a_fre[i]++;
        }
    }

    for(int i=0;i<size;i++){
        std::cout<<a_fre[i]<<" ";
    }

    int mostfrenumber=0;
    for(int i=0;i<size;i++)
    {
        if(a_fre[i]>mostfrenumber)
            mostfrenumber=i;

    }
    std::cout<<"\n mostfrenumber is :"<< a[mostfrenumber];

    return 0;
}