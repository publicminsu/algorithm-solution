#include <iostream>
using namespace std;
int main()
{
    int N, K, answer = 0;
    string PH;
    cin >> N >> K >> PH;
    for (int idx = 0; idx < N; ++idx)
    {
        if (PH[idx] != 'P') // 사람이 아닌 경우
        {
            continue;
        }

        bool isFind = false;

        for (int len = K; len >= 1; --len)
        {
            if (idx - len < 0) // 범위를 벗어나면 무시
            {
                continue;
            }

            if (PH[idx - len] == 'H') // 햄버거일 경우 햄버거를 제거하고 개수 세어 주기
            {
                ++answer;
                isFind = true;
                PH[idx - len] = '.';
                break;
            }
        }

        if (!isFind) // 만약 이전에 찾지 못했다면
        {
            for (int len = 1; len <= K; ++len)
            {
                if (idx + len >= N) // 범위를 벗어나면 나가기
                {
                    break;
                }

                if (PH[idx + len] == 'H') // 햄버거일 경우 햄버거를 제거하고 개수 세어 주기
                {
                    ++answer;
                    PH[idx + len] = '.';
                    break;
                }
            }
        }
    }
    cout << answer;
    return 0;
}