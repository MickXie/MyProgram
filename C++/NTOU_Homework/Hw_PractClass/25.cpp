#include <iostream>
#include <exception>
using namespace std;

// 自訂例外類別，使用舊版 throw() 規格
class InvalidDate : public std::exception
{
    const char *msg;

public:
    InvalidDate(const char *message) : msg(message) {}

    virtual const char *what() const throw()
    {
        return msg;
    }
};
class a : public std::exception
{
private:
    char x;

public:
    virtual char *what() const noexcept override
    {
        return "";
    }
};
class Date
{
private:
    int day, month, year;

    bool isLeap(int y) const
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:
    Date(int d, int m, int y)
    {
        if (y < 1900 || y > 2100)
            throw InvalidDate("[Out of range]Year must be between 1900 and 2100");
        if (m < 1 || m > 12)
            throw InvalidDate("Invalid month");

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31};

        if (m == 2 && isLeap(y))
            daysInMonth[2] = 29;

        if (d < 1 || d > daysInMonth[m])
            throw InvalidDate("Invalid day for the given month/year");
        throw a();
        day = d;
        month = m;
        year = y;
    }

    void print() const
    {
        cout << day << '/' << month << '/' << year << endl;
    }
};
int main()
{
    int d, m, y;
    cin >> d >> m >> y;
    try
    {
        Date dt(d, m, y);

        dt.print();
    }
    catch (const InvalidDate &e)
    {
        cout << "Date error: " << e.what() << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Other error: " << e.what() << endl;
    }
    catch (const a &e)
    {

        cout << "eeeeee error: " << e.what() << endl;
    }
    return 0;
}