#include<cstdio>
#include<algorithm>
#include<vector>
#include<array>
#include<string>
#include <unordered_map>
#include<unordered_set>

using namespace std;

/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
*/

class Solution {
private:
    vector<vector<int>> result; // 存放所有结果
    vector<int> path;           // 存放当前路径（一个组合）

    // startIndex 用来记录本层递归的中，搜索的起始位置
    void backtracking(int n, int k, int startIndex) {
        // 终止条件：找到了一组长度为 k 的组合
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // 单层搜索逻辑
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);          // 处理节点
            backtracking(n, k, i + 1);  // 递归：控制树的深度
            path.pop_back();            // 回溯：撤销处理的节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};


/*
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1. 12" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
*/
class Solution {
public:
    vector<string> out;

    // 校验这一段数字是否合法
    bool isValid(string s) {
        if (s.empty() || s.size() > 3) return false;
        // 检查前导 0：长度大于 1 时，首位不能为 0
        if (s.size() > 1 && s[0] == '0') return false;
        // 检查数值：不能大于 255
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    // s: 原字符串, index: 当前处理到的下标, ipwei: 当前是第几段 IP, path: 当前拼好的字符串
    void ip_make(string s, int index, int ipwei, string path) {
        // 如果已经凑齐了 4 段
        if (ipwei == 4) {
            // 如果刚好用完了原字符串的所有字符，说明这是一个合法的解
            if (index == s.size()) {
                // 去掉最后多出来的一个点
                path.pop_back();
                out.push_back(path);
            }
            return;
        }

        // 尝试截取 1 到 3 位
        for (int i = 1; i <= 3; i++) {
            // 越界检查
            if (index + i > s.size()) break;

            string temp = s.substr(index, i);
            if (isValid(temp)) {
                // 递归：处理下一段，把当前段加到路径里，并带上点
                ip_make(s, index + i, ipwei + 1, path + temp + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        out.clear();
        // 剪枝：IP数字最少 4 位，最多 12 位
        if (s.size() < 4 || s.size() > 12) return out;

        ip_make(s, 0, 0, "");
        return out;
    }
};


/*一个 「开心字符串」定义为：

仅包含小写字母 ['a', 'b', 'c'].
对所有在 1 到 s.length - 1 之间的 i ，满足 s[i] != s[i + 1] （字符串的下标从 1 开始）。
比方说，字符串 "abc"，"ac"，"b" 和 "abcbabcbcb" 都是开心字符串，但是 "aa"，"baa" 和 "ababbc" 都不是开心字符串。

给你两个整数 n 和 k ，你需要将长度为 n 的所有开心字符串按字典序排序。

请你返回排序后的第 k 个开心字符串，如果长度为 n 的开心字符串少于 k 个，那么请你返回 空字符串 。*/

class Solution {
public:
    int num = 0;           // 记录当前是第几个开心字符串
    string temp;           // 记录当前的路径
    string result = "";    // 存最终找到的答案

    // 我们需要一个独立的辅助函数（下属），专门负责递归
    void backtrack(int n, int k) {
        // 1. 如果结果已经找到了，直接返回，不再浪费时间
        if (!result.empty()) return;

        // 2. 终止条件：长度够了
        if (temp.size() == n) {
            num++; // 计数
            if (num == k) {
                result = temp; // 找到第 k 个了！
            }
            return;
        }

        // 3. 核心：尝试 a, b, c
        for (char c : {'a', 'b', 'c'}) {
            // 开心字符串逻辑：当前字符 c 不能和前一个相同
            if (temp.empty() || c != temp.back()) {
                temp.push_back(c);     // 【前进】
                backtrack(n, k);       // 【递归】去看下一位
                temp.pop_back();       // 【撤销】非常重要！退回原地
            }
        }
    }

    string getHappyString(int n, int k) {
        num = 0;
        temp = "";
        result = "";
        
        backtrack(n, k); // 开始递归
        return result;   // 如果最后都没找到，result 依然是 ""
    }
};