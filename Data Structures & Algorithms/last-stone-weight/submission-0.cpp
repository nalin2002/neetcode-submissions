class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq(stones.begin(),stones.end());

        while(!pq.empty() && pq.size()>1){
            int x= pq.top();
            pq.pop();

            int y= pq.top();
            pq.pop();

            if(x==y){
                continue;
            }
            else{
                pq.push(x-y);
            }
        }
        return pq.empty()?0:pq.top();
    }
};
