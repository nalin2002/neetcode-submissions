class Solution {
public:
    int min_val(vector<int>& nums){
        int n= nums.size();

        int l=0,r=n-1;

        while(l<r){
            int m= l+ (r-l)/2;

            if( nums[m]<nums[r]){
                r=m;
            }
            else{
                l= m+1;
            }
        }
        return l;
    }
    int is_present(vector<int>& nums,int l,int r,int target){
        while(l<=r){
            int m= l + (r-l)/2;

            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                r= m-1;
            }
            else{
                l= m+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n= nums.size();

        int l=0,r=n-1;

        int min_index= min_val(nums);

        int i1= is_present(nums,0,min_index-1,target);
        int i2= is_present(nums,min_index,n-1,target);

        if(i1!=-1){
            return i1;
        }
        else if(i2!=-1){
            return i2;
        }

        return -1;
    }
};
