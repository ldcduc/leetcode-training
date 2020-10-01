#The list of LeetCode problems which I've made a lot of bugs implementing the solution.  

| Problem name | Hint |
|---|---|
| [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray) | <details close><summary>Spoiler alert!!</summary> - Instead of using the trick of accumulative sum `sum[end] - sum[left - 1]` &rarr; which makes bad behavior with 0 in the products &rarr; maintain 2 array `products` (accumulative products) and `denominators`, thus the multiplication from `[start .. end]` will be `products[end] / denominators[start]` <br> - Some corner cases `[0,2]`, `[0]`, `[-2]` (odd number of negatives) </details>