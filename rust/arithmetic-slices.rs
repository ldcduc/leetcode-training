impl Solution {
    pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {
        let mut result = 0i32;
        if nums.len() > 2 {
            let mut cur_diff = 0i32;
            let mut prev_diff = nums[1] - nums[0];
            let mut cnt = 0i32;
            for i in 2..nums.len() {
                cur_diff = nums[i] - nums[i - 1];
                if cur_diff == prev_diff {
                    cnt += 1; 
                } else {
                    cnt = 0;
                    prev_diff = cur_diff;
                }
                result += cnt;
            }
        } 
        
        result
    }
}

