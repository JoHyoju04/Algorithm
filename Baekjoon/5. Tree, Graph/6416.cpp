#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<int> nodes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int lineCnt = 0, caseCnt = 1;
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) {
            break;
        }
        if (a == 0 && b == 0) {
            if (lineCnt == 0 || nodes.size() == lineCnt + 1) {
                cout<<"Case "<<caseCnt<<" is a tree.\n";
                caseCnt++;
                nodes.clear();
                lineCnt = 0;
                continue;
            }
            else {
                cout<<"Case "<<caseCnt<<" is not a tree.\n";
                caseCnt++;
                nodes.clear();
                lineCnt = 0;
                continue;
            }

        }
        nodes.insert(a);
        nodes.insert(b);
        lineCnt++;
    }

    return 0;
}