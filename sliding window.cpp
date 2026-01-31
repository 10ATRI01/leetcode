#include<cstdio>
#include<algorithm>
#include<vector>
#include<array>
#include <string>
#include <unordered_map>
#include<unordered_set>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window; // 使用 set 比 map 更快，因为只要判断是否存在
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. 如果当前数字已经在窗口里了，说明找到了距离 <= k 的重复项
            if (window.find(nums[i]) != window.end()) {
                return true;
            }
            
            // 2. 将当前数字放入窗口
            window.insert(nums[i]);
            
            // 3. 保持窗口大小不超过 k
            // 如果窗口里的元素个数超过了 k，就把最老的那个（也就是下标为 i-k 的）删掉
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};

/*
给你一个字符串 s ，它只包含三种字符 a, b 和 c 。

请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0}; // 记录 a, b, c 出现的次数
        int out = 0;
        int i = 0; // 左指针
        int n = s.size();

        for (int j = 0; j < n; j++) {
            // 1. 右指针 j 进场，增加计数
            count[s[j] - 'a']++;

            // 2. 当窗口内 a, b, c 都至少有一个时
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                // 核心逻辑：如果 [i, j] 满足，那么以 i 开头，
                // 结尾为 j, j+1, ..., n-1 的所有子串都满足
                out += n - j;

                // 3. 尝试左指针 i 出场，缩小窗口，寻找下一个可能的 i
                count[s[i] - 'a']--;
                i++;
            }
        }
        return out;
    }
};

/*
给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，
并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。
在执行上述操作后，返回 包含相同字母的最长子字符串的长度。
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0}; // 记录窗口内每个字母出现的次数
        int left = 0;
        int maxCount = 0; // 窗口内出现次数最多的那个字母的次数
        int res = 0;

        for (int right = 0; right < s.size(); right++) {
            // 1. 右指针进场，更新频率
            counts[s[right] - 'A']++;
            // 更新当前窗口内出现频率最高的字符次数
            maxCount = max(maxCount, counts[s[right] - 'A']);

            // 2. 检查窗口是否合法：窗口长度 - 最好看的字符数 > k
            // 如果不合法，左指针右移
            while (right - left + 1 - maxCount > k) {
                counts[s[left] - 'A']--;
                left++;
                // 注意：这里其实不需要重新计算 maxCount
                // 因为只有当 maxCount 变得更大时，才可能产生更长的结果
            }

            // 3. 此时窗口一定是合法的，更新最大长度
            res = max(res, right - left + 1);
        }

        return res;
    }
};