#include <iostream>
using namespace std;
int cnt;
string word, fullLine;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> word)
    {
        if (word == "<br>")
        {
            cnt = 0;
            cout << "\n";
        }
        else if (word == "<hr>")
        {
            if (cnt) // 이미 다른 단어가 있다면
            {
                cnt = 0;
                cout << "\n";
            }
            cout << "--------------------------------------------------------------------------------\n";
        }
        else
        {
            if (cnt + word.size() + 1 > 80) // 80개를 넘는다면
            {
                cnt = 0;
                cout << "\n";
            }
            if (cnt) // 이미 다른 단어가 있다면
            {
                cout << " ";
                ++cnt;
            }
            cout << word;
            cnt += word.size();
        }
    }
    return 0;
}