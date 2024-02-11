#include <iostream>
using namespace std;
float sum;
float creditSum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    string name, grade;
    float credit;
    float gradeNum;
    for (int i = 0; i < 20; ++i)
    {
        cin >> name >> credit >> grade;
        if (grade[0] < 'A' || grade[0] > 'D') // A와 D가 아닌 경우
        {
            if (grade[0] == 'F') // F인 경우
            {
                creditSum += credit;
            }
            continue;
        }
        gradeNum = 4 - (grade[0] - 'A');
        if (grade[1] == '+') //+인 경우
        {
            gradeNum += 0.5f;
        }
        creditSum += credit;
        sum += credit * gradeNum;
    }
    cout << (sum / creditSum);
    return 0;
}