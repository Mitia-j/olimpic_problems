#include <iostream>
using namespace std;
const int nmax = 300000;
struct av {
    int h, x;
    unsigned d;
} a[nmax];
int cnt = 0, MaxCount = 0, i, N;
int main() {
    cin >> N; // Читаем N перед использованием
    if (N > nmax) {
        cerr << "Ошибка: N превышает размер массива!" << endl;
        return 1;
    }

    for (i = 0; i < N; i++) {
        cin >> a[i].h >> a[i].x >> a[i].d;
    }
    while (true) {
        cnt = 0; // Обнуляем cnt перед подсчётом

        for (i = 0; i < N; i++) {
            for (int j = -i; j <= i; j++) { // Улучшенный диапазон
                if (a[i].x == j) cnt++;
            }
            if (a[i].d == 0) a[i].x--;
            else a[i].x++;
        }

        if (MaxCount < cnt) MaxCount = cnt;
        else break;
    }

    cout << "Максимальное количество: " << MaxCount << endl;
    return 0;
}