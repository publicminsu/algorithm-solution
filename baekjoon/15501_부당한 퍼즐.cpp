#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> seq1, seq2;

void initSeq(vector<int> &seq)
{
    seq = vector<int>(n);

    for (int &i : seq)
    {
        cin >> i;
    }
}

bool isGoodPuzzle()
{
    int index = 0;

    while (true)
    {
        if (seq1[0] == seq2[index])
        {
            break;
        }

        ++index;
    }

    if (seq1[1] == seq2[(index + 1) % n])
    {
        for (int i = 2; i < n; ++i)
        {
            if (seq1[i] != seq2[(index + i) % n])
            {
                return false;
            }
        }

        return true;
    }
    else if (seq1[n - 1] == seq2[(index + 1) % n])
    {
        for (int i = 2; i < n; ++i)
        {
            if (seq1[n - i] != seq2[(index + i) % n])
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    initSeq(seq1);
    initSeq(seq2);

    cout << (isGoodPuzzle() ? "good puzzle" : "bad puzzle");
    return 0;
}