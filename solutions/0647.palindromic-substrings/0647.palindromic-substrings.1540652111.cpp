/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (54.49%)
 * Total Accepted:    64.6K
 * Total Submissions: 118.5K
 * Testcase Example:  '"abc"'
 *
 * 
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * 
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters. 
 * 
 * 
 * Example 1:
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Note:
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 */
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            res += oddSubPalin(s, i);
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i-1] == s[i]) {
                res += evenSubPalin(s, i-1, i);
            }
        }
        return res;
    }

private:
    int oddSubPalin(string& s, int m) {
        int i = m;
        int j = m;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - m;
    }

    int evenSubPalin(string& s, int m, int n) {
        int i = m;
        int j = n;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - n;
    }
};

