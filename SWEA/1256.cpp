#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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

        int k, len;
        string word;
        vector<string> vec;
        cin >> k >> word;
        len = word.size();
        for (int i = 0; i < word.size(); i++) {
            string str = "";
            for (int j = 0; j < len; j++) {
                str += word[i + j];
            }
            len--;
            vec.push_back(str);
        }
        sort(vec.begin(), vec.end());


        cout << "#" << test_case << " " << vec[k - 1] << '\n';
        vec.clear();
    }
    return 0;
}