#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Player = pair<string, int>;

struct Room
{
    vector<Player> players = vector<Player>();
};

vector<Room> rooms;

int p, m;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> p >> m;

    while (p--)
    {
        Player player = {};
        cin >> player.second >> player.first;

        bool isFind = false;

        for (Room &room : rooms)
        {
            if (room.players.size() == m)
            {
                continue;
            }

            if (abs(room.players.front().second - player.second) <= 10)
            {
                isFind = true;
                room.players.push_back(player);

                break;
            }
        }

        if (isFind)
        {
            continue;
        }

        rooms.push_back({});
        rooms.back().players.push_back(player);
    }

    for (Room room : rooms)
    {
        sort(room.players.begin(), room.players.end());

        if (room.players.size() == m)
        {
            cout << "Started!";
        }
        else
        {
            cout << "Waiting!";
        }
        cout << "\n";

        for (Player p : room.players)
        {
            cout << p.second << " " << p.first << "\n";
        }
    }
    return 0;
}