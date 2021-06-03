#include <iostream>
#include <vector>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        std::string defanged = "";

        //Non-regex soln: step through every char
        for (size_t i = 0; i < address.length(); i++) {
            //If we come across a period, copy over the defanged ver
            if (address[i] == '.') {
                defanged.append("[.]");
            }
            //Otherwise just copy over the char
            else {
                defanged += address[i];
            }
        }
        return defanged;
    }
};

int main() {
    std::string address = "255.100.50.0";

    Solution s;
    std::cout << s.defangIPaddr(address) << std::endl;
}