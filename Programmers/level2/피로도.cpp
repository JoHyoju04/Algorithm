#include <string>
#include <vector>

using namespace std;

int maxCnt;
bool visited[8];

void dfs(int cnt,int curr,vector<vector<int> > dun){
    if(cnt>maxCnt)  maxCnt=cnt;
    
    for(int i=0;i<dun.size();i++){
        if(curr>=dun[i][0]&&!visited[i]){
            visited[i]=1;
            dfs(cnt+1,curr-dun[i][1],dun);
            visited[i]=0;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    dfs(0,k,dungeons);
    answer=maxCnt;
    return answer;
}