#include <iostream>
#include <queue>
using namespace std;

#define SIZE 8

long map[SIZE][SIZE];
long buffer[SIZE][SIZE];
char cmd;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (auto &line : map)
    {
        for (auto &num : line)
        {
            cin >> num;
        }
    }

    cin >> cmd;
}

void rotateLeft()
{
    copy(&map[0][0], &map[0][0] + SIZE * SIZE, &buffer[0][0]);

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            map[SIZE - j - 1][i] = buffer[i][j];
        }
    }
}

void rotateRight()
{
    copy(&map[0][0], &map[0][0] + SIZE * SIZE, &buffer[0][0]);

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            map[j][SIZE - i - 1] = buffer[i][j];
        }
    }
}

int getRotateCount()
{
    switch (cmd)
    {
    case 'D':
        return 3;
    case 'R':
        return 2;
    case 'U':
        return 1;
    default:
        return 0;
    }
}

void move()
{
    for (int i = 0; i < SIZE; ++i)
    {
        queue<long> q;

        for (int j = 0; j < SIZE; ++j)
        {
            long &num = map[i][j];

            if (num == 0)
            {
                continue;
            }

            q.push(num);
            num = 0;
        }

        int j = 0;
        while (!q.empty())
        {
            long num = q.front();
            q.pop();

            if (!q.empty() && q.front() == num)
            {
                num *= 2;
                q.pop();
            }

            map[i][j] = num;
            ++j;
        }
    }
}

void print()
{
    for (const auto &line : map)
    {
        for (const auto &num : line)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
}

int main()
{
    input();

    int rotateCount = getRotateCount();

    for (int i = 0; i < rotateCount; ++i)
    {
        rotateLeft();
    }

    move();

    for (int i = 0; i < rotateCount; ++i)
    {
        rotateRight();
    }

    print();
    return 0;
}