class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0); // it stores the needed char

        // Store required characters
        for (char c : t) {
            freq[c]++;
        }

        int l = 0; //stores left boundary of the current window
        int r = 0;
        int count = t.size(); // total characters needed

        int minLen = INT_MAX; // min length that we currently have
        int start = 0; //stores the left boundary of minimum valid window

        while (r < s.size()) {
            // I will traverse through code and checkIf current char is needed,
            // decrease count
            if (freq[s[r]] > 0) {
                count--;
            }

            freq[s[r]]--; // include character in window 
            r++;

            // When all characters are matched
            while (count == 0) {
                // Update minimum window
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }

                freq[s[l]]++;// Try to remove left character and add it to still needed section

                // If removing makes window invalid
                if (freq[s[l]] > 0) {
                    count++;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};