#include <iostream>
using namespace std;

int angles[3];
int sameCnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 3; ++i)
    {
        cin >> angles[i];
        sameCnt += angles[i] == angles[0];
    }

    if (angles[0] == 60 && sameCnt == 3)
    {
        cout << "Equilateral";
    }
    else
    {
        int sum = 0;

        for (int angle : angles)
        {
            sum += angle;
        }

        if (sum == 180)
        {
            if (angles[0] != angles[1] && angles[1] != angles[2] && angles[0] != angles[2])
            {
                cout << "Scalene";
            }
            else
            {
                cout << "Isosceles";
            }
        }
        else
        {
            cout << "Error";
        }
    }

    return 0;
}