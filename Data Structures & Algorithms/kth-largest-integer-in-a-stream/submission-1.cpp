class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
public:
   
    KthLargest(int k, vector<int>& nums) {
         K=k;
        for(auto x: nums){
            add(x);
        }
       
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};
