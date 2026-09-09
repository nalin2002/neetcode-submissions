class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


        unordered_set<string> words(wordList.begin(), wordList.end());
        
        if (words.find(endWord) == words.end()) {
            return 0;
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1}); 

        while (!q.empty()) {

            auto [currWord, dist] = q.front();
            q.pop();

            if (currWord == endWord) {
                return dist;
            }

            
            for (int i = 0; i < currWord.size(); i++) {
                char originalChar = currWord[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue;
                    
                    currWord[i] = c;

                    if (words.count(currWord)) {
                        q.push({currWord, dist + 1});
                        words.erase(currWord); 
                    }
                }

                currWord[i] = originalChar; 
            }
        }

        return 0;
    }
};
