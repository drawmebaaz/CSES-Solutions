#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& arr) {

    int n = arr.size();
    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(),arr[i]) - ans.begin();
            ans[low] = arr[i];
        }
    }

    return ans.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int a = lengthOfLIS(arr);
    reverse(arr.begin(), arr.end());
    int b = lengthOfLIS(arr);
    cout << max(a,b) << endl;
    return 0;
}