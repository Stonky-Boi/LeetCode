class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int inversions = 0;
        set<pair<long long, int>> sums;
        set<int> remaining;
        vector<long long> curr_elements(nums.begin(),nums.end());
        for (int i = 0; i < n; ++i) remaining.insert(i);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) inversions++;
            sums.insert({(long long)nums[i] + nums[i + 1], i});
        }
        int operations = 0;
        while (inversions > 0) {
            operations++;
            auto it = sums.begin();
            long long merged_sum = it->first;
            int left = it->second;
            sums.erase(it);
            auto right_it = remaining.upper_bound(left);
            int right = *right_it;
            if (curr_elements[left] > curr_elements[right]) inversions--;
            auto left_it = remaining.find(left);
            if (left_it != remaining.begin()) {
                auto prev_it = prev(left_it);
                int prev = *prev_it;
                if (curr_elements[prev] > curr_elements[left]) inversions--;
                sums.erase({curr_elements[prev] + curr_elements[left], prev});
                if (curr_elements[prev] > merged_sum) inversions++;
                sums.insert({curr_elements[prev] + merged_sum, prev});
            }
            auto next_it = next(right_it);
            if (next_it != remaining.end()) {
                int next = *next_it;
                if (curr_elements[right] > curr_elements[next]) inversions--;
                sums.erase({curr_elements[right] + curr_elements[next], right});
                if (merged_sum > curr_elements[next]) inversions++;
                sums.insert({merged_sum + curr_elements[next], left});
            }
            curr_elements[left] = merged_sum;
            remaining.erase(right);
        }
        return operations;
    }
};