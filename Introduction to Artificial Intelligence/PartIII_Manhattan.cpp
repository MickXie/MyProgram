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

int manhattan(const string &state)
{
    int n = sqrt(state.size());
    int dist = 0;
    for (int i = 0; i < (int)state.size(); i++)
    {
        char ch = state[i];
        if (ch == '0')
            continue;
        int val = hexDigitValue(ch);
        int tr = val / n;
        int tc = val % n;
        int cr = i / n;
        int cc = i % n;
        dist += abs(tr - cr) + abs(tc - cc);
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        string state;
        cin >> state;
        cout << manhattan(state);
        if (T > 0)
            cout << '\n';
    }
    return 0;
}
