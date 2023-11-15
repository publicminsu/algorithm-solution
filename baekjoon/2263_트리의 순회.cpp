#include <iostream>
#include <vector>
using namespace std;
vector<int> inorder, postorder, inorderIndex, postorderIndex;
int n;
void makeTree(int start, int end, int curValue)
{
    int curInorderIndex = inorderIndex[curValue];
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

    cout << curValue << " ";
    if (leftPostIndex != -1)
    {
        int leftVal = postorder[leftPostIndex];
        makeTree(start, curInorderIndex, leftVal);
    }
    if (rightPostIndex != -1)
    {
        int rightVal = postorder[rightPostIndex];
        makeTree(curInorderIndex + 1, end, rightVal);
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
    int headVal = postorder.back();
    makeTree(0, n, headVal);
    return 0;
}