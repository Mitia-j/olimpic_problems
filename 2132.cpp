#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> matrix;

// Функция для подсчёта 2x2 блоков
int countBlocks() {
    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (matrix[i][j] == matrix[i][j + 1] &&
                matrix[i][j] == matrix[i + 1][j] &&
                matrix[i][j] == matrix[i + 1][j + 1]) {
                count++;
            }
        }
    }
    return count;
}

// Функция для циклического сдвига вверх
void shiftUp() {
    vector<int> temp = matrix[0]; // Сохраняем первую строку
    for (int i = 0; i < N - 1; i++) {
        matrix[i] = matrix[i + 1];
    }
    matrix[N - 1] = temp; // Переносим первую строку в конец
}

// Функция для циклического сдвига вниз
void shiftDown() {
    vector<int> temp = matrix[N - 1]; // Сохраняем последнюю строку
    for (int i = N - 1; i > 0; i--) {
        matrix[i] = matrix[i - 1];
    }
    matrix[0] = temp; // Переносим последнюю строку в начало
}

// Функция для циклического сдвига влево
void shiftLeft() {
    for (int i = 0; i < N; i++) {
        int first = matrix[i][0];
        for (int j = 0; j < M - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
        matrix[i][M - 1] = first;
    }
}

// Функция для циклического сдвига вправо
void shiftRight() {
    for (int i = 0; i < N; i++) {
        int last = matrix[i][M - 1];
        for (int j = M - 1; j > 0; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][0] = last;
    }
}

// Функция для поиска оптимального расположения
int findMaxBlocks() {
    int maxBlocks = countBlocks();

    bool improved = true;
    while (improved) {
        improved = false;
        int bestMove = 0;
        vector<vector<int>> bestMatrix = matrix;

        // Пробуем все 4 направления
        shiftUp();
        int upBlocks = countBlocks();
        if (upBlocks > maxBlocks) {
            maxBlocks = upBlocks;
            bestMove = 1;
            bestMatrix = matrix;
        }
        shiftDown(); // Возвращаем в исходное положение

        shiftDown();
        int downBlocks = countBlocks();
        if (downBlocks > maxBlocks) {
            maxBlocks = downBlocks;
            bestMove = 2;
            bestMatrix = matrix;
        }
        shiftUp(); // Возвращаем в исходное положение

        shiftLeft();
        int leftBlocks = countBlocks();
        if (leftBlocks > maxBlocks) {
            maxBlocks = leftBlocks;
            bestMove = 3;
            bestMatrix = matrix;
        }
        shiftRight(); // Возвращаем в исходное положение

        shiftRight();
        int rightBlocks = countBlocks();
        if (rightBlocks > maxBlocks) {
            maxBlocks = rightBlocks;
            bestMove = 4;
            bestMatrix = matrix;
        }
        shiftLeft(); // Возвращаем в исходное положение

        // Если найдено улучшение, применяем лучший сдвиг
        if (bestMove != 0) {
            matrix = bestMatrix;
            improved = true;
        }
    }
    return maxBlocks;
}

int main() {
    cin >> N >> M;
    matrix.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            matrix[i][j] = row[j] - '0';
        }
    }

    cout << findMaxBlocks() << endl;
    return 0;
}