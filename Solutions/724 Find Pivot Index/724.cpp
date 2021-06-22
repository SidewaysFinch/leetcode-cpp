#include <iostream>
#include <vector>

class Solution
{
  public:
    int pivotIndex(std::vector<int> &nums)
    {
        // Start by assuming the index is 0
        int left = 0;
        int right = 0;
        int index = 0;

        // Right side will not ever include the first number
        for (int i = 1; i < nums.size(); i++)
        {
            right += nums[i];
        }

        /* Handle edge case behaviours:
         * when size = 1 leetcode answer interprets [-1] and [1] as return 0
         * otherwise check 0th index condition
         */
        if (nums.size() == 1 || (left == right))
        {
            return 0;
        }

        for (index = 1; index < nums.size(); index++)
        {
            // Pivot a number and compare the new sums
            left += nums[index - 1];
            right -= nums[index];

            if (left == right)
            {
                return index;
            }
        }
        return -1;
    }
};

int main()
{
    std::vector<int> nums = {-1, 1};

    Solution s;
    return s.pivotIndex(nums);
}