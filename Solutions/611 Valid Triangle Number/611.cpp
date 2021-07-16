#include <algorithm>
#include <vector>

/* For all triangles we know that the sum of any two sides must be greater than the last side
 * If we sort our array, we can iterate through the array and compare values
 */

class Solution
{
  public:
    int triangleNumber(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int result = 0;

        for (size_t k = 2; k < nums.size(); k++)
        {
            // Fix our k at the highest value then compare the smaller values below it
            int i = 0;
            int j = k - 1;

            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    // Because our list is in increasing order, every value of nums[i]
                    // after this one will also be > nums[k], so we have j - i valid pairs
                    result += j - i;

                    // Try a new j
                    j--;
                    // All of our previous i values are invalid because of the sorting
                    // if i + j isn't > k, then i + j-- won't be either
                }
                else
                {
                    // If we don't get a match then increase i
                    i++;
                }
            }
        }
        return result;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    std::vector<int> nums = {4, 2, 3, 4};

    Solution s;
    return s.triangleNumber(nums);
}