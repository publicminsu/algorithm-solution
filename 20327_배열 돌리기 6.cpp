#include <iostream>
#include <vector>
using namespace std;
int N, R, len, k, l;
vector<vector<int>> A, temp;

void cal(int k, int gap)
{
    for (int i = 0; i < len; i += gap)
        for (int j = 0; j < len; j += gap)
            for (int y = 0; y < gap; ++y)
                for (int x = 0; x < gap; ++x)
                {
                    switch (k)
                    {
                    case 1:
                        temp[i + gap - 1 - y][j + x] = A[i + y][j + x];
                        break;
                    case 2:
                        temp[i + y][j + gap - 1 - x] = A[i + y][j + x];
                        break;
                    case 3:
                        temp[i + x][j + gap - 1 - y] = A[i + y][j + x];
                        break;
                    case 4:
                        temp[i + gap - 1 - x][j + y] = A[i + y][j + x];
                        break;
                    case 5:
                        temp[len - gap - i + y][j + x] = A[i + y][j + x];
                        break;
                    case 6:
                        temp[i + y][len - gap - j + x] = A[i + y][j + x];
                        break;
                    case 7:
                        temp[j + y][len - gap - i + x] = A[i + y][j + x];
                        break;
                    case 8:
                        temp[len - gap - j + y][i + x] = A[i + y][j + x];
                        break;
                    }
                }
    A = temp;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> R;
    len = 1 << N;
    A = temp = vector<vector<int>>(len, vector<int>(len));
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            cin >> A[i][j];
    while (R--)
    {
        cin >> k >> l;
        int gap = 1 << l;
        cal(k, gap);
    }
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
            cout << A[i][j] << " ";
        cout << "\n";
    }
    return 0;
}