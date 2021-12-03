#include <iostream>
#include <string>
#define MOD 1000000
using namespace std;

int dp[5002];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string input;

    cin >> input;

    if (input == "0") {
        cout << "0";
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= input.size(); i++) {
        if (input[i-1]-'0'>0 &&input[i-1]-'0'<=26) {
            dp[i] = (dp[i - 1] + dp[i]) % MOD;
        }
        if (i == 1)    continue;
        int num = (input[i - 2] - '0') * 10 + (input[i-1] - '0');
        if (num >= 10 && num <= 26) {
            dp[i] = (dp[i - 2] + dp[i]) % MOD;
        }
    }

    cout << dp[input.size()];
    
    return 0;
}