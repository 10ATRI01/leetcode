#include<cstdio>
#include<algorithm>
#include<vector>
#include<array>

#include <unordered_map>
#include<unordered_set>

using namespace std;

/*
Q2. 使数组和能被 P 整除

给你个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 
子数组 定义为原数组中连续的一组元素
示例 1：
输入：nums = [3,1,4,2], p = 6
输出：1
解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
示例 2：
输入：nums = [6,3,5,2], p = 9
输出：2
解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
示例 3：
输入：nums = [1,2,3], p = 3
输出：0
解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
示例  4：
输入：nums = [1,2,3], p = 7
输出：-1
解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
示例 5：
输入：nums = [1000000000,1000000000,1000000000], p = 3
输出：0


sum[j]%p==sum[i]-target+p)%p

*/

// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p) {
//         // 1. 计算总余数，使用 long long 防止溢出
//         long long total_sum = 0;
//         for (int num : nums) total_sum += num;
//         int target = total_sum % p;

//         if (target == 0) return 0; // 已经能整除

//         // 2. 初始化
//         unordered_map<int, int> pos_map;
//         pos_map[0] = -1; // 前缀和余数为0出现在-1位置
        
//         int n = nums.size();
//         int min_len = n; // 记录最短长度
//         int cur_rem = 0;

//         // 3. 遍历数组
//         for (int i = 0; i < n; i++) {
//             // 计算当前前缀和的余数
//             cur_rem = (cur_rem + nums[i]) % p;
            
//             // 计算我们需要找的那个“以前的余数”
//             int need = (cur_rem - target + p) % p;

//             // 4. 在哈希表中找 need
//             if (pos_map.find(need) != pos_map.end()) {
//                 // 更新最短长度，不要直接 return
//                 min_len = min(min_len, i - pos_map[need]);
//             }

//             // 5. 存入当前余数的位置（如果已存在则覆盖，保证拿到的永远是最新的、最近的下标）
//             pos_map[cur_rem] = i;
//         }

//         // 6. 如果 min_len 还是初始值，或者等于数组长度n（题目不允许移除整个数组），返回-1
//         return (min_len >= n) ? -1 : min_len;
//     }
// };


/*
Q3. 生成平衡数组的方案数
中等
相关标签
premium lock icon
相关企业
提示
给你一个整数数组 nums 。你需要选择 恰好 一个下标（下标从 0 开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。

比方说，如果 nums = [6,1,7,4,1] ，那么：

选择删除下标 1 ，剩下的数组为 nums = [6,7,4,1] 。
选择删除下标 2 ，剩下的数组为 nums = [6,1,4,1] 。
选择删除下标 4 ，剩下的数组为 nums = [6,1,7,4] 。
如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 平衡数组 。

请你返回删除操作后，剩下的数组 nums 是 平衡数组 的 方案数 。
*/


class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd_num_sum=0;
        int even_sum=0;
        int out=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(j==i)continue;
                if(j<i){
                    if(j%2==0)even_sum+=nums[j];
                    else odd_num_sum+=nums[j];
                }
                else{
                    if(j%2==0)odd_num_sum+=nums[j];
                    else even_sum+=nums[j];
                }
            }
            if(even_sum==odd_num_sum)out++;
            even_sum=0;
            odd_num_sum=0;
        }
        return  out;

    }
};