#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <string>
using namespace std;

// 將羅馬數字轉換為整數
int romanToInt(string s) {
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        int currentValue = romanMap[s[i]];

        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}

// 將整數轉換為羅馬數字
string intToRoman(int num) {
    int numArr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romanArr[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string roman = "";

    for (int i = 0; i < 13; i++) {
        while (num >= numArr[i]) {
            roman += romanArr[i];
            num -= numArr[i];
        }
    }
    return roman;
}

int main() {
    string input1, input2;
    while (cin >> input1) {
        if (input1 == "#")
            break;
        cin >> input2;

        // 將羅馬數字轉換為整數
        int num1 = romanToInt(input1);
        int num2 = romanToInt(input2);

        // 計算差的絕對值
        int absDiff = abs(num1 - num2);

        if (absDiff == 0) {
            cout << "ZERO" << endl;
        } else {
            // 將差的絕對值轉換為羅馬數字
            string romanResult = intToRoman(absDiff);
            cout << romanResult << endl;
        }
    }
    return 0;
}
