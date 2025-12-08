#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    string A, B;

    cin >> A >> B;

    int i = A.length() - 1, j = B.length() - 1;
    bool carry = false;

    while (i >= 0 || j >= 0)
    {
        int aNum = 0;

        if (i >= 0)
        {
            aNum = A[i] - '0';
            --i;
        }

        int bNum = 0;

        if (j >= 0)
        {
            bNum = B[j] - '0';
            --j;
        }

        int sum = aNum + bNum + carry;

        st.push(sum % 10);
        carry = sum / 10;
    }

    if (carry)
    {
        st.push(1);
    }

    while (!st.empty())
    {
        int num = st.top();
        st.pop();
        cout << num;
    }
    return 0;
}