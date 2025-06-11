class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int end=0;
        int max_=0;
        unordered_map<char,int>  umap;
        while(end<s.size())
        {
            if(umap.find(s[end])==umap.end())
            {
                umap[s[end]]++;
                end++;
                 max_=max(max_,end-start);

            }
            else
            {
                //there's a duplicate
                //remove the first occurences 
                while(umap.find(s[end])!=umap.end())
                {
                    umap[s[start]]--;
                    if(umap[s[start]]==0)
                    {
                        umap.erase(s[start]);
                    }
                    start++;
                }
                
            }

        }
        return  max_;
        
    }
};
