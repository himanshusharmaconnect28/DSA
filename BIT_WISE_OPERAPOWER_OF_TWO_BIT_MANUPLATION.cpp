class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == INT_MAX || n == INT_MIN|| n <= 0) {
            return 0;
        }
        return (n & (n - 1)) == 0;
    }    
};
