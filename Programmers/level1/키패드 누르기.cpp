#include <string>
#include <vector>
#include <cmath>
using namespace std;

string midkey(int Lsub, int Rsub, string hand) {
    int Ldist, Rdist;
    if (Lsub == Rsub)  return (hand == "right") ? "R" : "L";
    else {
        if (Lsub == 1 || Lsub == 3)    Ldist = 1;
        else if (Lsub == 2 || Lsub == 4 || Lsub == 6)  Ldist = 2;
        else if (Lsub == 5 || Lsub == 7 || Lsub == 9)  Ldist = 3;
        else if (Lsub == 0)    Ldist = 0;
        else Ldist = 4;

        if (Rsub == 1 || Rsub == 3)    Rdist = 1;
        else if (Rsub == 2 || Rsub == 4 || Rsub == 6)  Rdist = 2;
        else if (Rsub == 5 || Rsub == 7 || Rsub == 9)  Rdist = 3;
        else if (Rsub == 0)    Rdist = 0;
        else Rdist = 4;

        if (Ldist == Rdist)    return (hand == "right") ? "R" : "L";
        else
        {
            return Ldist < Rdist ? "L" : "R";
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int Lsub, Rsub, l = 10, r = 12;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            l = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            r = numbers[i];
        }
        else {
            int num = (numbers[i] == 0) ? 11 : numbers[i];
            Lsub = abs(num - l);
            Rsub = abs(num - r);

            answer += midkey(Lsub, Rsub, hand);
            if (answer[i] == 'L')  l = num;
            else r = num;
        }
    }
    return answer;
}