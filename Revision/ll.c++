#include<bits/stdc++.h>
using namespace std;
class linkedlist{
    private:
    
    public:
    int val;
    int *left;
    int *right;
    linkedlist(){
        nullptr;
    }

    linkedlist(int n){
        linkedlist *a;
        a->val=n;
        a->left=nullptr;
        a->right=nullptr;
    }


};
int main()
{
    cout<<"Start"<<endl;
    linkedlist *head=new linkedlist(5);
    cout<<head->val<<endl;
    cout<<"End"<<endl;
    return 0;
}