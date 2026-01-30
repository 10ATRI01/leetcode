#include<cstdio>
#include<algorithm>
#include<vector>
#include <unordered_map>
using namespace std;

class tree
{
public:
    struct Treenode
    {
        /* data */
        Treenode*left_child;
        Treenode*right_child;
        int val;
        Treenode(int x):val(x),left_child(nullptr),right_child(nullptr){}
    };
    
    Treenode*creat_tree(vector<int> &preorder,vector<int> &inorder){
        //先把inorder数组构造成一个索引表
        unordered_map<int,int> inorder_map;
        for(int i=0;i<inorder.size();i++){
            //通过treenode中的val来获取数组下标，如果数组中有重复值需要重新建立一个数组自行定义id,此处默认没有重复
            inorder_map[inorder[i]]=i;
        }
        Treenode *root=dfscreat(preorder,inorder_map,0,0,preorder.size()-1);
        return root;
    }
    tree(/* args */){}
    ~tree(){}
private:
    /* data */
    Treenode*dfscreat(vector<int>perorder,unordered_map<int,int>inorder_map,int i,int l,int r){//i表示pre中的根，l，r表示左右端点（中序）
        if (r - l < 0) return nullptr;
        int index=inorder_map[perorder[i]];//检索这个在pre中根的值在inorder中的哪个位置
        //根和左右节点连接
        Treenode *node=new Treenode(perorder[i]);
        //返回左子树
        node->left_child= dfscreat(perorder,inorder_map,i+1,l,index-1);
        //返回右子树
        node->right_child= dfscreat(perorder,inorder_map,i+1+index-l,index+1,r);

        return node;
    }
};



class Solution {
public:
    vector<int>temp;
    int reversePairs(vector<int>& nums) {
       return divide(nums,0,nums.size()-1);
    }
    int divide(vector<int>&nums,int left,int right){
        if(left>=right){
            return 0;
        }
        int mid=(left+right)/2;
        //接住返回值
        int res=divide(nums,left,mid)+divide(nums,mid+1,right);
        //计算翻转对
        //左边是left到mid，右边是mid+1到right
        int left_p=left;
        int right_p=mid+1;
        
        for(;right_p<=right;right_p++){
            for(;left_p<=mid;left_p++){
                if(nums[left_p]>2LL*nums[right_p]){//2LL防止int溢出
                    res+=mid-left_p+1;
                    break;
                }
            }
        }
        //归并排序
        merge(nums,left,mid,right,temp);

        return res;
    }
    int merge(vector<int>&nums,int left,int mid,int right,vector<int> &temp){
        int left_p=left;
        int right_p=mid+1;
        temp.clear();
        for(;left_p<=mid&&right_p<=right;){
            if(nums[left_p]<=nums[right_p]){
                temp.push_back(nums[left_p]);
                left_p++;
            }
            else{
                temp.push_back(nums[right_p]);
                right_p++;
            }
        }
        if(left_p>mid){
            for(;right_p<=right;right_p++){
                temp.push_back(nums[right_p]);
            }
            
        }
        else{
            for(;left_p<=mid;left_p++){
                temp.push_back(nums[left_p]);
            }
        }
        //用temp代替nums
        for(int i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }

    }

};


int main(){
    vector<int>preorder={1,3,7,6,4,9};
    vector<int>inorder={7,3,6,1,9,4};
    tree::Treenode *node;
    tree t;
    node=t.creat_tree(preorder,inorder);
    return 1;
}

