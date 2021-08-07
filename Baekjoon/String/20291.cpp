#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    map<string, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input, extension;
        int start;
        cin >> input;
        start = input.find('.');
        extension = input.substr(start + 1);
        m[extension]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) cout << it->first << " " << it->second<<"\n";
    return 0;
}