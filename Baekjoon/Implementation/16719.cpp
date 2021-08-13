#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++){
        vector<pair<string, int>> cand;
        for (int j = 0; j < s.size(); j++){
            if (!visited[j]){
                string temp;
                for (int k = 0; k < s.size(); k++){
                    if (j == k || visited[k])    
                        temp += s[k];
                }
                cand.push_back({ temp, j });
            }
        }
        sort(cand.begin(), cand.end());
        cout << cand[0].first << "\n";
        visited[cand[0].second] = true;
    }
    return 0;
}