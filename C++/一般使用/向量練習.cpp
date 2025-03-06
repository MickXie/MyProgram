#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> numbers; // 創建一個整數向量

    // 向向量中添加元素
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // 使用索引訪問向量中的元素
    cout << numbers[0] << std::endl; // 輸出 10

    // 使用迴圈遍歷向量中的元素
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << std::endl; // 輸出 10 20 30

    return 0;
}
