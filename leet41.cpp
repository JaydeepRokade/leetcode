lclass Solution {
public:
    bool rotateString(string s, string goal) {
        int ln = s.length();
        for(int i =0;i<ln;i++){
            s += s[i];
            string sub = s.substr(i+1,ln+1);
            if(sub == goal) return true;
        }
        return false;
    }
};
