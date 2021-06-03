#include <iostream>
#include <vector>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        std::string defanged = "";
        for (size_t i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                defanged.append("[.]");
            }
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