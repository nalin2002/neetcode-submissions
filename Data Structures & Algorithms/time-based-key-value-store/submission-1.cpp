class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if( mp.find(key) ==mp.end()) return "";

        vector<pair<int,string>>& values = mp[key];

        int max_t= timestamp;

        int n= mp[key].size();

        int l=0,r=n-1;

        int ans=-1;
        while(l<=r){
            int m= l+ (r-l)/2;

            if(values[m].first <= max_t){
                ans= m;
                l= m+1;
            }
            else{
                r=m-1;
            }
        }
        return ans!=-1? values[ans].second:"";
    }
};
