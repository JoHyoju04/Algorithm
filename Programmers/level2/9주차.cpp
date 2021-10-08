#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
vector<bool> visited;
vector<int> tree[102];
int cnt;

void dfs(int start,int cut){
    visited[start]=1;
    cnt++;
    for(int i=0;i<tree[start].size();i++){
        int adj=tree[start][i];
        if(!visited[adj]&&adj!=cut) dfs(adj,cut);
    }
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    visited.assign(n+1,0);
    for(int i=0;i<wires.size();i++){
        tree[wires[i][0]].push_back(wires[i][1]);
        tree[wires[i][1]].push_back(wires[i][0]);
    }
    for(int i=0;i<wires.size();i++){
        int num=wires[i][0];
        cnt=0;
        visited.assign(n+1,0);
        dfs(num,wires[i][1]);
        answer=answer<abs((n-cnt)-cnt)?answer:abs((n-cnt)-cnt);
    }
    return answer;
}