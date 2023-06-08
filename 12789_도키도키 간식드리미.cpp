#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    int N, start = 1;
    cin >> N;
    for (int i = 0, j; i < N;)
    {
        if (!s.empty() && s.top() == start)
        {
            s.pop();
            ++start;
            continue;
        }

        cin >> j;
        ++i;
        if (start == j)
        {
            ++start;
            continue;
        }
        if (!s.empty() && s.top() < j)
        {
            cout << "Sad";
            return 0;
        }
        s.push(j);
    }

    cout << "Nice";
    return 0;
}