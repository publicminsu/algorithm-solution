#include <iostream>
#include <vector>
using namespace std;
int N, P, Q;
vector<int> A, B, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> P >> Q;
    A = B = vector<int>(N);

    for (int &a : A)
    {
        cin >> a;
    }

    for (int &b : B)
    {
        cin >> b;
    }

    for (int i = 0, j; i < N; ++i)
    {
        int &a = A[i];
        int &b = B[i];
        j = 0;

        while (a != b)
        {
            a += P;
            b += Q;
            ++j;

            if (j == 10000)
            {
                cout << "NO";
                return 0;
            }
        }

        answer.push_back(j);
    }

    cout << "YES" << "\n";

    for (const int &i : answer)
    {
        cout << i << " ";
    }
    return 0;
}