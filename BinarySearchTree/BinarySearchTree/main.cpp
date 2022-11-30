#include "BST.h"
#include<iostream>
using namespace std;
 int main()
{
     BST obj;
     int val;
     int option;
     do
     {
         cout<<"What operation do you want to perform? ";
         cout<<"Select option number. Enter 0 to exit."<<endl;
         cout<<"1. Insert Node" <<endl;
         cout<<"2. Search Node" <<endl;
         cout<<"3. Delete Node" <<endl;
         cout<<"4. Print BST values"<<endl;
         cout<<"5. Clear Screen"<<endl;
         cout<<"0. Exit Program"<<endl;
         
         cin>>option;
         //Node n1;  //when running the program multiple times the object will go out of scope and the memory will be destroyed
         TreeNode * new_node= new TreeNode();
         switch(option)
         {
             case 0:
                 break;
             case 1:
                 cout<<"Insert"<<endl;
                 cout<<"Enter the value of the tree node to insert in BST: ";
                 cin>> val;
                 new_node->value=val;
                 obj.insertNode(new_node);
                 //insertion code
                 break;
             case 2:
                 cout<<"Search"<<endl;
                 cout<<"Enter the value of tree node to search in BST: ";
                 cin>>val;
                 new_node = obj.iterativeSearch(val);
                 if(new_node!=NULL)
                     cout<<"Value is found "<<endl;
                 else
                     cout<<"Value not found "<<endl;
                 new_node = obj.recursiveSearch(obj.root,val);
                 if(new_node!=NULL)
                     cout<<"Value is found "<<endl;
                 else
                     cout<<"Value not found "<<endl;
                 //search node
                 break;
             case 3:
                 cout<<"Delete"<<endl;
                 cout<<"Enter value of tree node to delete in BST: ";
                 cin>>val;
                 new_node=obj.iterativeSearch(val);
                 if(new_node!=nullptr)
                 {
                     obj.deleteNode(obj.root,val);
                     cout<<"Value Deleted"<<endl;
                 }
                 else
                 {
                     cout<<"Value NOT found"<<endl;
                 }
                 //delete node
                 break;
             case 4:
                 cout<<"Print and Traverse"<<endl;
                 cout<<"2D BINARY SEARCH TREE"<<endl;
                 obj.print2D(obj.root,5);
                 cout<<"PRE-ORDER TRAVERSAL"<<endl;
                 obj.printPreorder(obj.root);
                 cout<<"IN-ORDER TRAVERSAL"<<endl;
                 obj.printInorder(obj.root);
                 cout<<"POST-ORDER TRAVERSAL"<<endl;
                 obj.printPostorder(obj.root);
                 cout<<"Print Level Order BFS :"<<endl;
                 obj.printLevelOrderBFS(obj.root);
                 cout<<endl;
                 //print and traverse
                 break;
             case 5:
                 cout<<"Tree Height"<<endl;
                 cout<<"Height : "<<obj.height(obj.root)<<endl;
                 break;
             case 6:
                 cout<<"Clear Screen"<<endl;
                 //clear screen
                 system("cls");
                 break;
             default:
                 cout<<"Enter proper option number "<<endl;
         }
     }
        while(option!=0);
     return 0;
 }
