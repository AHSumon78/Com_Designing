#include<iostream> 
#include <stack>
using namespace std;
bool isOperator(char op)
{
    return (op == '-' or op == '+' or op == '*' or op == '/' or op == '^') ;
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
int main(){
    string expression;
    cout<<"Input C++ expression :";
    cin>>expression;
    cout<<"PostFix Expression :"<<infixToPostfix(expression);

}
