#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> fail;
int ret;
void failFunc(string word) // 최대 일치
{
    fill(fail.begin(), fail.end(), 0);

    for (int i = 1, j = 0; i < word.size(); ++i)
    {
        while (j > 0 && word[i] != word[j])
        {
            j = fail[j - 1];
        }
        if (word[i] == word[j])
        {
            fail[i] = ++j;
            ret = max(ret, j);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string word;
    cin >> word;
    fail = vector<int>(word.size());
    failFunc(word);
    while (!word.empty())
    {
        word.erase(word.begin());
        failFunc(word);
    }
    cout << ret;
    return 0;
}