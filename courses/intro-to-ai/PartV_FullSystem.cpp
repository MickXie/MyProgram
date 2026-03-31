#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

const string GOAL = "0123456789ABCDEF";

int hexVal(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    return 0;
}

bool isSolvable(const string &state)
{
    int n = 4;
    vector<int> tiles;
    int zeroRow = 0;
    for (int i = 0; i < 16; i++)
    {
        if (state[i] == '0') { zeroRow = i / n; continue; }
        tiles.push_back(hexVal(state[i]));
    }
    int inv = 0;
    for (int i = 0; i < (int)tiles.size(); i++)
        for (int j = i + 1; j < (int)tiles.size(); j++)
            if (tiles[i] > tiles[j]) inv++;
    return (inv + zeroRow) % 2 == 0;
}

int manhattan(const string &state)
{
    int n = 4, dist = 0;
    for (int i = 0; i < 16; i++)
    {
        if (state[i] == '0') continue;
        int d = hexVal(state[i]);
        dist += abs(d / n - i / n) + abs(d % n - i % n);
    }
    return dist;
}

struct Node
{
    string state;
    int g, f, seq;
    bool operator>(const Node &o) const
    {
        if (f != o.f) return f > o.f;
        return seq > o.seq; // FIFO tiebreaking
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string start;
    if (!(cin >> start)) return 0;

    if (start == GOAL)
    {
        cout << "It is the goal state." << '\n';
        return 0;
    }

    if (!isSolvable(start))
    {
        cout << "No solution!!" << '\n';
        return 0;
    }

    // A* search
    unordered_map<string, int> best; // best g value seen per state
    unordered_map<string, string> parent, act;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    int seq = 0;
    pq.push({start, 0, manhattan(start), seq++});
    best[start] = 0;
    parent[start] = "";
    act[start] = "";

    const int DR[] = {-1, 1, 0, 0};
    const int DC[] = {0, 0, -1, 1};
    const char *DIR[] = {"up", "down", "left", "right"};

    while (!pq.empty())
    {
        auto [state, g, f, s] = pq.top();
        pq.pop();

        if (best.count(state) && best[state] < g) continue;

        if (state == GOAL) break;

        int p = (int)state.find('0');
        int r = p / 4, c = p % 4;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + DR[i], nc = c + DC[i];
            if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
            string next = state;
            swap(next[p], next[nr * 4 + nc]);
            int ng = g + 1;
            if (!best.count(next) || best[next] > ng)
            {
                best[next] = ng;
                parent[next] = state;
                act[next] = string("move 0 to ") + DIR[i];
                pq.push({next, ng, ng + manhattan(next), seq++});
            }
        }
    }

    // Reconstruct path
    vector<string> moves;
    string cur = GOAL;
    while (cur != start)
    {
        moves.push_back(act[cur]);
        cur = parent[cur];
    }
    reverse(moves.begin(), moves.end());
    for (auto &m : moves)
        cout << m << '\n';

    return 0;
}
