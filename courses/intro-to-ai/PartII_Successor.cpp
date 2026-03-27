#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<string, string>> successors(const string &state)
{
    int n = 4;
    int p = state.find('0');
    int r = p / n, c = p % n;
    vector<pair<string, string>> moves;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<string> names = {"up", "down", "left", "right"};
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dirs[i].first;
        int nc = c + dirs[i].second;
        if (nr >= 0 && nr < n && nc >= 0 && nc < n)
        {
            string next = state;
            swap(next[r * n + c], next[nr * n + nc]);
            moves.push_back({"move 0 to " + names[i], next});
        }
    }
    return moves;
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
        auto succ = successors(state);
        cout << succ.size() << '\n';
        for (auto &m : succ)
        {
            cout << m.first << '\n';
            cout << m.second << '\n';
        }
    }
    return 0;
}
