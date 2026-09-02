class Solution {
public:

    bool possible(long long int mid, vector<int>& piles, int h){
        long long int time=0;
        for(auto& x: piles){
            time += x/mid;
            if(x%mid!=0){
                time++;
            }
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        long long int max_bananas = *max_element(piles.begin(),piles.end());

        long long int low=1,high= max_bananas;

        while(low<high){
            long long int mid = low + (high-low)/2;

            if( possible(mid,piles,h)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
