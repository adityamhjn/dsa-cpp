/*
 * Problem: 242. Valid Anagram
 * * Time Complexity: O(N) - We scan the strings exactly once.
 * Space Complexity: O(1) - The array size is fixed at 26, which is constant memory.
 * * Intuition: 
 * We use a single fixed-size array as a ledger. 
 * String 's' deposits (+1) into the character's account.
 * String 't' withdraws (-1) from the character's account.
 * If the strings are perfect anagrams, every account balance will be exactly 0.
 */

#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // STEP 1: The Deflection
        if (s.length() != t.length()) {
            return false;
        }

        // STEP 2: The Bank
        int counts[26] = {0};

        // STEP 3: The Transactions
        for (int i = 0; i < s.length(); i++) {
            counts[s[i] - 'a']++; // Deposit
            counts[t[i] - 'a']--; // Withdraw
        }

        // STEP 4: The Audit
        for (int i = 0; i < 26; i++) {
            if (counts[i] != 0) {
                return false;     // Someone is lying
            }
        }

        // STEP 5: The Survival
        return true;
    }
};