/* Problem url: https://leetcode.com/problems/maximum-product-subarray
 * Code by: ldcduc
 * */
/* Begin of Solution */
class SimpleSolution {
public:
    int maxProduct(vector<int>& nums) {
        if (!nums.empty()) {
            int result = nums[0];
            int maxSub = nums[0];
            int minSub = nums[0];
            for (int i = 1; i < nums.size(); ++ i) {
                if (nums[i] < 0) {
                    swap(maxSub, minSub);
                }
                maxSub = max(maxSub * nums[i], nums[i]); 
                minSub = min(minSub * nums[i], nums[i]);
                result = max(result, maxSub); 
            }
            return result;
        }
        return 0;
    }
};

class Solution {
public:
    vector<long long> products;
    vector<long long> denominators;
    long long productByRange(int start, int end) {
        if (start <= end) {
            return products[end] / denominators[start];
        }    
        return 1ll << 63;
    }
    long long calculate(vector<int>& pos, int startPosition, int endPosition) {
        if (pos.size() % 2 == 0) {
            return productByRange(startPosition, endPosition);
        } else {
            long long product1 = productByRange(startPosition, pos.back() - 1);
            long long product2 = productByRange(pos.front() + 1, endPosition);
            return max(product1, product2);
        }        
    }
    int maxProduct(vector<int>& nums) {
        long long result = 1ll << 63;
        nums.push_back(0);
        vector<int> negativePos;
        int startPosition = 0, cntZero = 0;
        long long prod = 1;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == 0) {
                denominators.push_back(1);
                prod = 1;
                products.push_back(0);
                
                ++ cntZero;
                result = max(result, calculate(negativePos, startPosition, i - 1));
                negativePos.clear();
                startPosition = i + 1;
            } else {
                denominators.push_back(prod);
                prod *= nums[i];
                products.push_back(prod);
                
                if (nums[i] < 0) {
                result = result < nums[i] ? nums[i] : result;
                negativePos.push_back(i);
                }    
            }
        }
        return (cntZero > 1 && result < 0) ? 0 : result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, implementation, careful, trick
 * 
 * */
