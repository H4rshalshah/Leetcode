#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result = "";

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        // Use long long to avoid overflow with INT_MIN
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        // Integer part
        result += to_string(num / den);
        long long remainder = num % den;

        if (remainder == 0) {
            return result;
        }

        // Fractional part
        result += ".";
        unordered_map<long long, int> remainder_map;

        while (remainder != 0) {
            // If the remainder has been seen before, we found a repeating cycle
            if (remainder_map.find(remainder) != remainder_map.end()) {
                result.insert(remainder_map[remainder], "(");
                result += ")";
                break;
            }

            // Store current position of remainder
            remainder_map[remainder] = result.length();

            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};