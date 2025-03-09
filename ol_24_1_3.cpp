#include <iostream>
using namespace std;
const int nmax = 300000;
struct av {
    int h, x;
    unsigned d;
};
av a[nmax];
int N, i;
int main() {
    
    for (i=0; i<N; i++){
        cin>>a[i].h>>a[i].x>>a[i].d;
    }
    return 0;
}