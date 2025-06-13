class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> umap1;
        unordered_map<char,int> win_map;
        for(char c:s1)
        {
            umap1[c]++;
        }
        int start=0;
        int end=0;
        while(end<s2.size())
        {
            win_map[s2[end]]++;

            if(end-start+1==s1.size())
            {
                if(win_map==umap1) return  true;
                win_map[s2[start]]--;
                if(win_map[s2[start]]==0)
                {
                    win_map.erase(s2[start]);
                }
                start++;

            }
            end++;


        }

        return false;
        
    }
};
