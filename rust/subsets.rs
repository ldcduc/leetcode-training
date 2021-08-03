impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        nums.reverse();
        let mut result: Vec<Vec<i32>> = vec![vec![]];

        let n = nums.len();
        let mut base_slice: Vec<Vec<i32>> = vec![vec![]; 1 << n];
        base_slice[0] = vec![];
        
        for i in 0..n {
            base_slice[1 << i] = vec![nums[i]];
        }

        let mut m: Vec<Vec<i32>> = vec![vec![]; 1 << n];
        m[0] = vec![];

        for i in 1..(1 << n) {
            let state = i as i32;
            let mut arr = vec![];
            arr.extend(m[(state - (state & -state)) as usize].clone());
            arr.extend(base_slice[(state & -state) as usize].clone());
            m[state as usize] = arr;
            result.push(m[state as usize].clone())
        }
        
        result    
    }
}
