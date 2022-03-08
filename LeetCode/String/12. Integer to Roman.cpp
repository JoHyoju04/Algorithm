class Solution {
public:
    string intToRoman(int num) {
        string answer = "";
        vector<char> order = { 'M','C','D','C','X','L','X','I','V','I' };
        int rest = num;
        int n;
        for (int i = 0; i < order.size(); i++) {
            char ch = order[i];
            int tmp = rest;
            switch (ch) {
            case 'M':
                n = rest / 1000;
                rest %= 1000;
                break;
            case 'D':
                n = rest / 500;
                rest %= 500;
                break;
            case 'C':
                n = rest / 100;
                rest %= 100;
                break;
            case 'L':
                n = rest / 50;
                rest %= 50;
                break;
            case 'X':
                n = rest / 10;
                rest %= 10;
                break;
            case 'V':
                n = rest / 5;
                rest %= 5;
                break;
            case 'I':
                n = rest / 1;
                rest %= 1;
                break;
            }
            if (n == 4) {
                answer += ch; answer += order[i + 1];
                i += 2;
            }
            else if (n == 9) {
                answer += ch;
                answer += order[i - 1];
                i += 2;
            }
            else if (i == 1 || i == 4 || i == 7) {
                rest = tmp;
                continue;
            }
            else {
                for (int j = 0; j < n; j++) answer += ch;
            }

        }
        return answer;

    }
};