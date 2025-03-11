#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class BOOK
{
private:
    int BOOK_NO;
    string TITLE;
    float PRICE;
    float TOTAL_COST(int N)
    {
        return PRICE * N;
    }

public:
    void INPUT();
    void PURCHASE();
};

void BOOK::INPUT()
{
    cout << "In INPUT()" << endl;
    cout << "Enter Book Title: ";
    string line;
    getline(cin, line);
    TITLE = line.substr(0, 20);
    cout << "Enter Book Number: ";
    cin >> BOOK_NO;
    cin.ignore();
    cout << "Enter price per copy: ";
    cin >> PRICE;
    cin.ignore();
}

void BOOK::PURCHASE()
{
    cout << "In PURCHASE()" << endl;
    cout << "Enter number of copies to purchase: ";
    int N;
    cin >> N;
    float total = TOTAL_COST(N);
    cout << "TOTAL cost: " << total << endl;
}
int main()
{
    BOOK obj;
    obj.INPUT();
    obj.PURCHASE();
    system("pause");
    return 0;
}
