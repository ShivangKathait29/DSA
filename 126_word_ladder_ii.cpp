class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        vector<vector<string>> ans;

        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end()) return ans;

        queue<vector<string>> q;
        q.push({beginWord});

        st.erase(beginWord);

        bool found = false;

        while(!q.empty()) {

            int sz = q.size();

            unordered_set<string> usedOnLevel;

            for(int k = 0; k < sz; k++) {

                vector<string> path = q.front();
                q.pop();

                string word = path.back();

                if(word == endWord) {
                    ans.push_back(path);
                    found = true;
                    continue;
                }

                for(int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        if(st.find(word) != st.end()) {

                            vector<string> newPath = path;
                            newPath.push_back(word);

                            q.push(newPath);
                            usedOnLevel.insert(word);
                        }
                    }

                    word[i] = original;
                }
            }

            for(auto it : usedOnLevel) {
                st.erase(it);
            }

            if(found) break;
        }

        return ans;
    }
};