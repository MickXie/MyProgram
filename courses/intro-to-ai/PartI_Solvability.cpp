#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int hexDigitValue(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    if (c >= 'a' && c <= 'f')
        return 10 + (c - 'a');
    return 0;
}

bool isSolvable(const string &state)
{
    int n = sqrt(state.size());
    vector<int> tiles;
    int zeroRow = -1;
    for (int i = 0; i < (int)state.size(); i++)
    {
        if (state[i] == '0')
        {
            zeroRow = i / n;
            continue;
        }
        tiles.push_back(hexDigitValue(state[i]));
    }
    int inv = 0;
    for (int i = 0; i < (int)tiles.size(); i++)
    {
        for (int j = i + 1; j < (int)tiles.size(); j++)
        {
            if (tiles[i] > tiles[j])
                inv++;
        }
    }
    if (n % 2 == 1)
    {
        return inv % 2 == 0;
    }
    else
    {
        return (inv + zeroRow) % 2 == 0;
    }
}

int main()
{
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        string state;
        cin >> state;
        cout << (isSolvable(state) ? "YES" : "NO") << '\n';
    }
    return 0;
}