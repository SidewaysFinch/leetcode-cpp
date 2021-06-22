#include <cstdio>
#include <iostream>
#include <vector>

// Bruteforce solution
// Stops working due to size limit of numbers
/*
class Solution {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
        size_t bin = 0;
        std::vector<bool> answer;

        for (auto i = 0; i < nums.size(); i++) {
            bin = (bin << 1) | nums.at(i);
            answer.push_back(!(bin % 5 != 0));
        }
        return answer;
    }
};*/

class Solution
{
  public:
    std::vector<bool> prefixesDivBy5(std::vector<int> &nums)
    {
        int calc = 0;
        std::vector<bool> answer;

        for (auto i = 0; i < nums.size(); i++)
        {
            calc = (calc * 2 + nums.at(i)) % 5;
            answer.push_back(!calc);
        }
        return answer;
    }
};

int main()
{
    std::vector<int> nums = {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                             0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1};
    std::vector<bool> ans;
    Solution s;

    ans = s.prefixesDivBy5(nums);

    for (auto i = 0; i < nums.size(); i++)
    {
        std::cout << ans.at(i) << " ";
    }
}