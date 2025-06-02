#ifndef HOMEWORK_H
#define HOMEWORK_H
#include <iostream>
#include <iomanip>
using namespace std;
namespace Homework1
{
    struct datainput
    {
        double x, y, z;
    };
    class shape
    {
    public:
        shape() = default;
        shape(double x, double y) : width(x), height(y) {}
        virtual ~shape() {}
        virtual double area()
        {
            return 0.0;
        } // pure virtual function
    protected:
        double getw()
        {
            return width;
        }
        double geth()
        {
            return height;
        } // coordinates of the shape
    private:
        double width, height; // coordinates of the shape
    };
    class rectangle : public shape
    {
    public:
        rectangle(double w, double h) : shape(w, h) {}
        double area() override
        {
            return getw() * geth();
        }
    };
    class triangle : public shape
    {
    public:
        triangle(double w, double h) : shape(w, h) {}
        double area() override
        {
            return getw() * geth() * 0.5;
        }
    }; // forward declaration
}
namespace Homework2
{
    class Clock
    {
    private:
        int hour, minute, second;

    public:
        Clock() = default;
        Clock(double h, double m, double s) : hour(h), minute(m), second(s) {}
        Clock(Clock &x) : hour(x.hour), minute(x.minute), second(x.second) {}
        void showtime()
        {
            cout << hour << ":"
                 << setw(2) << setfill('0') << minute << ":"
                 << setw(2) << setfill('0') << second << endl;
        }
        void tick()
        {
            second++;
            if (second >= 60)
            {
                minute += static_cast<int>(second / 60);
                second = static_cast<int>(second) % 60;
            }
            if (minute >= 60)
            {
                hour += static_cast<int>(minute / 60);
                minute = static_cast<int>(minute) % 60;
            }
            hour = hour % 24;
        }
    };
}
namespace Homework3
{
    class Animal
    {
    public:
        Animal() = default;
        virtual void makeSound()
        {
            cout << " Animal makes a sound " << endl;
        }
        virtual ~Animal() {}
    };
    class Dog : public Animal
    {
    public:
        void makeSound() override
        {
            cout << " Dog barks " << endl;
        }
        ~Dog() {}
    };
    class Cat : public Animal
    {
    public:
        void makeSound() override
        {
            cout << " Cat meows " << endl;
        }
        ~Cat() {}
    };
}
namespace Homework4
{
    class Vehicle
    {
    private:
        double vehiclePrice;

    public:
        Vehicle() = default;
        Vehicle(double price) : vehiclePrice(price) {}
        virtual ~Vehicle() {}
        double get_v_price() { return vehiclePrice; }
    };
    class FourWheeler
    {
    private:
        double wheelsPrice;

    public:
        FourWheeler() = default;
        FourWheeler(double price) : wheelsPrice(price) {}
        double get_w_price() { return wheelsPrice; }
        virtual ~FourWheeler() {}
    };
    class Car : public Vehicle, public FourWheeler
    {
    private:
        double carPrice;

    public:
        Car() = default;
        Car(double v_price, double w_price, double c_price) : Vehicle(v_price), FourWheeler(w_price), carPrice(c_price) {}
        ~Car() {}
        double totalCost()
        {
            return get_v_price() + get_w_price() + carPrice;
        };
    };

}
namespace Homework5
{
    class car
    {
    private:
        static int speed_limit;

    public:
        int speed;
        car() = default;
        car(int s) : speed(s) {}
        ~car() {}
        int checkSpeed()
        {
            cout << (speed > speed_limit ? 1 : 0) << endl;
        }
        static void getLimit(int lt)
        {
            speed_limit = lt;
        }
    };
}
int Homework5::car::speed_limit = 0;
namespace Homework6
{
    class Employees
    {
    private:
        string name;
        int empID;

    public:
        Employees() = default;
        Employees(string n, int id) : name(n), empID(id) {}
        virtual ~Employees() {}
        virtual void displayInfo() = 0;
        virtual double calculateSalary() = 0;

    protected:
        string getName() { return name; }
        int getID() { return empID; }
    };
    class FullTimeEmployee : public Employees
    {
    private:
        double monthlySalary;

    public:
        FullTimeEmployee(string n, int id, double salary) : Employees(n, id), monthlySalary(salary) {}
        ~FullTimeEmployee() {}
        double calculateSalary() override
        {
            return monthlySalary;
        }
        void displayInfo() override
        {
            cout << "Employee ID: " << getID() << endl;
            cout << "Name: " << getName() << endl;
            cout << "Type: Full-Time Employee" << endl;
            cout << "Salary: $" << calculateSalary() << endl;
        }
    };
    class PartTimeEmployee : public Employees
    {
    private:
        double hourlyWage;
        int hoursWorked;

    public:
        PartTimeEmployee(string n, int id, double hl, double hs) : Employees(n, id), hourlyWage(hl), hoursWorked(hs) {}
        double calculateSalary() override
        {
            return hourlyWage * hoursWorked;
        }
        void displayInfo() override
        {
            cout << "Employee ID: " << getID() << endl;
            cout << "Name: " << getName() << endl;
            cout << "Type: Part-Time Employee" << endl;
            cout << "Salary: $" << calculateSalary() << endl;
        }
    };
}
namespace Homework7
{
    class Vector
    {
    private:
        double x, y;

    public:
        // 建構函數
        Vector(double x = 0, double y = 0) : x(x), y(y) {}

        // 重載 + 運算子（成員函數形式）
        Vector operator+(const Vector &other) const
        {
            return Vector(x + other.x, y + other.y);
        }

        // 重載 - 運算子
        Vector operator-(const Vector &other) const
        {
            return Vector(x - other.x, y - other.y);
        }

        // 重載 * 運算子（向量點積）
        double operator*(const Vector &other) const
        {
            return x * other.x + y * other.y;
        }

        // 重載 = 運算子
        Vector &operator=(const Vector &other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        // 重載 == 運算子
        bool operator==(const Vector &other) const
        {
            return (x == other.x) && (y == other.y);
        }

        // 重載 << 運算子（必須是非成員函數）
        friend ostream &operator<<(ostream &os, const Vector &v)
        {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }
    };

}
#endif