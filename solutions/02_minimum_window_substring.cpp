#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        int have = 0, required = need.size();
        int l = 0, minLen = INT_MAX, start = 0;
        for (int r = 0; r < s.size(); r++) {
            window[s[r]]++;
            if (need.count(s[r]) && window[s[r]] == need[s[r]]) have++;
            while (have == required) {
                if (r - l + 1 < minLen) { minLen = r - l + 1; start = l; }
                window[s[l]]--;
                if (need.count(s[l]) && window[s[l]] < need[s[l]]) have--;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
