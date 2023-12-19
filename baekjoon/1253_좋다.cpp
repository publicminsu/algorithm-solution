#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int> A;
unordered_set<int> used;
int N, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    A = vector<int>(N);

    for (int &i : A)
    {
        cin >> i;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            int good = A[i] + A[j];

            if (used.find(good) != used.end()) // 이미 사용한 GOOD이면
            {
                continue;
            }
            auto end = upper_bound(A.begin(), A.end(), good);
            auto start = lower_bound(A.begin(), A.end(), good);

            if (end - start == 1) // 길이가 1이고
            {
                if ((A[i] == 0 && A[j] == good) || (A[j] == 0 && A[i] == good)) // 하나는 0이고 나머지 하나는 합과 같다면
                {
                    continue;
                }
            }
            else if (end - start == 2 && A[i] == 0 && A[j] == 0) // 길이가 2이고 모두 0이라면
            {
                continue;
            }

            used.insert(good);

            answer += end - start;
        }
    }
    cout << answer;
    return 0;
}