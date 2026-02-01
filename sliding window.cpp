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

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_set<int> window; // 使用 set 比 map 更快，因为只要判断是否存在
        
//         for (int i = 0; i < nums.size(); i++) {
//             // 1. 如果当前数字已经在窗口里了，说明找到了距离 <= k 的重复项
//             if (window.find(nums[i]) != window.end()) {
//                 return true;
//             }
            
//             // 2. 将当前数字放入窗口
//             window.insert(nums[i]);
            
//             // 3. 保持窗口大小不超过 k
//             // 如果窗口里的元素个数超过了 k，就把最老的那个（也就是下标为 i-k 的）删掉
//             if (window.size() > k) {
//                 window.erase(nums[i - k]);
//             }
//         }
        
//         return false;
//     }
// };

// /*
// 给你一个字符串 s ，它只包含三种字符 a, b 和 c 。

// 请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
// */

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int count[3] = {0, 0, 0}; // 记录 a, b, c 出现的次数
//         int out = 0;
//         int i = 0; // 左指针
//         int n = s.size();

//         for (int j = 0; j < n; j++) {
//             // 1. 右指针 j 进场，增加计数
//             count[s[j] - 'a']++;

//             // 2. 当窗口内 a, b, c 都至少有一个时
//             while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
//                 // 核心逻辑：如果 [i, j] 满足，那么以 i 开头，
//                 // 结尾为 j, j+1, ..., n-1 的所有子串都满足
//                 out += n - j;

//                 // 3. 尝试左指针 i 出场，缩小窗口，寻找下一个可能的 i
//                 count[s[i] - 'a']--;
//                 i++;
//             }
//         }
//         return out;
//     }
// };

// /*
// 给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，
// 并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。
// 在执行上述操作后，返回 包含相同字母的最长子字符串的长度。
// */

// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int counts[26] = {0}; // 记录窗口内每个字母出现的次数
//         int left = 0;
//         int maxCount = 0; // 窗口内出现次数最多的那个字母的次数
//         int res = 0;

//         for (int right = 0; right < s.size(); right++) {
//             // 1. 右指针进场，更新频率
//             counts[s[right] - 'A']++;
//             // 更新当前窗口内出现频率最高的字符次数
//             maxCount = max(maxCount, counts[s[right] - 'A']);

//             // 2. 检查窗口是否合法：窗口长度 - 最好看的字符数 > k
//             // 如果不合法，左指针右移
//             while (right - left + 1 - maxCount > k) {
//                 counts[s[left] - 'A']--;
//                 left++;
//                 // 注意：这里其实不需要重新计算 maxCount
//                 // 因为只有当 maxCount 变得更大时，才可能产生更长的结果
//             }

//             // 3. 此时窗口一定是合法的，更新最大长度
//             res = max(res, right - left + 1);
//         }

//         return res;
//     }
// };

// /*
// 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。
// 找到并返回可以用这种方式转换的最短回文串。
// */
// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         int remainder=100000007;
//         int base=31;
//         int last_huiwen=-1;
//         long long int left_sum=0;
//         long long int right_sum=0;
//         int now=0;
//         long long mul=1;

//         while(now!=s.size()){
//             left_sum=(left_sum*31+s[now])%remainder;
//             // 【反向更新】：新字符变成最高位，加在原来的数前面
//             // 就像：1 -> 21 -> 321
//             right_sum = (right_sum + s[now] * mul) % remainder;
//             // 更新下一次的权重
//             mul = (mul * 31) % remainder;
//             if(left_sum==right_sum){
//                 last_huiwen=now;
//             }
//             now++;
//         }
//                 // 1. 截取后缀（即不是回文的部分）
//         string suffix = s.substr(last_huiwen+1); 

//         // 2. 翻转这个后缀
//         reverse(suffix.begin(), suffix.end()); 

//         // 3. 拼接到前面并返回
//         return suffix + s;
//     }
// };


/*
「快乐前缀」 是在原字符串中既是 非空 前缀也是后缀（不包括原字符串自身）的字符串。
给你一个字符串 s，请你返回它的 最长快乐前缀。如果不存在满足题意的前缀，则返回一个空字符串 "" 
*/

// class Solution {
// public:
//     string longestPrefix(string s) {
//         int remainder=100000007;
//         int base=31;       
//         long long int left_sum=0;
//         long long int right_sum=0;
//         long long int mul=1;
//         int max=0;
//         int reverse_i=0;
//         string out;
//         for(int i=0;i<s.size()-1;i++){
//             reverse_i=s.size()-i-1;
//             left_sum=(left_sum*base+s[i])%remainder;
//             right_sum=(right_sum+s[reverse_i]*mul)%remainder;
//             mul=(mul*base)%remainder;
//             if(left_sum==right_sum){
//                 //更新输出
//                 max=i+1;
//             }
//         }
//         out=s.substr(0,max);
//         return out;
        
//     }
// };

/*
你需要从空字符串开始 构造 一个长度为 n 的字符串 s ，
构造的过程为每次给当前字符串 前面 添加 一个 字符。
构造过程中得到的所有字符串编号为 1 到 n ，其中长度为 i 的字符串编号为 si 。
比方说，s = "abaca" ，s1 == "a" ，s2 == "ca" ，s3 == "aca" 依次类推。
si 的 得分 为 si 和 sn 的 最长公共前缀 的长度（注意 s == sn ）。
给你最终的字符串 s ，请你返回每一个 si 的 得分之和 。
*/
//z算法

class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        // 1. z 数组：z[i] 表示从下标 i 开始的后缀与原串的最长公共前缀长度
        vector<int> z(n, 0);
        
        // 2. sum 必须用 long long，防止 10^5 长度的字符串累加时溢出
        // 初始值为 n，因为字符串本身（s_n）与自己的公共前缀长度就是 n
        long long sum = n; 
        
        // 3. l 和 r 维护当前的“匹配窗口”（克隆区）
        int l = 0, r = 0;
        
        for (int i = 1; i < n; i++) {
            // 情况 A：如果在窗口内，先通过双胞胎抄答案，但不能超过窗口边界
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            
            // 情况 B：无论抄了多少，尝试继续暴力向后扩展
            // 比较后缀字符 s[i + z[i]] 和前缀字符 s[z[i]]
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            
            // 4. 如果新的匹配终点超过了旧的 r，更新窗口边界 [l, r]
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
            
            // 5. 累加每一个后缀的得分
            sum += z[i];
        }
        
        return sum;
    }
};



int main(){
    string s="bababcde";
    Solution plan;
    plan.sumScores(s);
    return 0;
}