class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle 32-bit integer overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to prevent overflow during absolute value operations
        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);

        long long quotient = 0;

        // Perform bitwise division
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Find the largest multiple using left shifts (multiplication by 2)
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the chunk from dividend and add to quotient
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};