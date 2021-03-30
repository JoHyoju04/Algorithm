#include <iostream>
#include<vector>
#include <queue>
#include<string>
#include<cmath>
using namespace std;

vector<string> wheels(5);
vector<bool> visited;

void rotate(int n, int t, vector<string>& ret) {
    string wheel = ret[n], tmp;
    if (t == -1) {
        wheel += wheel[0];
        wheel = wheel.substr(1);
    }
    else {
        tmp = wheel[7];
        wheel.pop_back();
        tmp += wheel;
        wheel = tmp;
    }
    ret[n] = wheel;
    return;
}
int getScore() {
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        if (wheels[i][0] == '1')   ans += pow(2, i - 1);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 4; i++) {
        cin >> wheels[i];
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int num, turn;
        cin >> num >> turn;
        visited.assign(5, 0);
        queue <pair<int, int> > que;
        que.push({ num,turn });
        visited[num] = true;
        while (!que.empty()) {
            int curN = que.front().first;
            int curT = que.front().second;
            que.pop();
            if (curN - 1 > 0 && wheels[curN - 1][2] != wheels[curN][6] && !visited[curN - 1]) {
                que.push({ curN - 1,-curT });
                visited[curN - 1] = true;
            }
            if (curN + 1 <= 4 && wheels[curN][2] != wheels[curN + 1][6] && !visited[curN + 1]) {
                que.push({ curN + 1,-curT });
                visited[curN + 1] = true;
            }
            rotate(curN, curT, wheels);

        }
    }
    int answer = getScore();
    cout << answer;
    return 0;
}