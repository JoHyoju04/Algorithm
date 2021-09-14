#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MAX 987654321
using namespace std;

bool visited[21];
int arr[21][21];
int N;
int answer = MAX;

void dfs(int idx,int cnt) {
    if (cnt > N / 2) return;
    else if(cnt!=0){
        int s = 0, l = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i!=j) {
                    if (!visited[i] && !visited[j])    l += arr[i][j];
                    if (visited[i] && visited[j])  s += arr[i][j];
                }
            }
        }
        answer = min(answer, abs(s - l));
    }
    for (int i = idx; i < N; i++) {
        visited[i] = 1;
        dfs(i + 1,cnt+1);
        visited[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    dfs(0,0);
    cout << answer;
    
    return 0;
}