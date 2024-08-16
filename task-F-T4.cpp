#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string s){
    stack<char> st;
    st.push(s[0]);
    for(int i=1; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='(')
                st.pop();
            else
                return false;
        }
        else if(s[i]=='}'){
            if(!st.empty() && st.top()=='{')
                st.pop();
            else
                return false;
        }
        else if(s[i]==']'){
            if(!st.empty() && st.top()=='[')
                st.pop();
            else
                return false;
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}
int main()
{
    string s;
    cin>>s;
    if(isBalanced(s)){
        cout<<1;
    }else{
        cout<<-1;
    }
    return 0;
}
