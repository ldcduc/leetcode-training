func arrayNesting(nums []int) int {
    var res = 0
    var cur, prev int
    for i, num := range nums {
        if num != -1 {
            cur = num
            nums[i] = -1;
            count := 1
            for nums[cur] != -1 {
                prev = cur
                cur = nums[cur]
                nums[prev] = -1
                count += 1
            }

            if count > res {
                res = count
            }
        }
    }
    return res
}

