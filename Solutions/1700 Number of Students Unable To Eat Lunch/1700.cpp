#include <iostream>
#include <vector>

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int type_count[] = { 0, 0 };
        int i, k;

        for (i = 0; i < students.size(); i++) {
            //Get a count of how many students like circles/squares
            type_count[students[i]]++;
        }
        
        k = 0;
        while (k < sandwiches.size()) {
            //While we still have sandwiches untaken, take away sandwiches away
            if (type_count[sandwiches[k]] > 0) {
                type_count[sandwiches[k]]--;
            }
            else {
                //If we are out of people to take the current kind of sandwich away, stop
                break;
            }
            k++;
        }

        //The # of students who couldn't eat is = total # sandwhiches - # students who did eat
        return sandwiches.size() - k;
    }
};

int main() {
    std::vector<int> student  { 1, 1, 0, 0 };
    std::vector<int> sandwich { 0, 1, 0, 1 };

    Solution s;
    s.countStudents(student, sandwich);
}