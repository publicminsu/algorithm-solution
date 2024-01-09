#include <iostream>
using namespace std;
int T;
string S, X;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> S;
        X = S;
        int startIdx = 0;
        while (true)
        {
            bool isSame = true;
            for (int i = 0; i + startIdx < S.size(); ++i)
            {
                if (S[i + startIdx] != S[S.size() - i - 1]) // 뒤의 값과 다르다면
                {
                    ++startIdx;
                    isSame = false;
                    break;
                }
            }
            if (isSame)
            {
                break;
            }
        }
        for (int i = startIdx - 1; i >= 0; --i) // 같은 부분이 아닌 곳부터 역순으로 X에 집어넣기
        {
            X.push_back(S[i]);
        }
        cout << X << "\n";
    }
    return 0;
}