class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<char, vector<char>, greater<char>> pq;  // Min-heap
        unordered_map<char, vector<int>> m;  // Stores 
        vector<bool> v(n, true);  // Marks
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                char temp = pq.top();  // Get smalle
                pq.pop();
                int last = m[temp].back();  // Get last occu
                m[temp].pop_back();
                v[i] = false;       // Remove '*'
                v[last] = false;    // Remove 
            } else {
                pq.push(s[i]);
                m[s[i]].push_back(i);
            }
        }

        string result = "";
        for (int i = 0; i < n; i++) {
            if (v[i]) result += s[i];
        }
        return result;
    }
};
