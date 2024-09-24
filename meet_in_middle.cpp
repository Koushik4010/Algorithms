class Solution {
public:
    
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2;
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        
        vector<vector<int>> left(n+1),right(n+1);

        for(int mask=0;mask<(1<<n);mask++){
            int sz=0,suml=0,sumr=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    sz++;
                    suml+=nums[i];
                    sumr+=nums[i+n];
                }
            }
            left[sz].push_back(suml);
            right[sz].push_back(sumr);
        }
        
        for(int i=0;i<=n;i++){
            sort(right[i].begin(),right[i].end());
        }

        int ans=INT_MAX;
         
        for(int i=0;i<=n;i++){
            for(auto sum1:left[i]){
                int target=(totalsum-2*sum1)/2;
                auto it=lower_bound(right[n-i].begin(),right[n-i].end(),target);

                if(it!=right[n-i].end()){
                    int sum2=*it;
                    ans=min(ans,abs(totalsum-2*(sum1+sum2)));
                }
                if(it!=right[n-i].begin()){
                    int sum2=*(prev(it));
                    ans=min(ans,abs(totalsum-2*(sum1+sum2)));
                }
            }
        }
        

        return ans;

    }
};
