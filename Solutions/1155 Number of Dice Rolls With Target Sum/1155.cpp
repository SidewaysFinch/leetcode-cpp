#include <iostream>
#include <vector>
/* Brute force solution
 * runs out of execution time
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        //Handle recursion end/1d case
        if (d == 1) {
            if (target > f) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else {
            int sum = 0;
            //Roll this dice and compare the new target with one less die
            for (size_t i = 1; i <= f; i++) {
                sum += numRollsToTarget(d - 1, f, target - i);
            }
            return sum % (10^9 + 7);
        }
    }
};


*/
/* New Dynamic Programming approach: map states to an array
 * This is similar to our brute force method, but much faster as
 * a) it does not exponentially grow as 
*/
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        std::vector<std::vector<int>> statemap(d+1, std::vector<int>(target+1, 0));
        statemap[0][0] = 1;
        for (int dice = 1; dice <= d; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                for (int k = 1; k <= f; k++) {
                    //If our target is reachable
                    if (k <= sum) {
                        //Add from the previous state (1 less die, sum - this roll)
                        statemap[dice][sum] = statemap[dice][sum] % (1000000007) + statemap[dice-1][sum-k] % (1000000007);
                    }
                }
            }
        }
        return statemap[d][target];
    }
};

int main() {
    int d = 30;
    int f = 30;
    int target = 500;


    Solution s;
    std::cout << s.numRollsToTarget(d, f, target) << std::endl;
}