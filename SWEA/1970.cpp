#include<iostream>

using namespace std;
int money[8] = { 50000,10000,5000,1000,500,100,50,10 };
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        cout << "#" << test_case << " \n";
        for (int i = 0; i < 8; i++) {
            int cnt = N / money[i];
            cout << cnt << " ";
            N %= money[i];
        }
        cout << "\n";
    }
    return 0;
}