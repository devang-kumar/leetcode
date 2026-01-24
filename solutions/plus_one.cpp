class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int count = 0;
        for(int i=len-1;i>=0;i--){
            if(digits[i] == 9){
                digits[i]=0;
                count++;
            }
            else{
                 digits[i]+=1;
                 return digits;
            }
        }
        if(count == len){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};