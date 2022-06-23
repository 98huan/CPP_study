#include <iostream>
#include <vector>
using namespace std;

struct binnode
{
    int data;
    binnode* left;
    binnode* right;
    binnode(int x) :  data(x), left(NULL), right(NULL){}
};


binnode* qianxu(vector<int>& vec){
    int len = vec.size();
    binnode *root = new binnode(vec[0]);{
        for(int i = 1; i < len; i++){
            binnode *tmp = new binnode(vec[i]);
            root->left = tmp;
        }
    }
    return root;
}

int main(){

    return 0;
}