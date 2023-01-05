#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<long int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            long int right = st.top();
            st.pop();
            long int left = st.top();
            st.pop();
            long int res = 0;
            if (tokens[i] == "+")
                res = left + right;
            else if (tokens[i] == "-")
                res = left - right;
            else if (tokens[i] == "*")
                res = left * right;
            else
                res = left / right;
            st.push(res);
        }
        else
        {
            st.push(stoll(tokens[i]));
        }
    }
    return st.top();
}
int main()
{
    vector<string> v = {"2", "1", "+"};
    evalRPN(v);
}