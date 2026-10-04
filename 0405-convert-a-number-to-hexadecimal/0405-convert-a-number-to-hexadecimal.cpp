class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        string hexChars = "0123456789abcdef";
        string result = "";
        
        // Cast to unsigned int to handle 32-bit two's complement automatically
        unsigned int uNum = num;
        
        while (uNum > 0) {
            // Get the last 4 bits (0xF is 1111 in binary)
            result = hexChars[uNum & 0xF] + result;
            // Logical right shift by 4 bits
            uNum >>= 4;
        }
        
        return result;
    }
};