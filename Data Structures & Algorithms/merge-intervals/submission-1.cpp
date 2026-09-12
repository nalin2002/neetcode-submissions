class Solution {
public:
    static bool comp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();

        if(n==1) return intervals;
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> res;

        vector<int> temp= intervals[0];

        int i=1;

        while(i<n){
            
            while(i<n && temp[1]>= intervals[i][0]){
                temp[0]= min(temp[0],intervals[i][0]);
                temp[1]=max(temp[1],intervals[i][1]);
                i++;
            }
            res.push_back(temp);
            temp.clear();

            if(i<n-1){
            temp= intervals[i];
            }
            else if(i==n-1){
                res.push_back(intervals[i]);
            }
            i++;
            
        }


        return res;
    }
};
