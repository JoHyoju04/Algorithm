#include<iostream>
using namespace std;
int N, M, sum = 0, result = 0;
bool visited[101] = { 0, };
int arr[101];
// DFS: 메모리 2016KB, 시간 4ms
void DFS(int size) {
    if (size == 3) {
        if (sum <= M && sum > result) {
            result = sum;
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sum += arr[i];
                DFS(size + 1);
                sum -= arr[i];
                visited[i] = false;
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    DFS(0);
    cout << result;
    return 0;
}
/*  이중 for문 : 메모리 2016KB, 시간 0ms
#include <iostream>
using namespace std;

int main() {
    int N, M, num[100] = { 0 }, answer = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                if (a != b && a != c && b != c) {
                    int sum = num[a] + num[b] + num[c];
                    if ((answer < sum) && (sum <= M))
                        answer = sum;
                }
            }
        }
    }
    cout << answer;
}
*/