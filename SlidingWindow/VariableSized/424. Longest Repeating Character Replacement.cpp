class Solution {
public:
    
    int characterReplacement(string s, int k) {
        int start=0;
        int end=0;
        int size=s.size();
        int max_=0;
        int max_win=0;
        unordered_map<char,int> umap;
        while(end<size)
        {
            umap[s[end]]++;
            max_=max(max_,umap[s[end]]);
            if((end-start+1)-max_<=k)
            {
                max_win=max(max_win,end-start+1);
                end++;
            }
            else
            {
                umap[s[start]]--;
                start++;
                end++;
            }
        }
        
        return max_win;
        
    }
};
