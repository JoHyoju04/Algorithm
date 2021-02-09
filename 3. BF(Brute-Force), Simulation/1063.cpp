#include<iostream>
#include<string>
#include<vector>
using namespace std;
pair<char, int> location(pair<char, int> ch, string m) {
    pair<char, int> loc = ch;
    int cnt = 0;
    if (m.find("R") != string::npos && ch.first + 1 <= 'H') {
        loc.first++;
        cnt++;
    }
    else if (m.find("L") != string::npos && ch.first - 1 >= 'A') {
        loc.first--;
        cnt++;
    }
    if (m.find("B") != string::npos && ch.second - 1 >= 1) {
        loc.second--;
        cnt++;
    }
    else if (m.find("T") != string::npos && ch.second + 1 <= 8) {
        loc.second++;
        cnt++;
    }
    if (m.size() != cnt)   loc = ch;
    return loc;
}
int main()
{
    vector<string> move(50);
    int N;
    pair<char, int> king;   pair<char, int> rock;
    cin >> king.first >> king.second >> rock.first >> rock.second >> N;
    for (int i = 0; i < N; i++) {
        cin >> move[i];
        pair<char, int> chess = location(king, move[i]);
        if (chess == king) continue;
        else if (chess == rock) {
            if (location(rock, move[i]) == rock)    continue;
            else rock = location(rock, move[i]);
        }
        king = chess;
    }

    cout << king.first << king.second << "\n" << rock.first << rock.second;
    return 0;
}