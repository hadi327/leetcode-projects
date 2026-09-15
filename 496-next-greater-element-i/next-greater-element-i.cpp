class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        unordered_map<int, int> next;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                next[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        vector<int> result;

        for (int num : nums1) {
            if (next.count(num))
                result.push_back(next[num]);
            else
                result.push_back(-1);
        }

        return result;
    }
};