#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        string answer = "";
        cin >> n;
        vector<pair<int, int> > inputs;
        vector<bool> visited;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            inputs.push_back({ a,b });
        }
        for (int i = 0; i < n; i++) {
            string str = to_string(inputs[i].first) + " " + to_string(inputs[i].second);
            int end = inputs[i].second;
            visited.assign(n, 0);
            visited[i] = 1;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (!visited[k]) {
                        int start = inputs[k].first;
                        if (end == start) {
                            visited[k] = 1;
                            str += " " + to_string(inputs[k].first) + " " + to_string(inputs[k].second);
                            end = inputs[k].second;
                            break;
                        }
                    }
                }
            }
            if (answer.size() < str.size())    answer = str;
        }
        inputs.clear();
        cout << "#" << test_case << " ";
        cout << answer;
        cout << "\n";


    }
    return 0;
}