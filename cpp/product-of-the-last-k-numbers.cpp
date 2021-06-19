/* Problem url: https://leetcode.com/problems/product-of-the-last-k-numbers
 * Code by: ldcduc
 * */
/* Begin of Solution */
class ProductOfNumbers {
public:
    vector<int> products, denum, zeroCnt;
    int size;
    ProductOfNumbers() {
        size = 0;    
    }
    
    void add(int num) {
        if (products.empty()) {
            denum.push_back(1);
            products.push_back(num);
            zeroCnt.push_back(num == 0);
        } else if (num == 0) {
            denum.push_back(1);
            products.push_back(0);
            zeroCnt.push_back(zeroCnt.back() + 1);
        } else {
            denum.push_back(products.back() ? products.back() : 1);
            products.push_back(products.back() ? products.back() * num : num);
            zeroCnt.push_back(zeroCnt.back());
        }
        ++ size;
    }
    
    int getProduct(int k) {
        if (zeroCnt.back() - (size > k ? zeroCnt[size - k - 1] : 0)) {
            return 0;
        }
        return products.back() / denum[size - k];    
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: accumulated product
 * 
 * */
