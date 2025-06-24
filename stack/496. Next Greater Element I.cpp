class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //from nums1 we need to find the next greate in nums 2 
        unordered_map<int,int> umap;
        vector<int> result;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
             while(!st.empty()&& nums2[i]>=st.top())
             {
                st.pop();
             }
             if(st.empty())
             {
                //this means the stack has now become empty
                umap[nums2[i]]=-1;
             }
             else
             {
                //this means a greater element has been found
                umap[nums2[i]]=st.top();
             }
             st.push(nums2[i]);
        }
       for(int i=0;i<nums1.size();i++)
       {
        nums1[i]=umap[nums1[i]];
       }
       

        
    
   

    return nums1;
    }
};
