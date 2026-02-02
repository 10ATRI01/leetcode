#include<cstdio>
#include<algorithm>
#include<vector>
#include<array>
#include<string>
#include <unordered_map>
#include<unordered_set>

using namespace std;



  struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*p1=list1;
        ListNode*p2=list2;
        ListNode*shaobing_p;
        ListNode shaobing;
        shaobing_p=&shaobing;
        shaobing_p->next=list2;
        ListNode*pre_p2=shaobing_p;
        ListNode*temp;
        if(list1==nullptr)return list2;
        else if(list2==nullptr)return list1;
        while(p2!=nullptr&&p1!=nullptr){
            while(p2!=nullptr&&p1->val>=p2->val){
                pre_p2=p2;
                p2=p2->next;
            }
            if(p2==nullptr)break;
            else{
                temp=p1;
                p1=p1->next;
                temp->next=pre_p2->next;
                pre_p2->next=temp;
                pre_p2=pre_p2->next;
            }

        }
        if(p2==nullptr)pre_p2->next=p1;
        // if(p1==nullptr)return shaobing_p->next;
        return shaobing_p->next;
    }
};

/*
给你两个正整数 n 和 k，二进制字符串  Sn 的形成规则如下：
S1 = "0"
当 i > 1 时，Si = Si-1 + "1" + reverse(invert(Si-1))
其中 + 表示串联操作，reverse(x) 返回反转 x 后得到的字符串，
而 invert(x) 则会翻转 x 中的每一位（0 变为 1，而 1 变为 0）。
例如，符合上述描述的序列的前 4 个字符串依次是：
S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
请你返回  Sn 的 第 k 位字符 ，题目数据保证 k 一定在 Sn 长度范围以内。
*/
class Solution {
public:
    char findKthBit(int n, int k) {
        // 基准情况：S1 只有一位 '0'
        if (n == 1) return '0';

        // 计算当前 Sn 的长度的一半（即中间位置）
        // Sn 的长度是 2^n - 1，中间位置就是 2^(n-1)
        int mid = 1 << (n - 1); 

        if (k == mid) {
            // 情况 1：正好在中间
            return '1';
        } 
        else if (k < mid) {
            // 情况 2：在左半部分，递归查找 Sn-1
            return findKthBit(n - 1, k);
        } 
        else {
            // 情况 3：在右半部分
            // 找到对应在 Sn-1 中的位置：k_new = Sn的长度 - k + 1
            // Sn 的长度是 (2 * mid - 1)
            int k_new = (2 * mid - 1) - k + 1;
            char res = findKthBit(n - 1, k_new);
            
            // 记得取反 (invert)
            return (res == '0') ? '1' : '0';
        }
    }
};

/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

测试用例保证输出的长度不会超过 105。
*/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }

    string helper(const string& s, int& i) {
        string res = "";
        int n = s.size();
        
        while (i < n && s[i] != ']') {
            if (!isdigit(s[i])) {
                // 1. 普通字母：直接加
                res += s[i++];
            } else {
                // 2. 数字：计算 k
                int k = 0;
                while (i < n && isdigit(s[i])) {
                    k = k * 10 + (s[i++] - '0');
                }
                
                // 3. 遇到 '['：开始递归处理括号内部
                i++; // 跳过 '['
                string innerStr = helper(s, i);
                i++; // 跳过 ']'
                
                // 4. 重复并拼接
                while (k--) res += innerStr;
            }
        }
        return res;
    }
};