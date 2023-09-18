#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node * links[26];
    bool flag= false;

    bool containskey(char ch){
        if(links[ch-'a'] != NULL){
            return true;
        }
        return false;
    }
    Node* getn(char ch){
        return links[ch-'a'];
    }

    void putc(char ch){
        links[ch-'a']= new Node();
    }

    void setend(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};

class Trie {
public:
    Node *root =NULL;
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node * node= root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])== true){
                node=node->getn(word[i]);
            }
            else{
                node->putc(word[i]);
                node=node->getn(word[i]);
            }
        }
        node->setend();
    }
    
    bool search(string word) {
        Node * node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
           node= node->getn(word[i]);
        }
        return node->isend();
    }
    
    bool startsWith(string prefix) {
        Node * node= root;
        for(int i=0;i<prefix.size();i++){
            if(node->containskey(prefix[i])){
                node=node->getn(prefix[i]);
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};