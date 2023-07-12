#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string num;
    int N, K;
    stack<char> s;
    cin >> N >> K >> num;
    for (int i = 0; i < N; ++i)
        if (s.empty())
            s.push(num[i]);
        else
        {
            while (!s.empty() && s.top() < num[i] && K)
            {
                s.pop();
                --K;
            }
            s.push(num[i]);
        }
    while (K)
    {
        s.pop();
        --K;
    }
    num.clear();
    while (!s.empty())
    {
        num.push_back(s.top());
        s.pop();
    }
    reverse(num.begin(), num.end());
    cout << num;
    return 0;
}