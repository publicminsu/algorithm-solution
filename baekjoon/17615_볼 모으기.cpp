#include <iostream>
#include <string>
using namespace std;
int N, i, j, blue, red, leftColor, rightColor;
string balls;
int main()
{
    cin >> N >> balls;
    j = balls.length() - 1;

    while (balls[i] == balls.front()) // 왼쪽 이어지는 부분 확인
    {
        ++i;
    }
    leftColor = i;

    while (i < j && balls[j] == balls.back()) // 오른쪽 이어지는 부분 확인
    {
        --j;
    }
    rightColor = balls.length() - j - 1;

    while (i <= j) // 남은 부분의 색깔 확인
    {
        if (balls[i++] == 'R')
        {
            ++red;
        }
        else
        {
            ++blue;
        }
    }

    if (balls.front() == balls.back()) // 앞과 뒤가 같다면
    {
        if (balls.front() == 'R') // 색깔을 모두 옮기기 vs 앞, 뒤 중 더 작게 옮기는 것과 중앙 색깔 옮기기
        {
            cout << min(blue, red + min(leftColor, rightColor));
        }
        else
        {
            cout << min(blue + min(leftColor, rightColor), red);
        }
    }
    else // 중앙 색깔을 더 작게 옮기는 경우
    {
        cout << min(red, blue);
    }
    return 0;
}