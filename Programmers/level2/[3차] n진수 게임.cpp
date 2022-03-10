#include <string>
#include <vector>
#include <iostream>
using namespace std;

char intToChar(int r) {
    switch (r) {
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    }
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string game = "0";
    for (int i = 1; game.size() <= m * t; i++) {
        int num = i, rest;
        string str = "";
        while (num) {
            rest = num % n;
            num /= n;
            if (n > 10 && rest >= 10) str += intToChar(rest);
            else str += (rest + '0');
        }
        for (int j = str.size() - 1; j >= 0; j--)  game += str[j];
    }
    int idx = p - 1;
    for (int i = 0; i < t; i++) {
        answer += game[idx];
        idx += m;
    }
    return answer;
}