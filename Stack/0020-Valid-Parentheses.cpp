/*
 * Problem: 20. Valid Parentheses
 * Time Complexity: O(N) - We scan the string exactly once.
 * Space Complexity: O(N) - In the worst case, the stack stores all opening brackets.
 * * Intuition: 
 * Brackets must close in the reverse order of how they opened (Last In, First Out).
 * - When we see an opening bracket, we push it onto the stack to remember it.
 * - When we see a closing bracket, it MUST match the bracket currently sitting 
 * on top of the stack. If it matches, we pop it off and continue.
 * - If the stack is empty when a closing bracket arrives, or if there is a mismatch,
 * the string is invalid.
 */

#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char ch : s) {
            // Case 1: If it's an opening bracket, store it
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            // Case 2: It's a closing bracket
            else {
                // Safeguard: Closing bracket arrives but nothing is open
                if (st.empty()) {
                    return false;
                }
                
                char topBracket = st.top();
                
                // Check for a perfect match
                if ((ch == ')' && topBracket == '(') ||
                    (ch == '}' && topBracket == '{') ||
                    (ch == ']' && topBracket == '[')) {
                    st.pop(); // Match found, clear the opening bracket
                } else {
                    return false; // Mismatch detected (e.g., "( ]")
                }
            }
        }
        
        // If the stack is completely empty, all pairs matched perfectly
        return st.empty();
    }
};