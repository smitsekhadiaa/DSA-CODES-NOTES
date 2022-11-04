// Reverse Vowels of a String

// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// Example 1:

// Input: s = "hello"
// Output: "holle"
// Example 2:

// Input: s = "leetcode"
// Output: "leotcede"

// Constraints:

// 1 <= s.length <= 3 * 105
// s consist of printable ASCII characters.
class Solution
{
public:
    bool check(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return true;
        }
        return false;
    }
    string reverseVowels(string s)
    {
        int i = 0;
        int n = s.length();
        int j = n - 1;
        while (i < j)
        {
            if (check(s[i]) == false && check(s[j]) == false)
            {
                i++;
                j--;
            }
            else if (check(s[i]) == true && check(s[j]) == false)
            {
                j--;
            }
            else if (check(s[i]) == false && check(s[j]) == true)
            {
                i++;
            }
            else if (check(s[i]) == true && check(s[j]) == true)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else
            {
                continue;
            }
        }
        return s;
    }
};