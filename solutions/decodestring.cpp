#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // use two stacks: one for counts, one for strings built so far
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strs;
        string curr = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                strs.push(curr);
                curr = "";
                k = 0;
            } else if (c == ']') {
                int repeat = counts.top(); counts.pop();
                string prev = strs.top(); strs.pop();
                for (int i = 0; i < repeat; i++) prev += curr;
                curr = prev;
            } else {
                curr += c;
            }
        }

        return curr;
    }
};
