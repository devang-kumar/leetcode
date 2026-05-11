#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // monotonic stack: keep decreasing stack, pop when we find a greater element
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> res;
        for (int num : nums1)
            res.push_back(nextGreater.count(num) ? nextGreater[num] : -1);

        return res;
    }
};
