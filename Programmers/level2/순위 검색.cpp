#include <string>
#include <vector>
#include <map>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> score[3][2][2][2];
vector<int> solution(vector<string> info, vector<string> query) {
    string str = "";
    vector<int> answer;
    int idxL = 0, idxJ = 0, idxC = 0, idxF = 0;
    map<string, int> lang;
    map<string, int> job;
    map<string, int> career;
    map<string, int> food;
    lang["cpp"] = 0, lang["java"] = 1, lang["python"] = 2, lang["-"] = 3;
    job["backend"] = 0, job["frontend"] = 1, job["-"] = 2;
    career["junior"] = 0, career["senior"] = 1, career["-"] = 2;
    food["chicken"] = 0, food["pizza"] = 1, food["-"] = 2;

    for (int i = 0; i < info.size(); i++) {
        int cnt = 0;
        str = "";
        for (int j = 0; j < info[i].size(); j++) {
            if (info[i][j] == ' ') {
                if (cnt == 0)  idxL = lang[str];
                else if (cnt == 1) idxJ = job[str];
                else if (cnt == 2) idxC = career[str];
                else if (cnt == 3) idxF = food[str];
                str = "";
                cnt++;
                continue;
            }
            str += info[i][j];
            if (j == info[i].size() - 1) score[idxL][idxJ][idxC][idxF].push_back(stoi(str));
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    sort(score[i][j][k][l].begin(), score[i][j][k][l].end());
                }
            }
        }
    }
    for (int i = 0; i < query.size(); i++) {
        int cnt = 0, cntA = 0;
        str = "";
        int startL, startJ, startC, startF;
        for (int j = 0; j < query[i].size(); j++) {
            if (str == "and") {
                cnt++;
                str = "";
                continue;
            }
            if (query[i][j] == ' ') {
                if (cnt == 0) {
                    idxL = lang[str];
                    if (idxL == 3) {
                        startL = 0;
                        idxL--;
                    }
                    else startL = idxL;
                }
                else if (cnt == 1) {
                    idxJ = job[str];
                    if (idxJ == 2) {
                        startJ = 0;
                        idxJ--;
                    }
                    else startJ = idxJ;
                }
                else if (cnt == 2) {
                    idxC = career[str];
                    if (idxC == 2) {
                        startC = 0;
                        idxC--;
                    }
                    else startC = idxC;
                }
                else if (cnt == 3) {
                    idxF = food[str];
                    if (idxF == 2) {
                        startF = 0;
                        idxF--;
                    }
                    else startF = idxF;
                }
                str = "";
                continue;
            }
            str += query[i][j];
        }
        for (int a = startL; a <= idxL; a++) {
            for (int b = startJ; b <= idxJ; b++) {
                for (int c = startC; c <= idxC; c++) {
                    for (int d = startF; d <= idxF; d++) {
                        if (score[a][b][c][d].size() == 0)  continue;
                        auto it = lower_bound(score[a][b][c][d].begin(), score[a][b][c][d].end(), stoi(str));
                        cntA += score[a][b][c][d].size() - (it - score[a][b][c][d].begin());
                    }
                }
            }
        }
        answer.push_back(cntA);
    }

    return answer;

}