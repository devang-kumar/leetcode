class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int coins = 0;
        int left = 0;
        int right = piles.size() - 1;
        while (left < right) {
            coins += piles[right - 1];
            right -= 2; 
            left += 1;       
        }
        return coins;
    }
};
