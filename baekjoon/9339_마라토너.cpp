#include <iostream>
#include <unordered_set>
using namespace std;

#define THRESHOLD 360

int T, K, N;
unordered_set<int> students;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        students.clear();
        cin >> K;

        while (K--)
        {
            int student;
            cin >> student;
            students.insert(student);
        }

        int count = 0;
        int minStudent;
        int minMin = THRESHOLD + 1;
        cin >> N;
        while (N--)
        {
            int person, hour, min;
            cin >> person >> hour >> min;

            if (hour == -1 || students.find(person) == students.end())
            {
                continue;
            }

            min += hour * 60;

            if (min > THRESHOLD)
            {
                continue;
            }

            ++count;

            if (min < minMin)
            {
                minStudent = person;
                minMin = min;
            }
        }

        cout << minStudent << " " << count << "\n";
    }
    return 0;
}