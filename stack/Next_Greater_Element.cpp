class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        int size=arr.size();
        vector<int> result;
        for(int i=size-1;i>=0;i--)
        {
            if(st.empty())
            {
                result.push_back(-1);
                st.push(arr[i]);
            }
            else
            {
                if(arr[i]<st.top())
                {
                    result.push_back(st.top());
                    st.push(arr[i]);
                }
                else
                {
                    while(!st.empty() && arr[i]>=st.top())
                    {
                        st.pop();
                    }
                    if(st.empty())
                    {
                        result.push_back(-1);
                    }
                    else
                    {
                        result.push_back(st.top());
                    }
                    st.push(arr[i]);

                }

            }
            
            
            
        }
        
        //reversing the result
        reverse(result.begin(),result.end());
        return result;
        
    }
};
