#include<cstdio>
#include<algorithm>
#include<vector>
#include<array>
#include <cmath>
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

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end());
//         vector<vector<int>> out;
        
//         for(int i=0;i<intervals.size()-1;){
//             if(intervals[i][1]>=intervals[i+1][1]){

//                 intervals.erase(intervals.begin()+i+1);
//                 continue;
//             }
//             else if(intervals[i][1]>=intervals[i+1][0]){
//                 intervals[i][1]=intervals[i+1][1];
//                 intervals.erase(intervals.begin()+i+1);
//                 continue;
//             }
//             i++;
//         }
//         return intervals;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         if (intervals.empty()) return {};

//         // 1. 排序 O(N log N)
//         sort(intervals.begin(), intervals.end());

//         vector<vector<int>> out;
        
//         // 2. 将第一个区间先放入结果集
//         out.push_back(intervals[0]);

//         // 3. 遍历剩下的区间 O(N)
//         for (int i = 1; i < intervals.size(); i++) {
//             // 我们拿结果集中“最后一个合并完的区间”来对比当前区间
//             // out.back() 代表当前已经合并好的最后一个区间
            
//             if (out.back()[1] >= intervals[i][0]) {
//                 // 如果【上一个的终点】 >= 【当前的起点】，说明有重叠，进行合并
//                 // 注意：终点要取两者的最大值，防止 [1, 4] 和 [2, 3] 这种情况
//                 out.back()[1] = max(out.back()[1], intervals[i][1]);
//             } else {
//                 // 如果没有重叠，说明上一个区间彻底结束了，把当前区间作为一个新的项加入
//                 out.push_back(intervals[i]);
//             }
//         }

//         return out;
//     }
// };

/*
给定一个长度为 n 的整数 山脉 数组 arr ，其中的值递增到一个 峰值元素 然后递减。

返回峰值元素的下标。

你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。

示例 1：

输入：arr = [0,1,0]
输出：1
示例 2：

输入：arr = [0,2,1,0]
输出：1
示例 3：

输入：arr = [0,10,5,2]
输出：1
 
*/
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         //本质找最大值看左右两边哪个比中间这个数大，如果左边数大，末尾指针指过来，右边数大，头指针之过来
//         int head=0;
//         int rear=arr.size()-1;
//         int naka=0;
//         while (head<=rear)
//         {
//             /* code */
//             naka=(head+rear)/2;
//             if(naka>1&&arr[naka]<arr[naka-1]){
//                 rear=naka-1;
//             }
//             if(naka<(arr.size()-1)&&arr[naka]<arr[naka+1]){
//                 head=naka+1;
//             }
//             if(arr[naka]>arr[naka+1]&&arr[naka]>arr[naka-1])return naka;
//         }

//         return -1;
//     }
// };


/*
给定一个非负整数 c ，
你要判断是否存在两个整数 a 和 b，
使得 a2 + b2 = c 。
示例 1：
输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
示例 2：
输入：c = 3
输出：false
*/

// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         long long head=0;
//         long long rear=sqrt(c);
//         long long sum;
//         while (head<rear)
//         {
//             /* code */
//             sum=head*head+rear*rear;
//             if(sum==c){
//                 return 1;
//             }
//             else if(sum>c){
//                 rear--;
//             }
//             else{
//                 head++;
//             }
//         }
//         return -1;
        
//     }
// };


/*
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 向左旋转，
使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 下标 3 上向左旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，
则返回它的下标，否则返回 -1 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
*/

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         unordered_map<int,int> map;
//         for(int i=0;i<nums.size();i++){
//             map[nums[i]]=i;
//         }
//         auto it=map.find(target);
//         if(it!=map.end())return it->second;
//         else return -1;
//     }
// };

/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end(),greater<int>());
//         return nums[k-1];
//     }
// };

/*
给你一个整数数组 nums，请你将该数组升序排列。
你必须在 不使用任何内置函数 的情况下解决问题，
时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。
*/


// //来写个归并排序吧
// class Solution {
// public:

//     vector<int> sortArray(vector<int>& nums) {

//     }
// };


/*
给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。

插入排序 算法的步骤:

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。

对链表进行插入排序。
*/

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // 1. 特判：如果没有节点或只有一个节点，直接返回
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 2. 创建虚拟头结点，方便在头部插入
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 3. 初始化指针
        // lastSorted: 已排序区间的最后一个节点（初始就是 head）
        // curr: 当前准备进行排序的节点（初始是 head 的下一个）
        ListNode *lastSorted = head;
        ListNode *curr = head->next;

        while (curr != nullptr) {
            // 【情况 A】如果当前节点比已排序的最后一个还要大（或相等）
            // 说明顺序是对的，直接把已排序区间向后扩展一位
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            } 
            // 【情况 B】当前节点比 lastSorted 小，需要插入到前面去
            else {
                // 我们需要从头开始找，找到第一个比 curr 大的节点的前一个位置
                ListNode *prev = dummy;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }

                // 此时 prev 的后面就是 curr 应该插入的位置
                // 开始断链和重连操作：
                
                // 1. 把 curr 从原位置（lastSorted 后面）拿出来
                lastSorted->next = curr->next;
                
                // 2. 把 curr 插到 prev 后面
                curr->next = prev->next;
                prev->next = curr;
            }

            // 【迭代】准备处理下一个节点
            // 注意：如果刚才发生了插入操作，lastSorted 不需要动，因为它的 next 已经更新为新的待排序节点了
            // 如果刚才没发生插入（情况 A），lastSorted 在上面已经动过了
            curr = lastSorted->next;
        }

        return dummy->next;
    }
};


int main(){

    vector<int> arr={0,2,1,0};
    Solution planc;
    // planc.peakIndexInMountainArray(arr);
    // planc.judgeSquareSum(3);
}