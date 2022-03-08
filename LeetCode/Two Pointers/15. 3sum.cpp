class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();

        int pzero;
        for (pzero = 0; pzero < size; ++pzero)
            if (nums[pzero] >= 0)
                break;
        if (size < 3 || pzero == size) {
            vector<vector<int>> n;
            return n;
        }

        vector<vector<int>> out;
        for (int i = 0; i <= pzero; ++i) {
            int ni = nums[i];

            int j = i + 1;
            int k = size - 1;
            while (j < k) {
                int sum = ni + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> v{ ni, nums[j], nums[k] };
                    out.push_back(move(v));

                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    ++j;
                    while (j < k && nums[k] == nums[k - 1]) --k;
                    --k;
                }
                else if (sum < 0)
                    ++j;
                else
                    --k;
            }
            while (i < pzero && nums[i] == nums[i + 1]) ++i;
        }

        return out;
    }
};