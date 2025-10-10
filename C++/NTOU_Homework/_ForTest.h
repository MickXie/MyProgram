#ifndef _FORTEST_H
#define _FORTEST_H
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
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
namespace Homework8
{
    template <typename T>
    class Box
    {
    private:
        T content;

    public:
        void set(T value) { content = value; }
        T get() { return content; }
    };
}
namespace Homework9
{
    template <typename T>
    void print_max(T *a, int &b)
    {
        for (int i = 0; i < b - 1; i++)
        {
            for (int j = 0; j < b - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                }
            }
        }
        cout << "The maximum value is: " << a[b - 1] << endl;
    }
}
namespace Homework10
{
    struct Node
    {
        int data;
        int order; // the order of generation
        Node *next;
        static int counter;

        // Constructor
        Node()
        {
            data = rand() % 100; // assign random number to data
            order = counter++;   // use static counter to track generation order
            next = nullptr;
        }

        // Destructor
        ~Node()
        {
            // cout << "Destroying Node with order: " << order << endl;
        }

        // Overload '<' operator
        bool operator<(Node &other)
        {
            return this->data < other.data;
        }

        // Overload '<<' operator (friend function)
        friend ostream &operator<<(ostream &os, const Node &node)
        {
            os << "(" << node.data << ", order=" << node.order << ")";
            return os;
        }
    };

    int Node::counter = 0; // initialize static counter

    // Template Bubble Sort
    template <class T>
    void bubbleSort(T a[], int n)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = n - 1; i < j; j--)
                if (a[j] < a[j - 1])
                    swap(a[j], a[j - 1]);
    }
}
namespace homework11
{
    struct SolType
    {
        int index1;
        int index2;
        SolType(int i1, int i2) : index1(i1), index2(i2) {}
        friend ostream &operator<<(ostream &os, const SolType &st)
        {
            if (st.index2 == 1)
            {
                os << "[" << st.index1 + 1 << ",";
            }
            else
            {
                os << st.index1 + 1 << "]";
            }

            return os;
        }
    };
    template <typename T>
    class Solution
    {
    private:
        vector<SolType> sol;
        void bubbleSort(vector<T> &a)
        {
            int n = a.end() - a.begin();
            for (int i = 0; i < n - 1; i++)
                for (int j = n - 1; i < j; j--)
                    if (a[j] < a[j - 1])
                        swap(a[j], a[j - 1]);
        }
        void FindTwoSum(vector<T> &num, T target)
        {
            bubbleSort(num);
            unordered_map<T, int> n2;
            for (auto n1 = num.begin(); n1 != num.end(); ++n1)
            {
                if (n2.find(target - *n1) != n2.end())
                {
                    sol.emplace_back(n2[target - *n1], 1);
                    sol.emplace_back(n1 - num.begin(), 2);
                    break;
                }
                else
                {
                    n2.insert({*n1, n1 - num.begin()});
                }
            }
            if (sol.empty())
            {
                cout << "No solution found." << endl;
            }
            else if (sol.size() == 2)
            {
                for (const auto &s : sol)
                {
                    cout << s;
                }
            }
        }

    public:
        Solution() = default;
        Solution(vector<T> &num, T target)
        {
            FindTwoSum(num, target);
        }
        ~Solution() {}
    };
}
namespace Homework12
{
    class Solution
    {
    public:
        vector<vector<int>> threeSum(vector<int> &nums)
        {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            int n = nums.size();

            for (int i = 0; i < n - 2; ++i)
            {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue; // skip duplicates
                int left = i + 1;
                int right = n - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == 0)
                    {
                        result.push_back({nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++; // skip duplicates
                        while (left < right && nums[right] == nums[right - 1])
                            right--; // skip duplicates
                        left++;
                        right--;
                    }
                    else if (sum < 0)
                        left++;
                    else
                        right--;
                }
            }

            return result;
        }
    };
}
namespace Homework13
{
    enum class suit : short
    {
        SPADE,
        HEART,
        DIAMOND,
        CLUB
    };

    class pips
    {
    public:
        pips(int val) : v(val) { assert(v > 0 && v < 14); } // 點數
        friend ostream &operator<<(ostream &out, const pips &p);
        int get_pips() { return v; }

    private:
        int v;
    };

    class card
    {
    public:
        card() : s(suit::SPADE), v(1) {}
        card(suit st, pips pv) : s(st), v(pv) {}
        friend ostream &operator<<(ostream &out, const card &c);
        suit get_suit() { return s; }
        pips get_pips() { return v; }

    private:
        suit s;
        pips v;
    };

    ostream &operator<<(ostream &os, const suit &s)
    {
        os << static_cast<std::underlying_type<suit>::type>(s);
        return os;
    }

    ostream &operator<<(ostream &os, const pips &p)
    {
        os << p.v;
        return os;
    }

    ostream &operator<<(ostream &os, const card &c)
    {
        os << c.v << c.s;
        return os;
    }

    void init_deck(vector<card> &d)
    {
        int i;
        for (i = 1; i < 14; i++)
        {
            card c(suit::SPADE, i);
            d[i - 1] = c;
            // cout << i << " ";
        }
        // cout << endl;
        for (i = 1; i < 14; i++)
        {
            card c(suit::HEART, i);
            d[i + 12] = c;
            // cout << i << " ";
        }
        // cout << endl;
        for (i = 1; i < 14; i++)
        {
            card c(suit::DIAMOND, i);
            d[i + 25] = c;
            // cout << i << " ";
        }
        // cout << endl;
        for (i = 1; i < 14; i++)
        {
            card c(suit::CLUB, i);
            d[i + 38] = c;
            // cout << i << " ";
        }
        // cout << endl;
    }

    void print(vector<card> &deck)
    {
        for (auto p = deck.begin(); p != deck.end(); ++p)
        { // for (auto card_val: deck) cout << card_val
            cout << *p;
        }
        cout << endl;
    }

    bool is_flush(vector<card> &hand)
    {
        suit s = hand[0].get_suit();
        for (auto p = hand.begin(); p != hand.end(); ++p)
        {
            if (s != p->get_suit())
            {
                return false;
            }
        }
        return true;
    }

    bool is_straight(vector<card> &hand)
    {
        int pips_v[5];
        int i = 0;
        for (auto p = hand.begin(); p != hand.end(); ++p)
        {
            pips_v[i++] = (p->get_pips()).get_pips();
        }
        sort(pips_v, pips_v + 5); // feed the range for the iterator
        if (pips_v[0] != 1)
        { // not ACE
            return (pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1);
        }
        else
        {
            return (pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1) || (pips_v[1] == 10) && (pips_v[2] == 11) && (pips_v[3] == 12) && (pips_v[4] == 13);
        }
    }

    bool is_straight_flush(vector<card> &hand)
    {
        return is_flush(hand) && is_straight(hand);
    }

    int main()
    {
        vector<card> deck(52);
        srand(time(0));
        init_deck(deck);
        int num_shuffles;
        int flush_count = 0;
        int str_count = 0;
        int str_flush_count = 0;
        cout << "How many shuffles? ";
        cin >> num_shuffles;
        for (int loop = 0; loop < num_shuffles; ++loop)
        {
            random_shuffle(deck.begin(), deck.end()); // STL algorithm again!
            vector<card> hand(5);
            int i = 0;
            for (auto p = deck.begin(); i < 5; ++p)
            {
                hand[i++] = *p;
            }
            if (is_flush(hand))
            {
                flush_count++;
            }
            if (is_straight(hand))
            {
                str_count++;
            }
            if (is_straight_flush(hand))
            {
                str_flush_count++;
            }
        }
        cout << "Flushes: " << flush_count << " out of " << num_shuffles << endl;
        cout << "Straights: " << str_count << " out of " << num_shuffles << endl;
        cout << "Straight Flushes: " << str_flush_count << " out of " << num_shuffles << endl;

        return 0;
    }
}
namespace FinalProject
{
    class Matrix
    {
    private:
        int m[2][2];

    public:
        Matrix() = default;
        Matrix(int a, int b, int c, int d)
        {
            m[0][0] = a;
            m[0][1] = b;
            m[1][0] = c;
            m[1][1] = d;
        }
        friend Matrix operator*(int t, const Matrix &A)
        {
            Matrix result;
            result.m[0][0] = t * A.m[0][0];
            result.m[0][1] = t * A.m[0][1];
            result.m[1][0] = t * A.m[1][0];
            result.m[1][1] = t * A.m[1][1];
            return result;
        }
        Matrix operator-() const
        {
            Matrix result;
            result.m[0][0] = -this->m[0][0];
            result.m[0][1] = -this->m[0][1];
            result.m[1][0] = -this->m[1][0];
            result.m[1][1] = -this->m[1][1];
            return result;
        }
        friend ostream &operator<<(ostream &os, const Matrix &A)
        {
            os << "[" << A.m[0][0] << ", " << A.m[0][1] << "]\n"
               << "[" << A.m[1][0] << ", " << A.m[1][1] << "]\n";
            return os;
        }
        Matrix operator+(const Matrix &rhs)
        {
            Matrix result;
            result.m[0][0] = this->m[0][0] + rhs.m[0][0];
            result.m[0][1] = this->m[0][1] + rhs.m[0][1];
            result.m[1][0] = this->m[1][0] + rhs.m[1][0];
            result.m[1][1] = this->m[1][1] + rhs.m[1][1];
            return result;
        }
        Matrix operator*(const Matrix &rhs)
        {
            Matrix result;
            result.m[0][0] = this->m[0][0] * rhs.m[0][0] + this->m[0][1] * rhs.m[1][0];
            result.m[0][1] = this->m[0][0] * rhs.m[0][1] + this->m[0][1] * rhs.m[1][1];
            result.m[1][0] = this->m[1][0] * rhs.m[0][0] + this->m[1][1] * rhs.m[1][0];
            result.m[1][1] = this->m[1][0] * rhs.m[0][1] + this->m[1][1] * rhs.m[1][1];
            return result;
        }
    };
} // namespace FinalProject

// std::cin.ignore(1);  // 吸收輸入緩衝區中剩下的 '\n'（換行符）
// cin.getline(stu_name, 50);
#endif