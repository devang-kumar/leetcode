#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // greedy: always schedule the most frequent task first
    // use a max heap + cooldown queue
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        priority_queue<int> maxHeap;
        for (auto& [ch, cnt] : freq) maxHeap.push(cnt);

        // {count, available_at_time}
        queue<pair<int,int>> cooldown;
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) cooldown.push({cnt, time + n});
            }

            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
