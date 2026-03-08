class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string temp = "";
        for(int i=0; i<n; i++){
            if(isalpha(s[i])){
                s[i] = tolower(s[i]);
                temp.push_back(s[i]);
            }
            if(s[i] >= '0' && s[i] <= '9')
                temp.push_back(s[i]);
        }
        
        int size = temp.size();
        for(int i=0; i<size/2; i++){
            if(temp[i] != temp[size-i-1])
                return false;
        }
        return true;
    }
};