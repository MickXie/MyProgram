#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <map>
#include <algorithm>
#include "Homework.h"
using namespace std;

int main()
{
    /*
    !!!Homework1!!!
    Homework1::datainput data;
    Homework1::rectangle rect(10.5, 2);
    cout << "Enter the width and height of the triangle: ";
    // ignore the newline character
    cin >> data.x;        // 讀取寬度
    cin.ignore(100, ','); // 跳過 1 個逗號（如果存在）
    cin >> data.y;
    cout << "The width and height of the triangle are: " << data.x << ", " << data.y << endl;
    Homework1::triangle tri(data.x, data.y);
    cout << rect.area() << endl;
    cout << tri.area() << endl;
    */
    /*
    !!!Homework2!!!
     Homework1::datainput data;
     cin >> data.x;      // 讀取寬度
     cin.ignore(1, ','); // 跳過 1 個逗號（如果存在）
     cin >> data.y;
     cin.ignore(1, ',');
     cin >> data.z;
     Homework2::Clock clock1(data.x, data.y, data.z);
     clock1.tick();
     clock1.showtime();
     system("pause");
     */
    /*
    !!!Homework3!!!
    Homework3::Animal *pet = new Homework3 ::Animal;
    pet->makeSound();
    delete pet;
    pet = new Homework3::Dog;
    pet->makeSound();
    delete pet;
    pet = new Homework3::Cat;
    pet->makeSound();
    delete pet;
    */
    /*
    !!!Homework4!!!
     Homework1::datainput data;
     cout << "Enter the car's width, height, and length: " << endl;
     cin >> data.x;
     cin.ignore(1, ','); // 跳過 1 個逗號（如果存在）
     cin >> data.y;
     cin.ignore(1, ','); // 跳過 1 個逗號（如果存在）
     cin >> data.z;      // 讀取寬度
     Homework4::Car car(data.x, data.y, data.z);
     cout << "The total cost of the car is: " << car.totalCost() << endl;
     */
    /*
    !!!Homework5!!!
    Homework1::datainput data;
    cout << "Enter the car'speed limit , car1's speed ,car2's speed" << endl;
    cin >> data.x;
    cin.ignore(1, ','); // 跳過 1 個逗號（如果存在）
    cin >> data.y;
    cin.ignore(1, ','); // 跳過 1 個逗號（如果存在)
    cin >> data.z;      // 讀取寬度
    Homework5::car::getLimit(data.x);
    Homework5::car car1(data.y);
    Homework5::car car2(data.z);
    car1.checkSpeed();
    car2.checkSpeed();
    */
    /*
    !!!Homework6!!!
     Homework6::Employees *emp = new Homework6::FullTimeEmployee("Alice", 101, 5000);
     emp->displayInfo();
     emp = new Homework6::PartTimeEmployee("Bob", 202, 100, 16);
     emp->displayInfo();
     */
    /*
    int a = 9;
    auto p = make_shared<int>(a); // object to which p points has one user
    auto q(p);                    // p and q point to the same object; q is a copy of p
    // object to which p and q point has two users
    auto r = make_shared<int>(a); // int to which r points has one user
    r = q;                        // assign to r, making it point to a different address
    // increase the use count for the object to which q points
    // reduce the use count of the object to which r had pointed
    // the object r had pointed to has no users; that object is
    // automatically freed
    cout << r.unique();    // print out whether p.use_count() is 1 or not
    cout << r.use_count(); // print out number of objects sharing with r
    cout << r.unique();
    */
    /*
    using namespace Homework7;
     Vector v1(1, 2);
     Vector v2(3, 4);
     Vector sum = v1 + v2;
     Vector diff = v1 - v2;
     double dot = v1 * v2;
     cout << "v1: " << v1 << endl;
     cout << "v2: " << v2 << endl;
     cout << "Sum: " << sum << endl;
     cout << "Difference: " << diff << endl;
     cout << "Dot product: " << dot << endl;
     if (v1 == v2)
     {
         cout << "v1 and v2 are equal" << endl;
     }
     else
     {
         cout << "v1 and v2 are not equal" << endl;
     }
    */
    /*
     using namespace Homework8;
     Box<int> intBox; // T 被指定為 int
     intBox.set(123);
     cout << intBox.get() << endl;
     Box<string> strBox; // T 被指定為 string
     strBox.set("Hello");
     cout << strBox.get() << endl;
     */
    /*
    using namespace Homework9;
    int a[6] = {10, 50, 30, 40, 20, -20};
    float b[] = {2.3, 0.0, -1.2, 17.2};
    char c[] = "NTOUCSE";
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int n3 = sizeof(c) / sizeof(c[0]);
    print_max<int>(a, n1);
    print_max<float>(b, n2);
    print_max<char>(c, n3);
    return 0;
    */
    /*
 using namespace Homework10;
     int n = 5;
     Node *dataList = new Node[n]; // dynamically allocate array of Nodes

     bubbleSort<Node>(dataList, n); // sort based on data value

     for (int i = 0; i < n; i++)
         cout << dataList[i] << " ";
     cout << endl;

     delete[] dataList; // free memory
     return 0;
    */
    /*
    using namespace homework11;
    vector<float> num = {24, 75, 89.1, 98.1, 106, 249};
    float target = 187.2;
    Solution<float> solution(num, target);
    return 0;
    */
    /*
    using namespace Homework12;
     vector<int> vec = {-1, 0, 1, 2, -1, 4};
     Solution solution;
     vector<vector<int>> result = solution.threeSum(vec);
     for (const auto &triplet : result)
     {
         cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
     }
    */
    using namespace FinalProject;
    Matrix A(1, 2, 3, 4);
    Matrix B(5, 6, 7, 8);
    cout << "A + B:\n"
         << A + B
         << "-A + B:\n"
         << (-A) + B
         << "A * B:\n"
         << A * B
         << "(A + A) * B:\n"
         << (A + A) * B;
    return 0;
}