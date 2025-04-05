#include <iostream>
#include <algorithm>
using namespace std;

string S, T;

bool recur(string curT)
{
    if (S.size() == curT.size())
    {
        return curT == S;
    }

    bool value = false;

    if (curT.back() == 'A')
    {
        string nextT = curT;
        nextT.pop_back();
        value |= recur(nextT);
    }

    if (value)
    {
        return true;
    }

    if (curT.front() == 'B')
    {
        string nextT = curT;
        reverse(nextT.begin(), nextT.end());
        nextT.pop_back();
        value |= recur(nextT);
    }

    return value;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> S >> T;
    cout << recur(T);
    return 0;
}