#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

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

    int T;
    if (!(cin >> T))
        return 0;

    deque<Node> pq;
    int order = 0;
    while (T--)
    {
        string action;
        cin >> action;
        if (action == "enqueue")
        {
            string st;
            int g, h;
            cin >> st >> g >> h;
            Node node{st, g, h, order++};
            // keep sorted with minimum f then FIFO
            auto it = pq.begin();
            while (it != pq.end())
            {
                int fcur = it->g + it->h;
                int fnew = node.g + node.h;
                if (fnew < fcur)
                    break;
                if (fnew == fcur && it->order > node.order)
                    break;
                ++it;
            }
            pq.insert(it, node);
            cout << "Insert OK!";
        }
        else if (action == "dequeue")
        {
            if (pq.empty())
            {
                cout << "Queue is empty!!";
            }
            else
            {
                cout << "Got " << pq.front().state;
                pq.pop_front();
            }
        }
        if (T > 0)
            cout << '\n';
    }
    return 0;
}
