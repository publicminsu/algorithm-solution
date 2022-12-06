#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct word
{
    int index;     // 인덱스
    string word;   // 암호
    int vowel;     // 모음
    int consonant; // 자음
};
bool isVowel(char c) // 모음인지 확인해주는 함수
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> cV;
    vector<string> answer;
    queue<word> q;
    int L, C;
    cin >> L >> C;
    for (int i = 0; i < C; ++i)
    {
        char c;
        cin >> c;
        cV.push_back(c);
    }
    sort(cV.begin(), cV.end());
    q.push({0, "", 0, 0});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (cur.index > C)
            continue;
        if (cur.word.length() == L && cur.vowel && cur.consonant >= 2)
        {
            answer.push_back(cur.word);
            continue;
        }
        q.push({cur.index + 1, cur.word, cur.vowel, cur.consonant});
        if (isVowel(cV[cur.index])) // 모음인지 확인
            cur.vowel += 1;
        else // 자음인 경우
            cur.consonant += 1;
        q.push({cur.index + 1, cur.word + cV[cur.index], cur.vowel, cur.consonant});
    }
    sort(answer.begin(), answer.end());
    for (string a : answer)
    {
        cout << a << '\n';
    }
    return 0;
}