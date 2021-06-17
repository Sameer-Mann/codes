class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int left, int right) {
        int n = a.size();
        vector<int>lf(n),rt(n),st;
        for(int i =0;i<n;i++){
            while(st.size() and a[st.back()]<a[i])st.pop_back();
            if(st.size())lf[i] = st.back();
            else lf[i] = -1;
            st.push_back(i);
        }
        st.clear();
        for(int i = n-1;i>=0;i--){
            while(st.size() and a[st.back()]<=a[i])st.pop_back();
            if(st.size())rt[i]=st.back();
            else rt[i] = n;
            st.push_back(i);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(a[i]>=left and a[i]<=right){
                ans += (rt[i]-i - 1)*(i-lf[i] - 1);
                ans += rt[i]-i;
                ans += i-lf[i]-1;
            }
        }
        return ans;
    }
};