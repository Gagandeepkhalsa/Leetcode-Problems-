#include <vector>
#include <cstring>
#include <algorithm>

class Solution {
public:
    int maximumLength(std::vector<int>& nums, int k) {
        int remainderCount[k][k];
        std::memset(remainderCount, 0, sizeof(remainderCount));
        
        int maxLength = 0;
        
        for (int num : nums) {
            int modValue = num % k;
            
            for (int remainder = 0; remainder < k; ++remainder) {
                int targetRemainder = (remainder - modValue + k) % k;
                
                remainderCount[modValue][targetRemainder] = remainderCount[targetRemainder][modValue] + 1;
                
                maxLength = std::max(maxLength, remainderCount[modValue][targetRemainder]);
            }
        }
        
        return maxLength;
    }
};