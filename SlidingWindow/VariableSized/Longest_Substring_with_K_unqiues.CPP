// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int start=0;
        int end=0;
        int max_window=-1;
        unordered_map<char,int> umap;
        while(end<s.size())
        {
            umap[s[end]]++;
            
            if(umap.size()==k)
            {
                
                max_window=max(max_window,end-start+1);
            }
            
            while(umap.size()>k)
            {
                umap[s[start]]--;
                if(umap[s[start]]==0)
                {
                    umap.erase(s[start]);
                }
                start++;
            }
            end++;
        }
        
        return max_window;
    }

};
