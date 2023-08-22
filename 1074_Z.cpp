#include <iostream>
using namespace std;
int N, r, c;
int recur(int startX, int endX, int startY, int endY, int depth)
{
    if (depth == -1)
        return 1;
    int midX = (startX + endX) >> 1;
    int midY = (startY + endY) >> 1;
    int val = 1 << depth;
    val *= val;
    int sum = 0;
    if (midX <= c || midY <= r)
    {
        sum = val;
        if (midY <= r)
        {
            sum += val;
            if (midX <= c)
            {
                sum += val;
                return sum += recur(midX, endX, midY, endY, depth - 1);
            }
            else
                return sum + recur(startX, midX, midY, endY, depth - 1);
        }
        else
            return sum + recur(midX, endX, startY, midY, depth - 1);
    }
    else
        return recur(startX, midX, startY, midY, depth - 1);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> r >> c;
    int end = 1 << N;
    cout << recur(0, end, 0, end, N - 1) - 1;
    return 0;
}