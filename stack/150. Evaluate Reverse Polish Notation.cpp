class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" ||tokens[i]=="*"|| tokens[i]=="/"||tokens[i]=="-")
            {
                int operand1=(st.top());
                st.pop();
                int operand2=(st.top());
                st.pop();
                int result=0;
                if(tokens[i]=="+")
                {
                    result=operand1+operand2;
                }
                else if(tokens[i]=="-")
                {
                    result=operand2-operand1;
                }
                else if(tokens[i]=="*")
                {
                    result=operand1*operand2;
                }
                else
                {
                    result=operand2/operand1;

                }
                st.push((result));
            }
            else
            {
                st.push(stoi(tokens[i]));

            }
        }
        return (st.top());
        
    }
};
