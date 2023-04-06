#include <iostream>
#include <unordered_set>
#include <vector>

std::string find_sum_pair(const std::vector<double>& nums, double s) {
    std::unordered_set<double> hash_table;
    for (double x : nums) {
        double complement = s - x;
        if (hash_table.find(complement) != hash_table.end()) {
            return "YES";
        }
        hash_table.insert(x);
    }
    return "NO";
}

int main() {
    std::vector<double> nums = { 5, 9, 1, 3 };
    double s = 6;
    std::cout << find_sum_pair(nums, s) << std::endl;  // Output: YES

    nums = { 5, 9, 1, 3 };
    s = 7;
    std::cout << find_sum_pair(nums, s) << std::endl;  // Output: NO

    return 0;
}
