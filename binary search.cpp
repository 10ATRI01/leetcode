#include<cstdio>
#include<algorithm>
#include<vector>
#include<array>

#include <unordered_map>
#include<unordered_set>

using namespace std;

/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
写一个函数搜索 nums 中的 target，
如果 target 存在返回下标，否则返回 -1。
你必须编写一个具有 O(log n) 时间复杂度的算法。
示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
*/

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int pre=0;
//         int rear=nums.size()-1;
//         while(pre<=rear){
//             if(target==nums[(pre+rear)/2])return (pre+rear)/2;
//             if(target>nums[(pre+rear)/2])pre=(pre+rear)/2+1;
//             else rear=(pre+rear)/2-1;
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         // 黑科技：关闭同步流，加快执行速度，有时能间接影响内存判定
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);

//         int pre = 0;
//         int rear = nums.size() - 1;

//         while (pre <= rear) {
//             // 优化 1：防止溢出（虽然这题数据范围不会溢出，但是好习惯）
//             // 如果 pre 和 rear 都很大，pre + rear 可能会超过 int 范围
//             int mid = pre + (rear - pre) / 2; 

//             if (nums[mid] == target) {
//                 return mid;
//             } else if (nums[mid] < target) {
//                 pre = mid + 1;
//             } else {
//                 rear = mid - 1;
//             }
//         }
//         return -1;
//     }
// };



