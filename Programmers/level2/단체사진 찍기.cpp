#include <string>
#include <vector>
using namespace std;
 
int answer;
bool check[8];
string people="ACFJMNRT";
string str="";
 
void dfs(int cnt, vector<string> data)
{
    if (cnt == 8)
    {
        for (int i = 0; i < data.size(); i++)
        {
            char first = data[i][0];
            char second = data[i][2];
            char cond = data[i][3];
            int dist = data[i][4] - '0';
            dist++;
 
            int fIdx, sIdx;
            fIdx = sIdx = -1;
            for (int j = 0; j < 8; j++)
            {
                if (str[j] == first) fIdx = j;
                if (str[j] == second) sIdx = j;
                if (fIdx != -1 && sIdx != -1) break;
            }
 
            if (cond == '=' && !(abs(fIdx - sIdx) == dist)) return;
            if (cond == '<' && !(abs(fIdx - sIdx) < dist)) return;
            if (cond == '>' && !(abs(fIdx - sIdx) > dist)) return;
        }
        answer++;
        return;
    }
    
    for (int i = 0; i < 8; i++)
    {
        if (check[i]) continue;
        check[i] = true;
        str+=people[i];
        dfs(cnt + 1, data);
        check[i] = false;
        str.pop_back();
    }
}
 
int solution(int n, vector<string> data)
{
    answer=0;
    dfs(0,data);
    return answer;
}