#include <iostream>
#include <stack>

using namespace std;
bool isOperator(char op)
{
    return (op == '-' or op == '+' or op == '*' or op == '/' or op == '^') ? true : false;
}
struct Node{
    char data;
    Node* left;
    Node* right;

    Node(char data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
typedef Node* nodeptr;
nodeptr parse(string st){
    stack<nodeptr> temp;
    for(int i=0;i<st.length();i++){
        if(isalpha(st[i])){
            nodeptr node= new Node(st[i]);
            temp.push(node);
        }
        else if(isOperator(st[i])){
            nodeptr node =new Node(st[i]);
            node->right=temp.top();
            temp.pop();
            node->left=temp.top();
            temp.pop();
            temp.push(node);
        }
    }
    return temp.top();
}

void printTree(nodeptr root){
     stack<nodeptr> st;
     st.push(root);
     nodeptr ptr=root;
     while (!st.empty()){
          ptr=st.top();
          st.pop();
     while(ptr!=NULL){
        cout<<ptr->data<<"     ";
        st.push(ptr->right);
        ptr=ptr->left;
     }
     cout<<endl;
     }
        
}
int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 4;
        break;
    case '/':
        return 2;
        break;
    case '*':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}

string infixToPostfix(string st)
{
    string postfix;
    stack<char> stk;
    stk.push('(');
    st.push_back(')');
    int i = 0;
    while (!stk.empty())
    {
        if (isalpha(st[i]))
        {
            postfix.push_back(st[i]);
        }
       else if (st[i]=='('){
         stk.push(st[i]);
       }
       else if(isOperator(st[i])){
        while(precedence(st[i])<=precedence(stk.top())){
            postfix.push_back(stk.top());
            stk.pop();
        }
        stk.push(st[i]);
       }
       else if(st[i]==')'){
        while(stk.top()!='('){
            postfix.push_back(stk.top());
            stk.pop();
        }
        stk.pop();
       }
       i++;
    }
    return postfix;
}

int main()
{
    string s="a+b*c/d";
    cout<<s<<endl;
    cout<<infixToPostfix(s);
    cout<<endl;
    printTree(parse(infixToPostfix(s)));
}