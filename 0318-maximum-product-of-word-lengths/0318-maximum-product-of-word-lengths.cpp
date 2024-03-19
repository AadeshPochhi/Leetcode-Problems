class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        unordered_map<int, int> hashmap;
        auto bitNumber = [](char ch) -> int {
            return ch - 'a';
        };
        for (const string& word : words) {
            int bitmask = 0;
            for (char ch : word) {
                bitmask |= 1 << bitNumber(ch);
            }
            hashmap[bitmask] = max(hashmap[bitmask], static_cast<int>(word.length()));
        }

        int maxProduct = 0;
        for (auto it1 = hashmap.begin(); it1 != hashmap.end(); ++it1) {
            for (auto it2 = hashmap.begin(); it2 != hashmap.end(); ++it2) {
                if ((it1->first & it2->first) == 0) {
                    maxProduct = std::max(maxProduct, it1->second * it2->second);
                }
            }
        }

        return maxProduct;
    }
};