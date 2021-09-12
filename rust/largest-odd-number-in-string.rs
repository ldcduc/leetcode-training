
impl Solution {
    pub fn largest_odd_number(num: String) -> String {
        let last_odd_index = num
            .char_indices()
            .filter(|(_, c)| (*c as u8) % 2 == 1)
            .last();

        match last_odd_index {
            None => "",
            Some((i, _)) => &num[..=i as usize],
        }
        .to_string()
    }
}

impl Solution {
    pub fn largest_odd_number(num: String) -> String {
        let n = num.len();
        for (i, ch) in num.chars().rev().enumerate() {
            if (ch as u8 - '0' as u8) % 2 == 1 {
                return (&num[..n - i]).to_string();
            }
        }
        
        "".to_string()
    }
}

