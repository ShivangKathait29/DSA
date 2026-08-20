class Solution {
public:
    bool can(vector<int>& arr, int i, vector<int>& vis) {
        if (arr[i] == 0) return true;

        if (vis[i]) return false;
        vis[i] = 1;

        bool right = false, left = false;

        if (i + arr[i] < arr.size())
            right = can(arr, i + arr[i], vis);

        if (i - arr[i] >= 0)
            left = can(arr, i - arr[i], vis);

        return right || left;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return can(arr, start, vis);
    }
};