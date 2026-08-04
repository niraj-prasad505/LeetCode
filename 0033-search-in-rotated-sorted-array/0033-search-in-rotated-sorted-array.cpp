class Solution {
private:
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (nums[m] > nums[e]) {
                s = m + 1;
            } else {
                e = m;
            }
        }
        int left = binarySearch(nums, 0, s - 1, target);
        int right = binarySearch(nums, s, nums.size() - 1, target);
        if (left == -1) {
            return right;
        } else {
            return left;
        }
    }
};