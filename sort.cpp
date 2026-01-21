#include<cstdio>
#include<algorithm>
#include<vector>
#include<array>

#include <unordered_map>
#include<unordered_set>
#include <map>
using namespace std;


/*
给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

每对元素对 [a,b] 如下：

a , b 均为数组 arr 中的元素
a < b
b - a 等于 arr 中任意两个元素的最小绝对差
 

示例 1：

输入：arr = [4,2,1,3]
输出：[[1,2],[2,3],[3,4]]
示例 2：

输入：arr = [1,3,6,10,15]
输出：[[1,3]]
示例 3：

输入：arr = [3,8,-10,23,19,-4,-14,27]
输出：[[-14,-10],[19,23],[23,27]]
 
*/

// class Solution {
// public:
//     vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
//         int min=INT16_MAX;
//         //先从小到大排序，然后相减
//        sort(arr.begin(),arr.end());
//         for(int i=0;i<arr.size()-1;i++){
//             if((arr[i+1]-arr[i])<min)min=arr[i+1]-arr[i];
//         }
//         vector<vector<int>>out;
//         unordered_map<int,int>map;
//         for(int i=0;i<arr.size();i++){
//             if (auto it = map.find(arr[i] - min); it != map.end())
//             {
//                 out.push_back({it->second,arr[i]});
//             }
//             if (auto it = map.find(arr[i] + min); it != map.end()){
//                 out.push_back({arr[i],it->second});
//             }
//             map[arr[i]] = arr[i];
//         }
//         return out;
//     }
// };


/*
给你一个整数数组 nums ，你的目标是令 nums 中的所有元素相等。完成一次减少操作需要遵照下面的几个步骤：

找出 nums 中的 最大 值。记这个值为 largest 并取其下标 i （下标从 0 开始计数）。如果有多个元素都是最大值，则取最小的 i 。
找出 nums 中的 下一个最大 值，这个值 严格小于 largest ，记为 nextLargest 。
将 nums[i] 减少到 nextLargest 。
返回使 nums 中的所有元素相等的操作次数。
示例 1：

输入：nums = [5,1,3]
输出：3
解释：需要 3 次操作使 nums 中的所有元素相等：
1. largest = 5 下标为 0 。nextLargest = 3 。将 nums[0] 减少到 3 。nums = [3,1,3] 。
2. largest = 3 下标为 0 。nextLargest = 1 。将 nums[0] 减少到 1 。nums = [1,1,3] 。
3. largest = 3 下标为 2 。nextLargest = 1 。将 nums[2] 减少到 1 。nums = [1,1,1] 。
示例 2：

输入：nums = [1,1,1]
输出：0
解释：nums 中的所有元素已经是相等的。
示例 3：

输入：nums = [1,1,2,2,3]
输出：4
解释：需要 4 次操作使 nums 中的所有元素相等：
1. largest = 3 下标为 4 。nextLargest = 2 。将 nums[4] 减少到 2 。nums = [1,1,2,2,2] 。
2. largest = 2 下标为 2 。nextLargest = 1 。将 nums[2] 减少到 1 。nums = [1,1,1,2,2] 。 
3. largest = 2 下标为 3 。nextLargest = 1 。将 nums[3] 减少到 1 。nums = [1,1,1,1,2] 。 
4. largest = 2 下标为 4 。nextLargest = 1 。将 nums[4] 减少到 1 。nums = [1,1,1,1,1] 。
*/

// class Solution {
// public:
//     int reductionOperations(vector<int>& nums) {
//         // sort(nums.begin(),nums.end(),greater<int>());
//         int out=0;
//         int step=0;
//         map<int,int> map;
//         for(int i=0;i<nums.size();i++){
//             map[nums[i]]++;
//         }
//         auto it=map.begin();
//         for(;it!=map.end();it++){
//             out+=step*it->second;
//             step++;
//         }
//         return out;

//     }
// };

/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
示例 3：

输入：intervals = [[4,7],[1,4]]
输出：[[1,7]]
解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> out;
        
        for(int i=0;i<intervals.size()-1;){
            if(intervals[i][1]>=intervals[i+1][1]){

                intervals.erase(intervals.begin()+i+1);
                continue;
            }
            else if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i][1]=intervals[i+1][1];
                intervals.erase(intervals.begin()+i+1);
                continue;
            }
            i++;
        }
        return intervals;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. 排序 O(N log N)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> out;
        
        // 2. 将第一个区间先放入结果集
        out.push_back(intervals[0]);

        // 3. 遍历剩下的区间 O(N)
        for (int i = 1; i < intervals.size(); i++) {
            // 我们拿结果集中“最后一个合并完的区间”来对比当前区间
            // out.back() 代表当前已经合并好的最后一个区间
            
            if (out.back()[1] >= intervals[i][0]) {
                // 如果【上一个的终点】 >= 【当前的起点】，说明有重叠，进行合并
                // 注意：终点要取两者的最大值，防止 [1, 4] 和 [2, 3] 这种情况
                out.back()[1] = max(out.back()[1], intervals[i][1]);
            } else {
                // 如果没有重叠，说明上一个区间彻底结束了，把当前区间作为一个新的项加入
                out.push_back(intervals[i]);
            }
        }

        return out;
    }
};
