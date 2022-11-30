#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode
{
public:
    int value;  //data
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n)  //non-default constructor
    {
        value=n;
        left=nullptr;
        right=nullptr;
    }
    TreeNode() //default constructor
    {
        value= 0;
        left= nullptr;
        right=nullptr;
    }
    
};

class BST
{
public:
    TreeNode* root;
    //METHODS
    BST()
    {
        root=nullptr;
    }
    bool isEmpty()
    {
        if(root==nullptr)
            return true;
        else
            return false;
    }
    void insertNode(TreeNode* newNode)
    {
        if(root==NULL)
        {
            root=newNode;
            cout<<"Value is inserted as root node "<<endl;
        }
        else
        {
            TreeNode* temp= root;
            while(temp!=nullptr)
            {
                if(temp->value==newNode->value)
                {
                    cout<<"Value already exist "<<endl;
                    return;
                }
                else if(temp->value<newNode->value && temp->right==nullptr)
                {
                    temp->right=newNode;
                    cout<<" Value Inserted to the Right! "<<endl;
                    break;
                }
                else if(temp->value<newNode->value)
                {
                    temp=temp->right;
                }
                else if(temp->value>newNode->value && temp->left==nullptr)
                {
                    temp->left= newNode;
                    cout<<" Value Inserted to the Left! "<<endl;
                    break;
                }
                else
                {
                    temp=temp->left;
                }
            }
        }
    }
    void printPreorder(TreeNode* temp)
    {
        if(temp==NULL)
            return;
        cout<<temp->value<<" ";
        printPreorder(temp->left);
        printPreorder(temp->right);
    }
    void printPostorder(TreeNode* temp)
    {
        if(temp==NULL)
            return;
        printPreorder(temp->left);
        printPreorder(temp->right);
        cout<<temp->value<<" ";
    }
    void printInorder(TreeNode* temp)
    {
        if(temp==NULL)
            return;
        printPreorder(temp->left);
        cout<<temp->value<<" ";
        printPreorder(temp->right);
    }
    void print2D(TreeNode* r, int space)
    {
        if(r==NULL)
            return;
        space+= SPACE;
        print2D(r->right,space);
        cout<<endl;
        for(int i=SPACE; i<space;i++)
        {
            cout<<" ";
        }
        cout<<r->value<<"\n";
        print2D(r->left,space);
    }
    TreeNode* iterativeSearch(int val)
    {
        if(root==NULL)
        {
            return root;
        }
        else
        {
            TreeNode* temp=root;
            while(temp!=NULL)
            {
                if(temp->value>val)
                    temp=temp->left;
                else if(temp->value<val)
                    temp=temp->right;
                else
                    return temp;
            }
            return NULL;
        }
    }
    TreeNode* recursiveSearch(TreeNode* r,int val)
    {
        if(r==NULL)
        {
            return r;
        }
        if(r->value == val)
        {
            return r;
        }
        else
        {
            if(r->value> val)
                return recursiveSearch(r->left, val);
            else
                return recursiveSearch(r->right, val);
        }
        return NULL;
    }
    int height(TreeNode* ptr) //Number of edges between the root node and the furthest leaf
    {
        if(ptr==NULL)
            return -1;
        else
        {
            int leftheight= height(ptr->left);
            int rightheight=height(ptr->right);
            if(leftheight>rightheight)
                return leftheight+1;
            else
                return rightheight+1;
        }
    }
    void printLevelOrderBFS(TreeNode* r)
    {
        int h= height(r);
        for(int i=0; i<=h; i++)
        {
            printGivenLevel(r,i);
        }
    }
    void printGivenLevel(TreeNode* r, int level)
    {
        if(r==NULL)
            return;
        else if(level==0)
        {
            cout<<r->value<<" ";
        }
        else
        {
            printGivenLevel(r->left,level-1);
            printGivenLevel(r->right,level-1);
        }
    }
    TreeNode* deleteNode(TreeNode* r,int v)
    {
//        if(r==NULL)
//        {
//            return ;
//        }
//        else
//        {
//            TreeNode* temp =r;
//            while(temp!=NULL)
//            {
//                if(temp->value > val && temp->left==NULL)
//                    return;
//                else if(temp->value > val)
//                {
//                    temp=temp->left;
//                }
//                else if(temp->value < val && temp->right==NULL)
//                    return;
//                else if(temp->value < val)
//                {
//                    temp=temp->right;
//                }
//                else
//                {
//                    if(temp->left==NULL && temp->right==NULL)
//                    {
//                        delete temp;
//                        temp=nullptr;
//                    }
//                    else if(temp->left==NULL && temp->right!=NULL)
//                    {
//                        TreeNode* r= temp->right;
//                        temp->value=r->value;
//                        delete r;
//                        temp->right=nullptr;
//                    }
//                    else if(temp->right==NULL && temp->left!=NULL)
//                    {
//                        TreeNode* r= temp->left;
//                        temp->value=r->value;
//                        delete r;
//                        temp->left=nullptr;
//                    }
//                    else
//                    {
//                        TreeNode* x=maxLeftSubtreeNode(temp);
//                        int result= x->value;
//                        temp->value=result;
//                        if(x->right!=NULL)
//                        {
//                            TreeNode* ptr=x->right;
//                            x->value = ptr->value;
//                            delete ptr;
//                            x->right=NULL;
//                        }
//                        else
//                        {
//                            delete x;
//                        }
//                    }
//                }
//            }
//        }
        if(r==NULL)
          return r;
        else if(r->value < v)
            r->right=deleteNode(r->right,v);
        else if(r->value > v)
            r->left= deleteNode(r->left,v);
        else
        {
            if(r->left==NULL) //node with only right child or no child
            {
                TreeNode* temp= r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL) //node with only right child
            {
                TreeNode* temp= r->left;
                delete r;
                return temp;
            }
            else //node with two children
            {
                TreeNode* temp=minValueNode(r->right);
                r->value =temp->value;
                r->right= deleteNode(r->right,temp->value);
            }
        }
        return r;
    }
    TreeNode* minValueNode(TreeNode* r)
    {
        TreeNode* temp=r;
        while(temp->left!=NULL)
        {
                temp=temp->left;
        }
        return temp;
    }
};
