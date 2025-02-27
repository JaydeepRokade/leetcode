#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index_map; 
        unordered_map<int, int> dp; 
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            index_map[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int x = arr[i] - arr[j]; 
                if (x < arr[j] && index_map.find(x) != index_map.end()) {
                    int k = index_map[x]; 
                    int len = dp[k * n + j] + 1;
                    dp[j * n + i] = max(3, len);
                    max_len = max(max_len, dp[j * n + i]);
                } else {
                    dp[j * n + i] = 2;
                }
            }
        }
        return max_len >= 3 ? max_len : 0;
    }
};
