#include <iostream>
using namespace std;
int k;
char A[9];
bool isVisited[10];
string answer[2] = {"0", "9999999999"};
void input()
{
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> A[i];
    }
}
void recur(int idx, string str)
{
    if (idx == k)
    {
        answer[0] = max(answer[0], str);
        answer[1] = min(answer[1], str);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        if (isVisited[i])
        {
            continue;
        }
        char nextC = i + '0';
        if ((A[idx] == '<' && (str.back() > nextC)) || (A[idx] == '>' && (str.back() < nextC))) // 부등호 확인
        {
            continue;
        }
        isVisited[i] = true;
        recur(idx + 1, str + nextC);
        isVisited[i] = false;
    }
}
int main()
{
    input();
    for (int i = 0; i < 10; ++i)
    {
        isVisited[i] = true;
        string str = "";
        str += static_cast<char>(i + '0');
        recur(0, str);
        isVisited[i] = false;
    }
    cout << answer[0] << "\n"
         << answer[1];
    return 0;
}