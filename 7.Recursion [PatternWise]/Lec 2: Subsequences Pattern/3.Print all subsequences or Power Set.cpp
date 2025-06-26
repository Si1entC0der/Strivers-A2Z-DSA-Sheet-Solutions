https://leetcode.com/problems/subsets/description/

// approach 1: 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int sz = nums.size();
        int len = (1 << sz);
        for (int i = 0; i < len; i++) {
            vector<int> lst;
            for (int j = 0; j < sz; j++)
                if (i & (1 << j))
                    lst.push_back(nums[j]);
            ans.push_back(lst);
        }
        return ans;
    }
};


/*

Editorial: Subsets (Bitmasking Approach)  
This C++ solution generates all possible subsets of a given array `nums` using bitmasking, an efficient technique that leverages binary representations to enumerate subsets.  

# Key Insights:  
1. Total Subsets:  
   - An array of size `n` has `2^n` subsets (including the empty set).  
   - Here, `1 << sz` computes `2^sz` efficiently.  

2. Bitmasking Logic:  
   - Each number `i` from `0` to `2^sz - 1` represents a unique subset.  
   - The `j`-th bit of `i` determines whether `nums[j]` is included in the subset.  
   - Example:  
     - `nums = [1, 2, 3]`, `i = 5` (`101` in binary) → subset `[1, 3]`.  

3. Efficiency:  
   - Time Complexity: O(n × 2^n) (since each of the `2^n` subsets takes `O(n)` time to generate).  
   - Space Complexity: O(2^n) (required to store all subsets).  

# Why This Approach?  
- No Recursion: Avoids function call overhead and stack limits.  
- Intuitive Bitwise Checks: Simple loop structure with bitwise operations.  
- Lexicographical Order: Subsets are generated in natural binary order.  

# Edge Cases Handled:  
- Empty input → Returns `[[]]`.  
- Single-element input → Returns `[[], [element]]`.  

A concise and optimal solution for subset generation, perfect for combinatorics problems! 🎯
*/


// approach 2:
class Solution {
public:
    void f(int i, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }

        // Take the element
        v.push_back(nums[i]);
        f(i + 1, nums, v, ans);

        // Not take the element
        v.pop_back();
        f(i + 1, nums, v, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        f(0, nums, v, ans);
        return ans;
    }
};



/*

Editorial: Subsets (Backtracking Approach)  
This C++ solution generates all possible subsets of a given array `nums` using recursive backtracking, a fundamental technique for combinatorial problems.  

# Key Insights:  
1. Decision Tree Approach:  
   - At each step, we decide whether to include (`take`) or exclude (`not take`) the current element.  
   - This creates a binary tree of choices, leading to all `2^n` subsets.  

2. Base Case:  
   - When we reach the end of the array (`i == nums.size()`), we add the current subset (`v`) to the result.  

3. Backtracking Steps:  
   - Take: Add `nums[i]` to the subset, then recurse.  
   - Not Take: Remove `nums[i]` (backtrack), then recurse.  

# Complexity:  
- Time: O(n × 2^n) (each of the `2^n` subsets is generated in `O(n)` time).  
- Space: O(n)` (recursion stack depth) + O(2^n)` (output storage).  

# Advantages:  
✅ Intuitive: Mirrors the natural thought process of subset generation.  
✅ No Duplicates: Automatically avoids duplicate subsets.  
✅ Flexible: Easily modifiable for problems like subsets with duplicates or size constraints.  

# Edge Cases Handled:  
- Empty input → Returns `[[]]`.  
- Single-element input → Returns `[[], [element]]`.  

A classic and elegant backtracking solution, essential for mastering recursion! 

*/
