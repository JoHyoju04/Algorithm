#include <iostream>

using namespace std;

int inorder[100000];  // L -> root -> R
int postorder[100000]; // L -> R -> root
int pos[100001];

void preorder(int in_start, int in_end, int po_start, int po_end) {
    if (in_start > in_end || po_start > po_end) return;
    // postorder�� �� �ڰ� root
    int root = postorder[po_end];
    //  preorder �� root �� �켱������ ���
    cout << root << " ";
    int index = pos[root];
    int length = index - in_start;
    //  inorder ���� root �� �������� Left �� Right ����
    solve(in_start, index - 1, po_start, po_start + length - 1);
    solve(index + 1, in_end, po_start + length, po_end - 1);
}
int main(int argc, const char* argv[]) {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < n; i++) {
        pos[inorder[i]] = i;
        //inorder�� ��ġ ����
    }


    preorder(0, n - 1, 0, n - 1);
    return 0;
}