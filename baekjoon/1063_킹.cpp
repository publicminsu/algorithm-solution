#include <iostream>
using namespace std;
struct pos
{
    int x, y;
    const pos operator+(const pos &other) const
    {
        return {x + other.x, y + other.y};
    }
    const bool operator==(const pos &other) const
    {
        return (x == other.x) && (y == other.y);
    }
    const bool isOut() const
    {
        return y < 1 || y > 8 || x < 'A' || x > 'H';
    }
    void print()
    {
        cout << static_cast<char>(x) << y;
    }
} dir[] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

pos king, rock;
int N;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    char y;
    int x;
    cin >> y >> x;
    king = {y, x};
    cin >> y >> x;
    rock = {y, x};
    cin >> N;
}

void solve()
{
    string cmd;
    while (N--)
    {
        cin >> cmd;

        pos d = {0, 0};

        for (const char &c : cmd)
        {
            if (c == 'R')
            {
                d = d + dir[0];
            }
            else if (c == 'L')
            {
                d = d + dir[1];
            }
            else if (c == 'B')
            {
                d = d + dir[2];
            }
            else if (c == 'T')
            {
                d = d + dir[3];
            }
        }

        pos nextKing = king + d;

        if (nextKing.isOut())
        {
            continue;
        }

        if (nextKing == rock) // 돌과 같은 곳
        {
            pos nextRock = rock + d;
            if (nextRock.isOut())
            {
                continue;
            }

            rock = nextRock;
        }
        king = nextKing;
    }

    king.print();
    cout << "\n";
    rock.print();
}

int main()
{
    input();
    solve();
    return 0;
}