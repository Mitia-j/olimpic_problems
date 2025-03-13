#include <iostream>
using namespace std;
int cnt, MaxCount, i, N;
const int nmax = 300000;
struct av {
    int h, x;
    unsigned d;
};
av a[nmax];
int main() {
    for (i=0; i<N; i++){
        cin>>a[i].h>>a[i].x>>a[i].d;
    }
    while (true){
        for (i=0; i<N; i++){
            for (int j=-i; j<=i; j++){
                if (a[i].x==j) cnt++;
            }
            if (a[i].d==0) a[i].x--;
            else a[i].x++;
        }
        if (MaxCount<=cnt) MaxCount = cnt;
        else break;
    }
    return 0;
}