#include <iostream>
#include <algorithm>
using namespace std;

class rectangle
{
private:
    int width, height;

public:
    rectangle(int w = 0, int h = 0) : width(w), height(h) {}

    rectangle operator+(const rectangle &r)
    {
        if (height == r.height)
        {
            // 水平合併：寬度相加，高度不變
            return rectangle(width + r.width, height);
        }
        else if (width == r.width)
        {
            // 垂直合併：高度相加，寬度不變
            return rectangle(width, height + r.height);
        }
        else
        {
            // 無法合併，取最大寬度和最大高度
            return rectangle(max(width, r.width), max(height, r.height));
        }
    }

    rectangle operator=(const rectangle &r)
    {
        if (this != &r)
        {
            width = r.width;
            height = r.height;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const rectangle &r);
};

ostream &operator<<(ostream &os, const rectangle &r)
{
    for (int i = 0; i < r.height; i++)
    {
        for (int j = 0; j < r.width; j++)
        {
            os << "* ";
        }
        os << '\n';
    }
    return os;
}

int main()
{
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    rectangle r1(w1, h1), r2(w2, h2), r;
    r = r1 + r2;
    cout << r;
    return 0;
}