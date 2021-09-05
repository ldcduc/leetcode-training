func orderlyQueue(s string, k int) string {
    if k == 1 {
        res := s
        double := s + s
        for i, _ := range s { 
            tmp := double[i : i + len(s)]
            if tmp < res {
                res = tmp
            }
        }
        return res
    }    
    chars := strings.Split(s, "")
    sort.Strings(chars)
    return strings.Join(chars, "")
}

