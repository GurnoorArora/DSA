class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //the idea is for every bar to look for nearest smallest numer to the right and to the left, that would  basically give the  area that can be formed by that heigh times the width
        vector<int> ns_right;//nearest smaller to right
        vector<int> ns_left; //nearest smaller to the left
        stack<int> st;
        for(int i=0;i<heights.size();i++)
        {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                    //so we have popped out 
                }
                if(st.empty())
                {
                    ns_left.push_back(-1);
                    st.push(i);
                }
                else
                {
                    ns_left.push_back(st.top());
                    st.push(i);

                } 
        }
        //now checking the  nearest smaller indices on the right
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                    //so we have popped out 
                }
                if(st.empty())
                {
                    ns_right.push_back(-1);
                    st.push(i);
                }
                else
                {
                    ns_right.push_back(st.top());
                    st.push(i);

                } 
        }
        //reversing the ns_right list
        reverse(ns_right.begin(),ns_right.end());
        //now we have the list which consists of nearest element in the left and right of a bar
        int maxHeight=0;
        for(int i=0;i<heights.size();i++)
        {
            //ns_left[-1,-1,1,2,1,4]
            //ns_right[1,-1,4,4,4,-1]
            int min_lef_index=ns_left[i];
            int min_right_index=ns_right[i];
            if(ns_left[i]==-1)
            {
                //this means there's nothing smaller for the element in the  right side
                min_lef_index=-1;

            }
            if(ns_right[i]==-1)
            {
                min_right_index=heights.size();
            }
            maxHeight=max(maxHeight,(min_right_index-min_lef_index-1)*heights[i]);
            
        }
        return maxHeight;
    }
};
