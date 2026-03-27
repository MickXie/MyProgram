#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<int> PLUS(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> digits;
    int d;
    while (ss >> d)
    {
        digits.push_back(d);
    }
    Solution ans;
    vector<int> result = ans.PLUS(digits);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
