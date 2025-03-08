#include <iostream>

using namespace std;

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