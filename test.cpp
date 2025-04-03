#include <iostream>
using namespace std;

class Point
{
public:
    double x, y;

    Point(double nx, double ny) : x(nx), y(ny)
    {
        cout << "2-parameter constructor"
             << endl;
    }
    Point(Point &p) : x(p.x), y(p.y)
    {
        cout << "3-parameter constructor"
             << endl;
    }
};

Point q(1.0, 2.0);
// 2-parameter constructor
Point r = q;

class Employee
{
private:
    string name;
    int empID;

public:
    Employee() = default;
    Employee(string n, int e) : name(n), empID(e) {}
    void displayInfo()
    {
        cout << "Employee ID: " << empID
             << endl;
        cout << "Name: " << name
             << endl;
    }
    ~Employee() = default;
};
int main()
{
    Employee e("Alice", 1);
    // Implicit conversion!!
    e.displayInfo();
    return 0;
}
#include <iostream>

class Car
{
private:
    static int speed_limit; // 所有 Car 共享同一个限速

public:
    int speed;

    Car(int s) : speed(s) {} // 使用初始化列表

    // 检查是否超速
    bool isOverSpeed() const
    { // const 表示不修改对象状态
        return speed > speed_limit;
    }

    // 静态方法设置限速（属于类，而不是对象）
    static void setSpeedLimit(int limit)
    {
        speed_limit = limit;
    }

    // 静态方法获取限速（可选）
    static int getSpeedLimit()
    {
        return speed_limit;
    }
};

int Car::speed_limit = 0; // 静态变量初始化

int main()
{
    int limit, speed1, speed2;
    std::cout << "Enter speed limit, speed of car 1, and speed of car 2: ";
    std::cin >> limit >> speed1 >> speed2;

    Car::setSpeedLimit(limit); // 直接通过类设置限速，而不是通过对象

    Car car1(speed1);
    Car car2(speed2);

    std::cout << "Car 1 exceeds speed limit: " << car1.isOverSpeed() << std::endl;
    std::cout << "Car 2 exceeds speed limit: " << car2.isOverSpeed() << std::endl;

    return 0;
}