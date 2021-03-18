#include<iostream>
#include<vector>
using namespace std;
vector <int> arr;
vector<int> lotto;
vector <bool> visited;
int k;
void DFS(int cnt, int idx) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++)    cout << lotto[i] << " ";
        cout << "\n";
    }
    else {
        for (int j = idx; j < k; j++) {
            if (!visited[j]) {
                visited[j] = true;
                lotto.push_back(arr[j]);
                DFS(cnt + 1, j);
                visited[j] = false;
                lotto.pop_back();
            }
        }
    }
}
int main()
{
    while (1) {
        cin >> k;
        if (k == 0)    break;
        else {
            visited.assign(13, 0);
            for (int i = 0; i < k; i++) {
                int n;
                cin >> n;
                arr.push_back(n);
            }
            DFS(0, 0);
            cout << "\n";
            arr.clear();
        }
    }

    return 0;
}