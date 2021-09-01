impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        for i in 0..arr.len() {
            for j in 0..arr.len() {
                if i != j && arr[i] * 2 == arr[j] {
                    return true;
                }
            }
        }    
        
        false
    }
}

