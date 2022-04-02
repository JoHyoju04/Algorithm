#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        string s, tmp;
        cin >> s;
        tmp.push_back(s[0]);

        for (int j = 1; j < s.size(); j++)
        {
            if (tmp != s.substr(tmp.size(), j))
                tmp.push_back(s[j]);
            else
                break;
        }
        cout << "#" << i << " " << tmp.size() << endl;
    }
    return 0;
}