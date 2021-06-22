#include <algorithm>
#include <iostream>
#include <vector>


/* There are only two situations we care about:
 *   - The max and min of nums are already the closest so we just add/sub k to both to get the same difference
 *   - The min needs k added and the max needs k subtracted to make the difference smaller
 *   (only other possibility is subtracting k from min and adding k to max which always makes difference bigger so we
 * ignore this) Thus our plan is to compare the difference between the max and min with the difference between the a new
 * min calculated
 */

class Solution
{
  public:
    int smallestRangeII(std::vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());

        int max = nums.back() - k;
        int min = nums.front() - k;

        int diff = max - min;

        if (k == 0)
        {
            return diff;
        }

        // We want to test our variable miniums against the max
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // Check if there's a new max value
            max = std::max(nums[i] + k, max);
            // Find the smaller of our biggest min and the next index -k
            min = std::min(nums[i + 1] - k, nums.front() + k);
            // See if this difference is smaller
            diff = std::min(diff, max - min);
        }
        return diff;
    }
};

int main()
{
    std::vector<int> nums = {3, 1, 10};
    int k = 4;

    Solution s;
    return s.smallestRangeII(nums, k);
}