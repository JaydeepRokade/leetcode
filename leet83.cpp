class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
          int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        int ans = INT_MIN;
        int currentsum = 0;
        for(int i = 0; i<n; i++)
        {
            currentsum += arr[i];
            ans = max(ans, currentsum);
            if(currentsum<0) currentsum = 0;
        }
        int frontmax = arr[0];
        int frontsum = arr[0];
        for(int i = 1; i<n; i++)
        {
            sum -= arr[i-1];
            if(frontmax>0)
            {
                int maxi = sum + frontmax;
                ans = max(ans,maxi);
                
            }
            frontsum += arr[i];
            frontmax = max(frontmax,frontsum);
            
        }
        return ans;
    }
};
