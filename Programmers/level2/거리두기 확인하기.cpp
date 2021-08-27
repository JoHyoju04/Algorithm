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