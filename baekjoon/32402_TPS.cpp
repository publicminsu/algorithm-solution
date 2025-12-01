#include <iostream>

using namespace std;

int N;
string cmd;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int y, x, cameraDir;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> cmd;

        if (cmd == "MR")
        {
            cameraDir = (cameraDir + 1) % 4;
        }
        else if (cmd == "ML")
        {
            cameraDir = (cameraDir + 3) % 4;
        }
        else if (cmd == "W")
        {
            int moveDir = (cameraDir + 2) % 4;
            y += dy[moveDir];
            x += dx[moveDir];
        }
        else if (cmd == "A")
        {
            int moveDir = (cameraDir + 1) % 4;
            y += dy[moveDir];
            x += dx[moveDir];
        }
        else if (cmd == "S")
        {
            int moveDir = cameraDir;
            y += dy[moveDir];
            x += dx[moveDir];
        }
        else if (cmd == "D")
        {
            int moveDir = (cameraDir + 3) % 4;
            y += dy[moveDir];
            x += dx[moveDir];
        }

        int cameraY = y + dy[cameraDir];
        int cameraX = x + dx[cameraDir];

        cout << x << " " << y << " " << cameraX << " " << cameraY << "\n";
    }
    return 0;
}