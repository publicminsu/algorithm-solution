#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int value;
    node *left, *right;
};
vector<int> inorder, postorder, inorderIndex, postorderIndex;
int n;
void preorder(node *curNode)
{
    if (curNode == nullptr)
    {
        return;
    }
    cout << curNode->value << " ";
    preorder(curNode->left);
    preorder(curNode->right);
}
void makeTree(node *curNode, int start, int end)
{
    int curInorderIndex = inorderIndex[curNode->value];
    int leftPostIndex = -1, rightPostIndex = -1;
    // 가장 높은 포스트 오더 인덱스를 가져옴
    for (int i = start; i < curInorderIndex; ++i)
    {
        leftPostIndex = max(postorderIndex[inorder[i]], leftPostIndex);
    }
    for (int i = curInorderIndex + 1; i < end; ++i)
    {
        rightPostIndex = max(postorderIndex[inorder[i]], rightPostIndex);
    }
    if (leftPostIndex != -1)
    {
        node *left = new node();
        left->value = postorder[leftPostIndex];
        curNode->left = left;
        makeTree(left, start, curInorderIndex);
    }
    if (rightPostIndex != -1)
    {
        node *right = new node();
        right->value = postorder[rightPostIndex];
        curNode->right = right;
        makeTree(right, curInorderIndex + 1, end);
    }
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    inorder = postorder = vector<int>(n);
    inorderIndex = postorderIndex = vector<int>(n + 1);

    // 순회를 저장해 주고 해당 값의 인덱스를 저장해 줌
    for (int i = 0; i < n; ++i)
    {
        cin >> inorder[i];
        inorderIndex[inorder[i]] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> postorder[i];
        postorderIndex[postorder[i]] = i;
    }
}
int main()
{
    input();
    node *head = new node();
    int headVal = postorder.back();
    head->value = headVal;
    makeTree(head, 0, n);
    preorder(head);
    return 0;
}