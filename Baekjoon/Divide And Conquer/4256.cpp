#include <cstdio>
#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node *left, *right;
    Node(int value):value(value) {}
};

int n;
int order[1001];
int preorder[1001];
int inorder[1001];

Node* make_tree(int st, int ed) {
    if (st > ed)
        return NULL;

    int min_order = 0x7ffffff, min_value = 0, min_i = 0;
    for (int i = st; i <= ed; i++) {
        int value = inorder[i];
        if (min_order > order[value]) {
            min_order = order[value];
            min_value = value;
            min_i = i;
        }
    }

    Node *root = new Node(min_value);
    root->left = make_tree(st, min_i - 1);
    root->right = make_tree(min_i + 1, ed);

    return root;
}

void post_order(Node *node) {
    if (node->left != NULL) post_order(node->left);
    if (node->right != NULL) post_order(node->right);
    printf("%d ", node->value);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> preorder[i];
            order[preorder[i]] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }

        Node *root = make_tree(0, n - 1);
        post_order(root);
        printf("\n");
    }
}