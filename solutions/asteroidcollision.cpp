#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // positive asteroids go right, negative go left
    // collision only when top of stack is positive and current is negative
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool alive = true;

            while (alive && a < 0 && !st.empty() && st.top() > 0) {
                if (st.top() < -a) {
                    st.pop();           // stack asteroid explodes
                } else if (st.top() == -a) {
                    st.pop();           // both explode
                    alive = false;
                } else {
                    alive = false;      // current asteroid explodes
                }
            }

            if (alive) st.push(a);
        }

        vector<int> res(st.size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = st.top(); st.pop();
        }

        return res;
    }
};
