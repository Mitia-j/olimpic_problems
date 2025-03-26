#include <iostream>
using namespace std;

int main (){
    const int nmax = 1000000;
    int j=0, i=0, N, M;
    char masiv [nmax][nmax];
    cin>>N>>M;
    
        for (i=N-1; i>=0; i--)
            for (j=M-1; j>=0; j--)
                cin>>masiv[i][j];
    return 0;
}