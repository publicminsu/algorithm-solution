#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
using tiiis = tuple<int, int, int, string>;
vector<tiiis> students;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        tiiis student;
        cin >> get<3>(student) >> get<0>(student) >> get<1>(student) >> get<2>(student);
        // 음수로 변환하여 감소하는 순으로 변경
        get<0>(student) *= -1;
        get<2>(student) *= -1;
        students.push_back(student);
    }
    sort(students.begin(), students.end());
    for (const tiiis &student : students)
    {
        cout << get<3>(student) << "\n";
    }
    return 0;
}