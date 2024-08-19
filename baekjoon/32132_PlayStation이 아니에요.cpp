#include <iostream>
using namespace std;
int N;
string str, answer;
int main()
{
    cin >> N >> str;
    for (char &c : str)
    {
        int size = answer.size();
        if (size >= 2 && answer[size - 2] == 'P' && answer[size - 1] == 'S' && (c == '4' || c == '5'))
        {
            continue;
        }
        answer += c;
    }
    cout << answer;
    return 0;
}