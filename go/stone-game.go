func stoneGame(piles []int) bool {
    xorSum := 0
    for _, value := range piles {
        xorSum ^= value 
    }    
    return xorSum != 0
}
