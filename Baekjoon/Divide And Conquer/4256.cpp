#include <iostream>
#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> slice(const vector<int> &v, int a, int b)
{
    return vector<int>(v.begin() + a, v.begin() + b);
}
 
void printPostOrder(const vector<int> &preorder, const vector<int> &inorder)
{
    const int N = preorder.size();
 
    if (preorder.empty())
        return;
 
    const int root = preorder[0];
 
    int i;
    for (i = 0; i < N; i++)
        if (inorder[i] == root)
            break;
 
    const int L = i;
 
    const int R = N - L - 1;
    
    printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
 
    cout<<root;
}
int main()
{
    int tCase;
    vector<int> pre;
    vector<int> in;
    cin<<tCase;
 
    while (tCase--)
    {
        pre.clear();
        in.clear();
 
        int n, val;
        cin<<n;
 
        for (int i = 1; i <= n; i++)
        {
            cin>>val;
            pre.push_back(val);
        }
        for (int i = 1; i <= n; i++)
        {
            cin>>val;
            in.push_back(val);
        }
 
        printPostOrder(pre, in);
 
        cout<<"\n";
 
    }
 
    return 0;
}