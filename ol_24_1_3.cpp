#include <iostream>
using namespace std;
const int nmax = 300000;
struct av {
    int h, x;
    unsigned d;
} a[nmax];
int cnt = 0, MaxCount = 0, i, N, i1=-1, i2=1, j, im=0;
int main() {
    cin >> N; // Читаем N перед использованием
    if (N > nmax) {
        cerr << "Ошибка: N превышает размер массива!" << endl;
        return 1;
    }

    for (i = 0; i < N; i++) {
        cin >> a[i].h >> a[i].x >> a[i].d;
    }
    while (im<1000) {
        cnt = 0; // Обнуляем cnt перед подсчётом

        for (i = 0; i < N; i++) {
            for (j=0; j<nmax; j++){
                if (a[i].x >= i1 && a[i].x <= i2)
                    if(a[i].h >= i2){ 
                        cnt++;
                        goto next;
                    }
                    else goto next;
                i1--; i2++;
            }
        next:
            if (a[i].d == 0) a[i].x--;
            else a[i].x++;
            i1=-1; i2=1;
        }
        if (MaxCount <= cnt) MaxCount = cnt;
        //else break;
        im++;
    }
    cout << "Максимальное количество: " << MaxCount << endl;
    return 0;
}