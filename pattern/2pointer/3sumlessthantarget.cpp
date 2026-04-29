#include <bits/stdc++.h>
using namespace std;
// Count triplets with sum less than target
int countTriplets(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < target) {
                count += (right - left); // all pairs valid
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

//if dublicaTE NOT ALLOWED 
int countTripletsNoDuplicate(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < target) {
                count++; // count only one unique triplet
                
                int leftVal = nums[left];
                int rightVal = nums[right];

                // skip duplicates
                while (left < right && nums[left] == leftVal) left++;
                while (left < right && nums[right] == rightVal) right--;
            } 
            else {
                right--;
            }
        }
    }

    return count;
}






int main() {
    vector<int> nums = {-2, 0, 1, 3};
    int target = 2;

    cout << countTriplets(nums, target);
    return 0;
}