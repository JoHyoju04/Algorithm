#include <string>
#include <map>
#include <iostream>
using namespace std;

int m[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int move(char c){
    if(c=='U')  return 0;
    if(c=='D')  return 1;
    if(c=='R')  return 2;
    if(c=='L')  return 3;
}
int solution(string dirs) {
    int answer = 0;
    int r=0,c=0,mr=0,mc=0;
    map<string,int> visited;
    
    for(int i=0;i<dirs.size();i++){
        r=mr,c=mc;
        int d=move(dirs[i]);
        mr=r+m[d][0];
        mc=c+m[d][1];
        if(mr<-5||mc<-5||mr>5||mc>5){
            mr=r;
            mc=c;
            continue;
        }
        string start=to_string(r)+to_string(c);
        string end=to_string(mr)+to_string(mc);
        if(visited[start+end]==0&&visited[end+start]==0){
            answer++;
            visited[start+end]=1;
            visited[end+start]=1;
        }
    }
    return answer;
}