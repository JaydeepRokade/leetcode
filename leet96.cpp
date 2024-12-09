class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        intervals.push_back({newInterval[0], newInterval[1]});
        sort(intervals.begin(), intervals.end());
        
        // now apply the logic of merging overlapping intervals
        int n = intervals.size();
        int prev = 0;
        for(int i=1 ; i<n ; i++) {
            if(intervals[i][0] <= intervals[prev][1]) {
                intervals[prev][0] = min(intervals[prev][0], intervals[i][0]);
                intervals[prev][1] = max(intervals[prev][1], intervals[i][1]);
            } else {
                prev++;
                intervals[prev][0] = intervals[i][0];
                intervals[prev][1] = intervals[i][1];
            }
        }
        for(int i=n-1 ; i>prev ; i--) {
            intervals.pop_back();
        }
        return intervals;
    }
};
