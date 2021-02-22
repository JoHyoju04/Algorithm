#include <iostream>
#include <vector>
using namespace std;
int N, M, K, answer = 5000;
vector<vector<int> > arr(51, vector<int>(51, 0));
vector <bool> visited(51);
int rotation[7][4] = { 0, };

int minimum(vector<vector<int> > arr) {
    int ret = 5000, sum;
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < M; j++) {
            sum += arr[i][j];
        }
        ret = ret < sum ? ret : sum;
    }
    return ret;
}
vector<vector<int> > rotate(int r, int c, int s, vector <vector<int> > a) {
    vector<vector<int> > arr = a;
    for (int i = 1; i <= s; i++) {
        int tmp = arr[r - i][c - i];
        for (int a = r - i; a < r + i; a++)    arr[a][c - i] = arr[a + 1][c - i];
        for (int b = c - i; b < c + i; b++)    arr[r + i][b] = arr[r + i][b + 1];
        for (int a = r + i; a > r - i; a--)    arr[a][c + i] = arr[a - 1][c + i];
        for (int b = c + i; b > c - i; b--)    arr[r - i][b] = arr[r - i][b - 1];
        arr[r - i][c - i + 1] = tmp;
    }
    return arr;
}
void DFS(int num, vector<vector<int> >board) {
    if (num == K) {
        int min = minimum(board);
        answer = min > answer ? answer : min;
    }
    else {
        for (int i = 0; i < K; i++) {
            if (!visited[i]) {
                visited[i] = true;
                vector <vector<int> > b = rotate(rotation[i][0] - 1, rotation[i][1] - 1, rotation[i][2], board);
                DFS(num + 1, b);
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> rotation[i][0] >> rotation[i][1] >> rotation[i][2];
    }
    DFS(0, arr);
    cout << answer;
    return 0;
}