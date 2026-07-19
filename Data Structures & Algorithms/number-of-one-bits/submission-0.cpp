class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bin(n);
        return bin.count();
    }
};
