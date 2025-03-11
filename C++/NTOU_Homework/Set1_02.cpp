#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class student
{
private:
    int studentID;
    string name;
    float eng, math, phy;
    float avg(void)
    {
        return (eng + math + phy) / 3.0f;
    }

public:
    void Takedata(void)
    {
        cout << "In Takedata()" << endl;
        cout << "Enter studentID: ";
        cin >> studentID;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter in English, Math, and Physics: ";
        cin >> eng >> math >> phy;
        avg();
    }

    void Showdata(void)
    {
        cout << "In Showdata()" << endl;
        cout << "StudentID: " << studentID << endl;
        cout << "Student Name: " << name << endl;
        cout << "English: " << eng << endl;
        cout << "Math: " << math << endl;
        cout << "Physics: " << phy << endl;
    }

    void PassOrFail(void)
    {
        if (avg() >= 60.0f)
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }
};

int main()
{
    student obj;
    obj.Takedata();
    obj.Showdata();
    obj.PassOrFail();
    system("pause");
    return 0;
}