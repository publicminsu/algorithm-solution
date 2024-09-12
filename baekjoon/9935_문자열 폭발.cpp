#include <iostream>
using namespace std;
string str, boom, answer;
int boomSize;
bool isBoomWord()
{
    int answerSize = answer.size();

    if (answerSize - boomSize < 0)
    {
        return false;
    }

    for (int i = 0; i < boomSize; ++i)
    {
        if (answer[answerSize - boomSize + i] != boom[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> str >> boom;

    boomSize = boom.size();
    answer.reserve(str.size());

    for (const char &c : str)
    {
        answer.push_back(c);

        while (true)
        {
            if (answer.size() < boomSize || !isBoomWord())
            {
                break;
            }

            for (int i = 0; i < boomSize; ++i)
            {
                answer.pop_back();
            }
        }
    }

    if (answer.size() == 0)
    {
        answer = "FRULA";
    }

    cout << answer;
    return 0;
}