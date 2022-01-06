#include <iostream>
#include <vector>
using namespace std;

void postOrder(vector<int>& pre, int start, int end) {
    int root = pre[start++], rStart = start, lEnd = 0;
    for (int i = start; i < pre.size(); i++) {
        if (root < pre[i]) {
            rStart = i;
            break;
        }
    }
    lEnd = rStart - 1;
    if (start <= lEnd) postOrder(pre, start, lEnd);
    if (rStart <= end) postOrder(pre, rStart, end);

    cout << root << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int size = 0;

    vector<int> preorder;
    int num;
    while (cin >> num) {
        preorder.push_back(num);
    }

    postOrder(preorder, 0, preorder.size() - 1);
    return 0;

}