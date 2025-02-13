#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct point
{
    float y, x;

    void input()
    {
        cin >> y >> x;
    }
};

int N, answer;
point a, b, c, temp;

float calcSize(point p1, point p2, point p3)
{
    return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2);
}

int main()
{
    cout << fixed;
    cout.precision(1);

    a.input();
    b.input();
    c.input();

    cin >> N;

    float size = calcSize(a, b, c);

    while (N--)
    {
        temp.input();
        float sum = calcSize(a, b, temp) + calcSize(a, c, temp) + calcSize(b, c, temp);

        if (sum == size)
        {
            ++answer;
        }
    }

    cout << size << "\n"
         << answer;
    return 0;
}