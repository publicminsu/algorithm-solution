#include <iostream>
#include <stack>

using namespace std;

int N, B;
stack<char> st;

char numToChar(int num)
{
    if (num >= 10)
    {
        return 'A' + (num - 10);
    }

    return '0' + num;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> B;

    while (N)
    {
        st.push(numToChar(N % B));
        N /= B;
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}