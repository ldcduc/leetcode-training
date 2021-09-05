use std::cmp;
impl Solution {
    pub fn orderly_queue(s: String, k: i32) -> String {
        if k == 1 {
            let mut res = s.clone();
            let double: String = [s.clone(), s.clone()].join(""); 
            for i in 0..s.len() {
                let tmp = &double[i..i + s.len()];
                let tmp : String = tmp.into();
                res = cmp::min(res, tmp).clone();
            }
            
            res
        } else {
            let mut characters: Vec<char> = s.chars().collect();
            characters.sort();
            
            characters.iter().collect()
        }   
    }
}

// sugyan's solution
// https://leetcode.com/problems/orderly-queue/discuss/1446287/Rust-solution
impl Solution {
    pub fn orderly_queue(s: String, k: i32) -> String {
        if k == 1 {
            let ss = s.chars().chain(s.chars()).collect::<Vec<_>>();
            let mut v = ss.windows(s.len()).collect::<Vec<_>>();
            v.sort();
            v[0].iter().copied().collect()
        } else {
            let mut v = s.chars().collect::<Vec<_>>();
            v.sort();
            v.iter().collect()
        }
    }
}

