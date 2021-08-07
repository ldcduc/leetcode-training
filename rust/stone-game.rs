impl Solution {
    pub fn stone_game(piles: Vec<i32>) -> bool {
        let mut xor_sum = 0;
        for value in piles {
            xor_sum ^= value;
        } 
        xor_sum != 0
    }
}
