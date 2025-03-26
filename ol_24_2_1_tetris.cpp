#include <iostream>
using namespace std;

int main (){
    const int nmax = 1000000;
    int j=0, i=0, N, M;
    char masiv [nmax][nmax];
    cin>>N>>M;
    for (i=0; i<N; i++)
        for (j=0; j<M; j++)
            cin>>masiv[i][j];
    for (i=N-1; i>=0; i--)
        for (j=M-1; j>=0; j--) {
            if (masiv[i][j] == '.')
                masiv[i][j] = masiv[i-1][j-1];
        }
    return 0;
}