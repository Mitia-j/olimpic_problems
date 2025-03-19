#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_N = 300000;

struct Event {
    long long x;
    int type; // +1 (вход самолёта) или -1 (выход самолёта)
};

Event events[MAX_N * 2]; // Массив событий
int eventCount = 0; // Количество записанных событий

// Функция для сортировки (аналог лямбда-функции)
int compareEvents(const void* a, const void* b) {
    Event* ev1 = (Event*)a;
    Event* ev2 = (Event*)b;
    if (ev1->x != ev2->x) return (ev1->x < ev2->x) ? -1 : 1;
    return ev2->type - ev1->type; // Сначала +1, потом -1 при равных x
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long hi, xi, di;
        cin >> hi >> xi >> di;

        if (di == 0) { // Летит влево
            events[eventCount++] = {xi, 1};
            events[eventCount++] = {xi + hi + 1, -1};
        } else { // Летит вправо
            events[eventCount++] = {xi - hi, 1};
            events[eventCount++] = {xi + 1, -1};
        }
    }

    // Сортировка массива событий
    qsort(events, eventCount, sizeof(Event), compareEvents);

    int maxPlanes = 0, currentPlanes = 0;

    // Sweep Line (проход по событиям)
    for (int i = 0; i < eventCount; i++) {
        currentPlanes += events[i].type;
        if (currentPlanes > maxPlanes) {
            maxPlanes = currentPlanes;
        }
    }

    cout << maxPlanes << endl;
    return 0;
}