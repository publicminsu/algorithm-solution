#include <iostream>
#include <vector>
using namespace std;
int N, answer = 987654321;
void dfs(const vector<char> &cards, const int &index, const int &count)
{
    if (count >= answer)
    {
        return;
    }

    if (index == N)
    {
        int score = 0;

        for (int i = 0; i < N; i += 2)
        {
            const char &myCard = cards[i];
            const char &otherCard = cards[i + 1];

            if (myCard == 'O' && otherCard == 'X')
            {
                ++score;
            }
            else if (myCard == 'X' && otherCard == 'O')
            {
                --score;
            }
        }

        if (score > 0)
        {
            answer = min(answer, count);
        }

        return;
    }

    for (int i = index; i < N; ++i)
    {
        vector<char> newCards = vector<char>(cards);
        int temp = newCards[i];

        for (int j = i; j >= 0; --j)
        {
            newCards[j] = newCards[j - 1];
        }

        newCards[0] = temp;

        dfs(newCards, index + 1, count + 1);
    }

    dfs(cards, index + 1, count);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    N *= 2;

    vector<char> cards = vector<char>(N);

    for (char &c : cards)
    {
        cin >> c;
    }

    dfs(cards, 1, 0);

    cout << answer;
    return 0;
}