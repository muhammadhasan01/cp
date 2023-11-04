vector<int> L(n);
{
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        L[i] = st.empty() ? -1 : st.top();
        st.emplace(i);
    }    
}
vector<int> R(n);
{
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        R[i] = st.empty() ? n : st.top();
        st.emplace(i);
    }
}