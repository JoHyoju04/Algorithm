#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() != b.size()) 	return a.size() < b.size();
    return a < b;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {

        int N;
        cin >> N;
        vector<string> list;
        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;
            list.push_back(input);
        }
        sort(list.begin(), list.end(), cmp);
        cout << "#" << test_case << "\n";
        string str = " ";
        for (int i = 0; i < N; i++) {
            if (str != list[i]) {
                cout << list[i] << "\n";
                str = list[i];
            }

        }
        list.clear();
    }
    return 0;
}