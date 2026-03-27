#include <iostream>
#include <string>
using namespace std;

template <typename T>
class node
{
public:
    T v;
    node<T> *next;
    node(T x) : v(x), next(nullptr) {}
};

template <typename T>
class queue
{
    node<T> *start;
    node<T> *end;

public:
    queue() : start(nullptr), end(nullptr) {}

    bool empty()
    {
        return start == nullptr;
    }

    void safe_push(T v)
    {
        // 檢查元素是否已存在
        node<T> *current = start;
        while (current != nullptr)
        {
            if (current->v == v)
                return; // 元素已存在，不添加
            current = current->next;
        }

        // 添加新元素
        node<T> *new_node = new node<T>(v);
        if (end == nullptr)
        {
            start = end = new_node;
        }
        else
        {
            end->next = new_node;
            end = new_node;
        }
    }

    T front()
    {
        return start->v;
    }

    void pop()
    {
        if (start != nullptr)
        {
            node<T> *temp = start;
            start = start->next;
            if (start == nullptr)
                end = nullptr;
            delete temp;
        }
    }
};

// 主函数保持不变
int main()
{
    ::queue<string> q;
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    q.safe_push(s1);
    q.safe_push(s2);
    q.safe_push(s3);
    q.safe_push(s4);
    q.pop();
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}