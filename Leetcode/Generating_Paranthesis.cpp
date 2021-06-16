bool check(string s){
    stack<bool>st;
    for(char ch:s){
        if(ch=='(')st.push(1);
        else{
            if(st.empty())return false;
            st.pop();
        }
    }
    if(!st.empty())return false;
    return true;
}
void f(int n,string s,vector<string>&ans){
    if(n==0){
        if(check(s))ans.push_back(s);
        return;
    }
    f(n-1,s+"(",ans);
    f(n-1,s+")",ans);
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        n<<=1;
        vector<string>ans;
        f(n,"",ans);
        return ans;
    }
};