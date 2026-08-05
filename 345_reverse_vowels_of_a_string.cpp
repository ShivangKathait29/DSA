class Solution {
public:
    bool isVowel(char c){
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
        c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        string ans;
        int n = s.size();
        int i=0,j=n-1;
        while(i<j){
            while(i<j && !isVowel(s[i])){
                i++;
            }
            while(i<j && !isVowel(s[j])){
                j--;
            }

            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        int k = 0;
        while(k<n){
            ans+=s[k];
            k++;
        }
        return ans;
    }
};