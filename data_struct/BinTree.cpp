#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;    //类型名也可以是string等等
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class PrintTree
{
private:
    /*  把去掉中括号'[]'后的字符串转换成vector<string>向量，去掉逗号','
    传入："1,2,3,null,null,4,5"
    返回：向量{1,2,3,null,null,4,5} */
    vector<string> StringtoVector(string str, string delim) {
        vector<string> vec;
        int i = 0, j = 0, len = str.length();   //i字符串的首地址，j字符串的尾地址加1即逗号的地址
        while(i < len){
            while(j < len && str[j] != ',')
                j++;
            // 退出while时j存储的是逗号的地址
            vec.push_back(str.substr(i, j - i));
            i = ++j;
        }
        return vec;
    }
public:
    string serialize(TreeNode* root) {  //序列化：将一个二叉树按层序输出成一个字符串
        cout << "输入形式如：[1,2,3,null,null,4,5]" << endl;
        if(root == nullptr) return "[]";
        string res = "[";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if(node != nullptr) {
                res += (to_string(node->val) + ",");
                que.push(node->left);
                que.push(node->right);
            }
            else res += "null,";
        }
        res.pop_back(); //删掉字符串最后一个字符
        res += "]";
        return res;
    }   //string serialize(TreeNode* root)

    
    TreeNode* deserialize(string data) {    //字符串数组转成一个满二叉树
        if (data == "[]")
            return nullptr;
        //data.substr(1, data.length() - 2) 取从首地址1开始长为length()-2的子串，即把首尾的'[]'去掉
        vector<string> vec = StringtoVector(data.substr(1, data.length() - 2), ",");

        // stoi()字符串转int
        queue<TreeNode*> que;
        TreeNode *root = new TreeNode(stoi(vec[0]));  //创建根节点
        que.push(root);  //和emplace效果一样从队列尾部插入
        int i = 1;
        while(!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if(vec[i] != "null")
            {
                node->left = new TreeNode(std::stoi(vec[i]));  //创建新节点的方式：new TreeNode(int x)
                que.emplace(node->left);
            }
            if(i == vec.size() - 1)
                return root;
            i++;
            if(vec[i] != "null") {
                node->right = new TreeNode(std::stoi(vec[i]));
                que.emplace(node->right);
            }
            if(i == vec.size() - 1)
                return root;
            i++;
        }
        return root;
    }   //TreeNode* deserialize(string data)


    int countNode(TreeNode*& root)//统计二叉树中结点的个数
    {
        if(root == NULL)
            return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }//统计二叉树中结点的个数
    

    int hight(TreeNode*& root)//求二叉树的高度
    {
        if(!root)return 0 ;
        return max(hight(root->left), hight(root->right)) + 1;
    }//求二叉树的高度


    // 函数：寻找相同的子树

};  //class PrintTree

int main(){
    string str;
    cin >> str;
    PrintTree Tree; //实例化类
    TreeNode* root = Tree.deserialize(str);
    string s = Tree.serialize(root);
    cout << "s:" << s << endl;
    int count = Tree.countNode(root);
    cout << "countNode:" << count << endl;
    int hight = Tree.hight(root);
    cout << "hight:" << hight << endl;
    
    return 0;
}