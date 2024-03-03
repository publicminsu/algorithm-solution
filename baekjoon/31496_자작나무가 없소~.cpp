#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int N, answer, cnt;
string S, str, temp;
bool isContain()
{
    istringstream ss(str);
    while (getline(ss, temp, '_'))
    {
        if (temp == S) // 단어가 존재하면
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> S;
    while (N--)
    {
        cin >> str >> cnt;
        if (isContain())
        {
            answer += cnt;
        }
    }
    cout << answer;
    return 0;
}