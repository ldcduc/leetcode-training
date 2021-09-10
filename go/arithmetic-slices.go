func numberOfArithmeticSlices(nums []int) int {
    result := 0
    if len(nums) > 2 {
        prev_diff := nums[1] - nums[0]
        cnt := 0
        for i, _ := range nums[2:] {
            cur_diff := nums[i + 2] - nums[i + 1]
            if cur_diff == prev_diff {
                cnt += 1
            } else {
                cnt = 0
                prev_diff = cur_diff 
            }
            result += cnt
        }
    } 
    return result
}

