#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> SUM(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_map;

        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end())
            {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    Solution sol;
    vector<int> result = sol.SUM(nums, target);
    if (result.size() == 2)
    {
        cout << result[0] << " " << result[1] << "\n";
    }
    return 0;
}