#include <iostream>
using namespace std;
string word, ring;
int N, answer;
bool isFind(int i)
{
    for (int j = 0; j < word.size(); ++j)
    {
        if (ring[i + j] != word[j]) // 만약 다르다면
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> word >> N;
    while (N--)
    {
        cin >> ring;

        for (int i = 0; i < word.size() - 1; ++i) // 원의 형태로 이어진 경우 고려
        {
            ring.push_back(ring[i]);
        }

        for (int i = 0; i <= ring.size() - word.size(); ++i)
        {
            if (isFind(i)) // 일치하는 경우를 찾으면
            {
                ++answer;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}