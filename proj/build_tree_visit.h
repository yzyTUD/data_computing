#include<iostream>
#include<cstring>
#include<string>
char* sstr = "(324,)(22,L) (3,R) (4,LL)(281,LLL)(5,LR)()"; 
// navigate and maniplixx at last step 

class Node{
    int v;
    Node* left;
    Node* right;
public:
    Node(int value){
        v=value;
        left=right=NULL;
    }
    void setLeftNode(Node* l){
        left=l;
    }
    void setRightNode(Node* r){
        right=r;
    }
    Node* getLeftNode(){
        return left;
    }
    Node* getRightNode(){
        return right;
    }
    int getValue(){
        return v;
    }
};

Node* buildTreeFromString(char* ss){
    Node* root;

    //evaluate the expression, between ( and ,
    char* sp = std::strchr(ss,'(')+1;
    char* ep = std::strchr(sp,',');
    while(sp!=NULL&& ep!=NULL){
        int n=ep-sp;
        int value=0;
        for(int i=0;i<n;i++){
            int factor=1;
            for(int j=n-1-i;j>0;j--){
                factor *= 10;
            }
            value += (*(sp+i)-'0')*factor;
        }
        //std::cout<<value<<std::endl;
        //extract the lev information 
        sp = ep+1;//, 
        ep = std::strchr(sp,')');
        n=ep-sp;
        //std::cout<<n;
        Node* curNode;
        Node* curParent;
        curParent=root;

        //navigate to :
        for(int i=0;i<n-1;i++){
            if(*(sp+i)=='L'){
                //printf("left");
                curParent=curParent->getLeftNode();
            }else if(*(sp+i)=='R'){
                //right
                curParent=curParent->getRightNode();
            }
        }
        // add Node
        if(0==n){
            //root 
            root=new Node(value);
        }else{
            curNode = new Node(value);
            if(*(sp+n-1)=='L'){ 
                curParent->setLeftNode(curNode);
            }else{
                curParent->setRightNode(curNode);
            }
        }

        sp = std::strchr(sp,'(')+1; 
        ep = std::strchr(sp,',');
    }
    
    return root;

}

struct Trunk
{
    Trunk *prev;
    std::string str;

    Trunk(Trunk *prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    std::cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(Node *root, Trunk *prev, bool isLeft)
{
    if (root == NULL)
        return;
    
    std::string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->getRightNode(), trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isLeft)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    std::cout << root->getValue() << std::endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->getLeftNode(), trunk, false);
}

//some operations to the tree 
void firstOrderVisit(Node* node){
    if(node==NULL){
        return;
    }
    std::cout<<node->getValue()<<" ";
    firstOrderVisit(node->getLeftNode());
    firstOrderVisit(node->getRightNode());
}

void inOrderVisit(Node* node){
    if(node==NULL){
        return;
    }
    inOrderVisit(node->getLeftNode());
    std::cout<<node->getValue()<<" ";
    inOrderVisit(node->getRightNode());
}

int main(){

    Node* root=buildTreeFromString(sstr);
    //std::cout<<root->getValue()<<std::endl;
    //std::cout<<root->getLeftNode()->getLeftNode()->getValue()<<std::endl;
    printTree(root,NULL,false);
    std::cout<<"\n";
    std::cout<<"First Order Visit: \t";firstOrderVisit(root);
    std::cout<<"\nIn Order Visit: \t";inOrderVisit(root);
    std::cout<<"\n";
    return 0;
}
