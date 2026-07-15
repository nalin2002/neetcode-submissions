class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> ans;
        int i=0,j=n-1;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;
            }
            else{
                ans= {i+1,j+1};
                return ans;
            }
        }
        return ans;
    }
};
