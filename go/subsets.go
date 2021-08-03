func subsets(nums []int) [][]int {
    sort.Slice(nums, func(i, j int) bool {
      return nums[i] > nums[j]
    })
    result := [][]int {[]int{}}
    
    n := len(nums)
    base_slice := make(map[int][]int)
    base_slice[0] = []int{}
    for i := 0; i < n; i ++ {
        base_slice[1 << i] = []int {nums[i]}
    }
    
    m := make(map[int][]int)
    m[0] = []int{}
    
    for state := 1; state < (1 << n); state ++ {
        m[state] = append(m[state - (state & -state)], base_slice[state & -state]...)
        arr := make([]int, len(m[state]))
        copy(arr, m[state])
        result = append(result, arr)
    }
    return result
}
