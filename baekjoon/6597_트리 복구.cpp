#include <iostream>
using namespace std;
string preorder, inorder;
int index;

void recur(int left, int right)
{
    if (left > right)
    {
        return;
    }

    char curNode = preorder[index++];
    int curInorderIndex = inorder.find(curNode);

    recur(left, curInorderIndex - 1);
    recur(curInorderIndex + 1, right);

    cout << curNode;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (cin >> preorder >> inorder)
    {
        index = 0;
        recur(0, preorder.size() - 1);
        cout << "\n";
    }
    return 0;
}