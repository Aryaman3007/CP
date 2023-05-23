#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

void markParents(TreeNode* root,unordered_map<TreeNode* , TreeNode*> &m){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                m[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                m[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> m;
        markParents(root,m);

        queue<TreeNode*> qu;
        qu.push(target);

        unordered_map<TreeNode* , bool> visited;
        visited[target]=true;
        int curr_level=0;

        while(!qu.empty()){
            if(curr_level++ == k) break;
            int size=qu.size();
            for(int i=0;i<size;i++){
                TreeNode* node=qu.front();
                qu.pop();
                if(node->left && !visited[node->left]){
                    qu.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    qu.push(node->right);
                    visited[node->right]=true;
                }
                if(m[node] && !visited[m[node]]){
                    qu.push(m[node]);
                    visited[m[node]]=true;
                }
            }
        }

        vector<int> ans;
        while(!qu.empty()){
            TreeNode* t=qu.front();
            qu.pop();
            ans.push_back(t->val);
        } 
        return ans;      
    }