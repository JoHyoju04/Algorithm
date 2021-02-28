#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > cnt;
int dir[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };
int t, I;
int BFS(int start_r, int start_c, int end_r, int end_c) {
    queue<pair<int, int> > que;
    que.push({ start_r,start_c });
    cnt[start_r][start_c] = 1;
    while (!que.empty()) {
        int r_loc = que.front().first;
        int c_loc = que.front().second;
        que.pop();
        if (r_loc == end_r && c_loc == end_c)  return cnt[r_loc][c_loc];
        for (int i = 0; i < 8; i++) {
            int r = r_loc + dir[i][0];
            int c = c_loc + dir[i][1];
            if (r >= 0 && r < I && c >= 0 && c < I && cnt[r][c] == 0) {
                que.push({ r,c });
                cnt[r][c] = cnt[r_loc][c_loc] + 1;
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> I;
        cnt.assign(I, vector<int>(I, 0));
        int curr_r, curr_c, end_r, end_c;
        cin >> curr_r >> curr_c >> end_r >> end_c;
        cout << BFS(curr_r, curr_c, end_r, end_c) - 1 << "\n";
    }
    return 0;
}