#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_map; // Create a hashmap to store numbers and their indices

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i]; // Calculate the complement

        // Check if the complement is already in the hashmap
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i}; // Return indices if found
        }

        // Otherwise, store the current number and its index in the hashmap
        num_map[nums[i]] = i;
    }

    return {}; // Return empty vector if no solution is found
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices: " << nums[result[0]] << ", " << nums[result[1]] << std::endl;
    } else {
        std::cout << "No solution found" << std::endl;
    }

    return 0;
}

