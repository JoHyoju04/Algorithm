#include<iostream>
#include<vector>
using namespace std;

int N, answer = 987654321;
int arr[21][21];
bool visited[21];

void dfs(int cnt, int idx) {
    if (cnt == N / 2) {
        vector<int> lList;
        vector<int> sList;
        int sSum = 0, lSum = 0;
        for (int j = 0; j < N; j++) {
            if (visited[j]) {
                sList.push_back(j);
            }
            else lList.push_back(j);
        }

        for (int j = 0; j < N / 2 - 1; j++) {
            for (int k = j + 1; k < N / 2; k++) {
                sSum += arr[sList[j]][sList[k]];
                sSum += arr[sList[k]][sList[j]];
                lSum += arr[lList[j]][lList[k]];
                lSum += arr[lList[k]][lList[j]];
            }
        }
        answer = answer < abs(sSum - lSum) ? answer : abs(sSum - lSum);
        return;
    }
    for (int i = idx; i < N; i++) {
        visited[i] = 1;
        dfs(cnt + 1, i + 1);
        visited[i] = 0;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0);

    cout << answer;

    return 0;
}