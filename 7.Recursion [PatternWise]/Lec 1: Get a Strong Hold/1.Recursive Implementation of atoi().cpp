https://leetcode.com/problems/string-to-integer-atoi/description/


class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, res = 0, sz = s.size();

        while (i < sz && s[i] == ' ')
            i++;

        if (i < sz && (s[i] == '+' or s[i] == '-')) {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }

        while (i < sz && isdigit(s[i])) {
            int diz = s[i] - '0';

            if (res > (INT_MAX - diz) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;

            res = res * 10 + diz;
            i++;
        }

        return res * sign;
    }
};



/*

This C++ solution efficiently converts a string to a 32-bit signed integer while
adhering to specific rules:
1. Leading whitespaces are skipped.
2. An optional sign (`+` or `-`) is parsed.
3. Numerical characters are processed until a non-digit is encountered.
4. Overflow handling: If the result exceeds `INT_MAX` or `INT_MIN`, the
respective boundary value is returned.

# Key Points:
- Sign Handling: The sign is captured early and applied at the end.
- Overflow Check: Before updating `res`, the code checks if multiplying by 10
and adding the next digit would cause overflow.
- Early Termination: Processing stops at the first non-digit character.

This approach ensures correctness and efficiency with O(n) time complexity
(where `n` is the string length) and O(1) space complexity.

*/
