func twoSum(nums []int, target int) []int {
    var m map[int]int = make(map[int]int)    
    for i, value := range nums {
        if m[target - value] != 0{ 
            return []int {m[target - value] - 1, i}
        } 
        m[value] = i + 1
    }
    return []int {}
}
