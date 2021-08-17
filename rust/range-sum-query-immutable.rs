struct NumArray {
    sum: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {
    fn new(nums: Vec<i32>) -> Self {
        let mut sum = Vec::new();
        sum.push(0);
        let mut cur = 0i32;
        for num in nums {
            cur += num;
            sum.push(cur); 
        }
        
        Self {
            sum
        }
    }
    
    fn sum_range(&self, left: i32, right: i32) -> i32 {
        &self.sum[(right + 1) as usize] - &self.sum[(left) as usize]
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray::new(nums);
 * let ret_1: i32 = obj.sum_range(left, right);
 */
