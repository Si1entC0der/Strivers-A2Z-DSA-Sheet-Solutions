https://leetcode.com/problems/powx-n/description/


class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double res = 1.0;
        while (N) {
            if (N & 1)
                res *= x;
            x *= x;
            N /= 2;
        }

        return res;
    }
};

/*

 Editorial: Pow(x, n) - Fast Exponentiation

This C++ solution efficiently computes `x` raised to the power `n` (`x^n`) using
binary exponentiation, a method that reduces the time complexity from O(n)
(naive approach) to O(log n).

# Key Steps:
1. Handle Negative Exponents:
   - If `n` is negative, convert the problem to `(1/x)^(-n)`.
   - Using `long long` avoids overflow when handling `INT_MIN`.

2. Binary Exponentiation (Iterative Approach):
   - Break down `n` into binary powers: For example, `x^13 = x^8 * x^4 * x^1`.
   - Multiply `res` only when the current bit is set (`N & 1`).
   - Square `x` and halve `N` in each iteration (`x *= x`, `N /= 2`).

# Edge Cases & Optimizations:
  - Zero Exponent: Returns `1.0` (since `x^0 = 1`).
  - Overflow Handling: No risk of overflow due to logarithmic steps.
  - Efficiency: Performs O(log n) multiplications instead of O(n).

This approach is optimal for large exponents and is widely used in competitive
programming and numerical computations.

A clean, efficient, and mathematically elegant solution! 🔥


*/
