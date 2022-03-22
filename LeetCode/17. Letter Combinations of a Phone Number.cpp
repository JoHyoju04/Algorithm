class Solution {
public:
    char pDigit[10][4] = {
        {' ',' ',' ',' '},
        {'a','b','c',' '},
        {'d','e','f',' '},
        {'g','h','i',' '},
        {'j','k','l',' '},
        {'m','n','o',' '},
        {'p','q','r','s'},
        {'t','u','v',' '},
        {'w','x','y','z'},
        {' ',' ',' ',' '}
    };
    vector<string> answer;
    void com(int cnt, string str, string digits) {
        if (cnt == digits.size()) {
            answer.push_back(str);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int n = digits[cnt] - '0';
            if (pDigit[n - 1][i] == ' ') continue;
            com(cnt + 1, str + pDigit[n - 1][i], digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)    return answer;

        com(0, "", digits);

        return answer;
    }
};