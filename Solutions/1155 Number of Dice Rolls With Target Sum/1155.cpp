#include <iostream>
/* Brute force solution
 * runs out of execution time
*/
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

int main() {
    int d = 15;
    int f = 15;
    int target = 250;


    Solution s;
    std::cout << s.numRollsToTarget(d, f, target) << std::endl;
}