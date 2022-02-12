#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {

        int N, M;
        int answer = 0;
        unordered_map<string, int> m1, m2;
        cin >> N >> M;
        string input;
        for (int i = 0; i < N; i++) {
            cin >> input;
            m1.insert({ input,1 });
        }
        for (int i = 0; i < M; i++) {
            cin >> input;
            m2.insert({ input,1 });
        }
        if (M > N) {
            unordered_map<string, int> tmp(m1);
            m1 = m2;
            m2 = tmp;
        }
        for (auto iter = m1.begin(); iter != m1.end(); iter++) {
            if (m2.find(iter->first) != m2.end())  answer++;
        }
        cout << "#" << test_case << " " << answer << "\n";
        m1.clear();
        m2.clear();

    }
    return 0;
}