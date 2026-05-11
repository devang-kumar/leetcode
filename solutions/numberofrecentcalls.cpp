#include <bits/stdc++.h>
using namespace std;

// queue-based: keep only calls within last 3000ms
class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000)
            q.pop();
        return q.size();
    }
};
