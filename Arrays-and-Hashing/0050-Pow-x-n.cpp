/*
 * Problem: 50. Pow(x, n)
 * * Time Complexity: O(log N) - We halve the exponent on every iteration.
 * Space Complexity: O(1) - No extra memory is used.
 * * Intuition: 
 * Binary Exponentiation. Instead of multiplying 'x' by itself 'n' times, 
 * we square the base and halve the exponent. 
 * If the current exponent is odd, we multiply our running answer by the current base.
 */

class Solution {
public:
    double myPow(double x, int n) {
        // Base cases for immediate returns
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;
        if (x == 1) return 1.0;
        if (x == -1 && n % 2 == 0) return 1.0;
        if (x == -1 && n % 2 != 0) return -1.0;

        // Use long to prevent integer overflow when n = -2147483648
        long binform = n;
        
        // Handle negative exponents
        if (binform < 0) {
            x = 1 / x;
            binform = -binform;
        }
        
        double ans = 1.0;
        
        // Corrected condition: strictly greater than 0
        while (binform > 0) {
            // Corrected check: test the current binform, not the original n
            if (binform % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binform /= 2;
        }
        
        return ans;
    }
};