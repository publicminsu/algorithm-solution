#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<string> us;
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    while (N--)
    {
        string word;
        cin >> word;
        sort(word.begin(), word.end());
        us.insert(word);
    }
    cout << us.size();
}