#include <iostream>
using namespace std;

class Shallow
{
public:
    int *data;
    Shallow(int val)
    {
        data = new int(val);
    }
    ~Shallow()
    {
        delete data;
    }
    Shallow(const Shallow &other)
    {
        data = new int(*other.data);
    }
    Shallow &operator=(const Shallow &other)
    {
        if (this == &other)
            return *this;
        delete data;
        data = new int(*other.data);
        return *this;
    }
};

int main()
{
    Shallow a(5);
    Shallow b = a;
    cout << *a.data << endl;
    cout << *b.data << endl;
    return 0;
}