class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here fvs fs vss vd myj g jiuk ,k, uu
        int n = arr.size();
        int d = arr[1] - arr[0];
        
        for(int i=0; i<n-1; i++){
            
            int diff = arr[i+1] - arr[i];
            if(d != diff){
                return arr[i+1] - d;
            }
        }
        return arr[n-1] + d;
    }
};

