#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N, answer = 0;
    cin >> N;
    string n = to_string(N);
    if (N <= 10 && N / 2 == 0)   answer = N / 2;
    else {
        for (int i = N - 9 * n.size(); i <= N; i++) {
            int sum = i;
            string sum_str = to_string(sum);
            for (int j = 0; j < sum_str.size(); j++) {
                sum += sum_str[j] - '0';
            }
            if (sum == N) {
                answer = i;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}