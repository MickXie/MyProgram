#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
namespace CompanyA
{
    void printMessage()
    {
        cout << "Welcome to Company A!" << endl;
    }
}
namespace CompanyB
{
    void printMessage()
    {
        cout << "Welcome to Company B!" << endl;
    }
}

int main()
{
    string choice;
    cout << "Enter company choice (A or B): ";
    cin >> choice;
    if (choice == "A")
    {
        using namespace CompanyA;
        printMessage();
    }
    else if (choice == "B")
    {
        using namespace CompanyB;
        printMessage();
    }
    system("pause");
    return 0;
}