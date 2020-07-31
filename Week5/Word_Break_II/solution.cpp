class Solution {
private:
    vector<string> wordBreakHelper(string s, unordered_set<string>& wordSet, unordered_map<string,vector<string>>& map) {
        
        if(map.find(s) != map.end()) return map[s];
        
        vector<string> result;
        
        if(s.empty()) {
            result.push_back("");
            return result;
        }
        
        for(int i = 1; i <= s.size(); ++i) {
            string left = s.substr(0, i);
            
            if(wordSet.find(left) != wordSet.end()) {
                vector<string> subList = wordBreakHelper(s.substr(i), wordSet, map);
                
                for(string sen: subList) {
                    sen = sen.empty() ? sen : " " + sen;
                    result.push_back(left + sen);
                }
            }
        }
        
        map[s] = result;
        return result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        unordered_map<string,vector<string>> map;
        
        for(string word: wordDict)
            wordSet.insert(word);
        
        return wordBreakHelper(s, wordSet, map);
    }
};