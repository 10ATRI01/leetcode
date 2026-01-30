#include<cstdio>
#include<algorithm>
#include<vector>
#include<array>

#include <unordered_map>
#include<unordered_set>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
/*
给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!(head))return 0;
        ListNode *quick_p;
        ListNode *slow_p;
        quick_p=head;
        slow_p=head;
        while(quick_p!=nullptr){
            quick_p=quick_p->next;
            if(quick_p!=nullptr){
                quick_p=quick_p->next;
            }
            else{
                return 0;
            }
            slow_p=slow_p->next;
            if(slow_p==quick_p)return 1;
        }
        return 0;
    }
};

/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。
请你从 nums 中选出三个在 不同下标位置 的整数，使它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在恰好一个解。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int now_p,pre_p,rear_p;
        vector<int> out;
        int sum=0;
        int abossum=INT16_MIN;
        sort(nums.begin(),nums.end());
        for(now_p=1;now_p<=nums.size()-2;now_p++){
            pre_p=0;
            rear_p=nums.size()-1;
            while(pre_p<now_p&&rear_p>now_p){
                sum=nums[now_p]+nums[pre_p]+nums[rear_p];
                if(abs(target-abossum)>abs(target-sum)){
                    abossum=sum;
                    out.clear();
                    out.push_back(nums[pre_p]);
                    out.push_back(nums[now_p]);
                    out.push_back(nums[rear_p]);
                }
                if(sum<target){
                    pre_p++;
                }
                else{
                    rear_p--;
                }
            }
        }
        return abossum;
    }
};


/*
神奇字符串 s 仅由 '1' 和 '2' 组成，并需要遵守下面的规则：
将连续相同字符组 '1' 和 '2' 长度的序列连接起来会生成字符串 s 本身。
s 的前几个元素是 s = "1221121221221121122……" 。如果将 s 中连续的若干 1 和 2 进行分组，
可以得到 "1 22 11 2 1 22 1 22 11 2 11 22 ......" 。
每组中 1 或者 2 的出现次数分别是 "1 2 2 1 1 2 1 2 2 1 2 2 ......" 。上面的出现次数正是 s 自身。
给你一个整数 n ，返回在神奇字符串 s 的前 n 个数字中 1 的数目。
*/

class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1; // n=1,2,3 时，s 分别为 "1", "12", "122"，1的个数都是1

        // 1. 初始化数组，预存前三个神奇字符串的数字
        std::vector<int> s;
        s.reserve(n + 1); // 预分配内存提高效率
        s.push_back(1);
        s.push_back(2);
        s.push_back(2);

        int ans = 1;      // 统计 1 的个数，初始只有 s[0] 是 1
        int head = 2;     // 读指针，从 s[2] 开始读，它决定了下一组数字的长度

        // 2. 模拟构造
        while (s.size() < n) {
            // 下一组要填入的数字：如果是 1 就填 2，如果是 2 就填 1
            // 技巧：3 - 2 = 1, 3 - 1 = 2
            int nextNum = 3 - s.back();
            
            // 当前读指针 head 指向的值，决定了下一组数字要重复几次
            int count = s[head];
            
            for (int k = 0; k < count; ++k) {
                if (s.size() < n) { // 确保不超过 n
                    s.push_back(nextNum);
                    if (nextNum == 1) {
                        ans++;
                    }
                }
            }
            head++; // 读指针后移
        }

        return ans;
    }
};

