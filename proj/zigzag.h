#include <cstdlib>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

// C++ ZigZag Scan Algorithm
// Compiling: g++ zigzag.cpp -o zigzag
// Usage: ./zigzag N M
// Based on http://stackoverflow.com/questions/3025595/code-golf-zigzag-pattern-scanning 
// but this is not a shorter one ;]

bool buble (std::vector<int> i, std::vector<int> j) { return  (i[0] == j[0]) ? (i[1] < j[1]) : (i[0] < j[0]); }

int main(int argc, char* argv[]){

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    
    std::vector< std::vector<int> > p( N*M, std::vector<int>(3) );   
    for(int i = 0; i < N*M; i++){
        p[i][0] = i % N + i / N;
        p[i][1] = (((i % N - i / N) % 2) == 0 ? i % N : i / N);
        p[i][2] = i;
    }
    std::sort(p.begin(), p.end(), buble);
    
    for(int i = 0; i < N*M; i++){
        std::cout << ' ' << p[i][2];
        //if((i+1)%N==0)
            //std::cout<<"\n";
    }
        
    
    std::cout << std::endl;
}