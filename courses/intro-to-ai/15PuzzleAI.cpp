#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
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
    return -1;
}

bool isSolvable(const string &state)
{
    int n = 4;
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

vector<pair<string, string>> successors(const string &state)
{
    int n = 4;
    int p = state.find('0');
    int r = p / n, c = p % n;
    vector<pair<string, string>> out;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<string> name = {"up", "down", "left", "right"};
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dirs[i].first;
        int nc = c + dirs[i].second;
        if (nr >= 0 && nr < n && nc >= 0 && nc < n)
        {
            string s = state;
            swap(s[r * n + c], s[nr * n + nc]);
            out.push_back({"move 0 to " + name[i], s});
        }
    }
    return out;
}

int manhattan(const string &state)
{
    int n = 4;
    int dist = 0;
    for (int i = 0; i < (int)state.size(); i++)
    {
        char ch = state[i];
        if (ch == '0')
            continue;
        int d = hexDigitValue(ch);
        int goalR = d / n;
        int goalC = d % n;
        int curR = i / n;
        int curC = i % n;
        dist += abs(goalR - curR) + abs(goalC - curC);
    }
    return dist;
}

struct Node
{
    string state;
    int g, h;
    int order;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string part;
    if (!(cin >> part))
        return 0;

    // detect mode
    if (part == "1" || part == "I" || part == "Part1" || part == "PartI")
    {
        int T;
        cin >> T;
        while (T--)
        {
            string s;
            cin >> s;
            cout << (isSolvable(s) ? "YES" : "NO") << '\n';
        }
        return 0;
    }
    if (part == "2" || part == "II" || part == "Part2" || part == "PartII")
    {
        int T;
        cin >> T;
        while (T--)
        {
            string s;
            cin >> s;
            auto succ = successors(s);
            cout << succ.size() << '\n';
            for (auto &pr : succ)
            {
                cout << pr.first << '\n';
                cout << pr.second << '\n';
            }
        }
        return 0;
    }
    if (part == "3" || part == "III" || part == "Part3" || part == "PartIII")
    {
        int T;
        cin >> T;
        while (T--)
        {
            string s;
            cin >> s;
            cout << manhattan(s) << '\n';
        }
        return 0;
    }
    if (part == "4" || part == "IV" || part == "Part4" || part == "PartIV")
    {
        int T;
        cin >> T;
        deque<Node> pq;
        int order = 0;
        string action;
        while (T--)
        {
            cin >> action;
            if (action == "enqueue")
            {
                string state;
                int g, h;
                cin >> state >> g >> h;
                Node n{state, g, h, order++};
                auto it = pq.begin();
                while (it != pq.end())
                {
                    int f1 = it->g + it->h;
                    int f2 = n.g + n.h;
                    if (f2 < f1)
                        break;
                    if (f2 == f1 && it->order > n.order)
                        break;
                    ++it;
                }
                pq.insert(it, n);
                cout << "Insert OK!" << '\n';
            }
            else if (action == "dequeue")
            {
                if (pq.empty())
                {
                    cout << "Queue is empty!!" << '\n';
                }
                else
                {
                    auto node = pq.front();
                    pq.pop_front();
                    cout << "Got " << node.state << '\n';
                }
            }
        }
        return 0;
    }

    // fallback: first token is test count (assume part I by default)
    int T;
    try
    {
        T = stoi(part);
    }
    catch (...)
    {
        return 0;
    }
    vector<string> lines;
    string s;
    while (cin >> s)
        lines.push_back(s);
    bool hasQueueCmd = false;
    for (auto &x : lines)
        if (x == "enqueue" || x == "dequeue")
            hasQueueCmd = true;

    if (hasQueueCmd)
    {
        // use part4 logic
        deque<Node> pq;
        int order = 0;
        int idx = 0;
        for (int i = 0; i < T; i++)
        {
            if (idx >= lines.size())
                break;
            string action2 = lines[idx++];
            if (action2 == "enqueue" && idx + 2 < lines.size())
            {
                string state = lines[idx++];
                int g = stoi(lines[idx++]);
                int h = stoi(lines[idx++]);
                Node n{state, g, h, order++};
                auto it = pq.begin();
                while (it != pq.end())
                {
                    int f1 = it->g + it->h;
                    int f2 = n.g + n.h;
                    if (f2 < f1)
                        break;
                    if (f2 == f1 && it->order > n.order)
                        break;
                    ++it;
                }
                pq.insert(it, n);
                cout << "Insert OK!" << '\n';
            }
            else if (action2 == "dequeue")
            {
                if (pq.empty())
                    cout << "Queue is empty!!" << '\n';
                else
                {
                    cout << "Got " << pq.front().state << '\n';
                    pq.pop_front();
                }
            }
        }
    }
    else
    {
        // Assume part1 by default if not clearly part2/3.
        for (int i = 0; i < T && i < (int)lines.size(); i++)
        {
            cout << (isSolvable(lines[i]) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
