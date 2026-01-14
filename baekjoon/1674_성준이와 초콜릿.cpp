#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct food
{
    string cmd;
    int T;
    double N;

    double distance(int t)
    {
        if (t < T)
        {
            return 0.0;
        }

        double value;
        double dt = t - T;
        if (cmd == "Chocolate")
        {
            value = 8.0 * N - dt / 12.0;
        }
        else
        {
            value = 2.0 * N - dt * dt / 79.0;
        }

        return max(value, 0.0);
    }
};

vector<food> foods;
vector<double> queries;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    cout.precision(1);

    queries.reserve(10000);
    foods.reserve(100);

    string cmd;

    while (cin >> cmd)
    {
        int T;
        cin >> T;

        if (cmd == "Query")
        {
            queries.push_back(T);
        }
        else
        {
            double N;
            cin >> N;
            foods.push_back({cmd, T, N});
        }
    }

    sort(queries.begin(), queries.end());

    for (int T : queries)
    {
        double R = 0.0;

        for (food f : foods)
        {
            R += f.distance(T);
        }

        if (R < 1.0)
        {
            R = 1.0;
        }

        cout << T << " " << R << "\n";
    }

    return 0;
}