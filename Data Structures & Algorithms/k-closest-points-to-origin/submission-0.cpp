class Solution {
public:
    double dist(int x1,int y1,int x2,int y2){
        return (sqrt((x1 - x2)^2 + (y1 - y2)^2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue< pair<double,pair<int,int>>,vector< pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>> > pq; 
        for(auto x: points){
            int x1= x[0];
            int y1= x[1];
            double d= sqrt(x1*x1+y1*y1);
            pq.push({d,{x1,y1}});
        }
        vector<vector<int>> ans;
        while(k--){
            pair<double,pair<int,int>> top= pq.top();
            pq.pop();

            ans.push_back({top.second.first,top.second.second});
        }
        return ans;
    }
};
