#include <string>
#include <vector>
#include <queue>
using namespace std;

struct state {
    int r, c;
    bool checkTable;
};
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

bool bfs(int idx, int curR, int curC, vector<vector<string>> places) {

    queue<state> q;
    vector<vector<bool> > visited(5, vector<bool>(5, 0));
    q.push({ curR,curC,0 });
    visited[curR][curC] = 1;
    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        bool check = q.front().checkTable;
        q.pop();
        if (abs(curR - r) + abs(curC - c) > 2)   continue;
        else if ((places[idx][r][c] == 'P' && check) || (abs(curR - r) + abs(curC - c) == 1 && places[idx][r][c] == 'P')) return false;

        for (int j = 0; j < 4; j++) {
            int nr = r + dir[j][0];
            int nc = c + dir[j][1];
            if (nr >= 5 || nc >= 5 || nr < 0 || nc < 0 || (places[idx][nr][nc] != 'P' && visited[nr][nc]) || (nr == curR && nc == curC)) continue;
            if (places[idx][nr][nc] == 'O')    q.push({ nr,nc,1 });
            else q.push({ nr,nc,check });
            visited[nr][nc] = 1;
        }
    }

    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);
    for (int i = 0; i < 5; i++) {
        bool flag = true;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (places[i][j][k] == 'P') {
                    if (!bfs(i, j, k, places)) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) break;
        }
        if (flag)   answer[i] = 1;
    }
    return answer;
}
/*
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool bfs(int row, int col, vector<string> p) {
    vector<vector<int> > cnt(5, vector<int>(5, 0));
    queue <pair<int, int> > q;
    q.push({ row,col });
    cnt[row][col] = 1;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = dir[i][0]+r;
            int nc = dir[i][1]+c;
            if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5)    continue;
            if (cnt[nr][nc] == 0 && p[nr][nc] != 'X') {
                if (p[nr][nc] == 'P' && cnt[r][c] <= 2)    return false;
                cnt[nr][nc] = cnt[r][c] + 1;
                q.push({ nr,nc });
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);
    for(int i=0;i<5;i++){
        vector<string> p=places[i];
        bool flag=true;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(p[j][k]=='P'){
                    if(!bfs(j,k,p)){
                        flag=false;
                        break;
                    }
                    else  p[j][k]='O';
                }
            }
            if(!flag)   break;
        }
        if(flag)    answer[i]=1;
    }
    return answer;
}
*/