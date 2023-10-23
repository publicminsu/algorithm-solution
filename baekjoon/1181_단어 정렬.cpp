#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<string> words;
bool comp(const string &word1, const string &word2) // 정렬 기준
{
    if (word1.size() < word2.size())
        return true;
    else if (word1.size() > word2.size())
        return false;
    return word1 < word2; // 길이가 같은 경우
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    words = vector<string>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> words[i];
    }

    sort(words.begin(), words.end(), comp); // 정렬

    words.erase(unique(words.begin(), words.end()), words.end()); // 증복 제거

    for (string word : words)
    {
        cout << word << "\n";
    }
    return 0;
}