class Solution {
    public:
        int search(vector<int>& nums, int target) {
            return method2(nums, target);
        }

        /******************************************************************************
        * Function:         int method2
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method1(vector<int>& nums, int target){
            if (nums.size() == 0) { return -1; }
            int l = 0, r = nums.size() - 1;
            // find the pivot: which is always the smallest one
            /* 5 1 3 */

            /* l 0 2 */ 
            /* v 5 3 */

            /* r 2 2 */
            /* v 3 3 */

            /* m 1 2 */
            /* v 1 3 */

            while (l < r) {
                int m = l + (r - l) / 2;
                // decreasing
                if (nums[m] > nums[r]) { l = m + 1; }
                else { r = m; }
            }
            /* cout << l << " num is: " << nums[l] << endl; */
            /* cout << r << endl; */
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int realMid = (mid + l) % nums.size();
                if (nums[realMid] == target) { return realMid; }
                if (nums[realMid] < target) { left = mid + 1; }
                else { right = mid - 1; }
            }
            return -1;
        }

        /******************************************************************************
        * Function:         int method2
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method2(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    return mid;
                // right is in ascending order
                } else if (nums[mid] < nums[right]) {
                    // in range of mid and right
                    if (nums[mid] < target && nums[right] >= target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    // in range of left and mid
                    if (nums[left] <= target && nums[mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            return -1;
        }

};
