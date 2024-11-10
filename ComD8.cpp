#include <bits/stdc++.h>
using namespace std;

vector<string> keywords = {
    "true", "false",
    "or", "and", "xor",
    "for", "if", "else", "do", "while", "break", "continue",
    "int", "float", "double", "bool", "long", "unsigned",
    "char", "string", "void", "auto", "new", "switch",
    "namespace", "class", "const", "sizeof", "typedef",
    "delete", "nullptr","main"
};

vector<string> arithmetic_operators = { "+", "-", "*", "/", "%" };
vector<string> relational_operators = { "==", "!=", "<", ">", "<=", ">=" };
vector<string> logical_operators = { "&&", "||", "!" };
vector<string> bitwise_operators = { "&", "|", "^", "~", "<<", ">>" };
vector<string> assignment_operators = { "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=" };
vector<string> increment_decrement_operators = { "++", "--" };
bool findStr(vector<string> st, string str){
    return find( st.begin(),st.end(),str)!=end(st);
}
bool isIdentifier(string st){
    if(isdigit(st[0])){
        return false;
    }
    for(auto x:st){
        if(x!='_' and !isalnum(x)){
            return false;
        }
    }
    return true;
}
bool is_string_constant(string st){
    if(st[0]=='\"' and st[st.length()-1]=='\"'){
        return true;
    }
    else{
        return false;
    }
}
int isConstant(string st){
    int radix=0;
    for(int i=0;i<st.length();i++){
        if(st[i]=='.'){
            radix++;
        }
        if(!isdigit(st[i]) && st[i]!='.'){
            return -1;
        }
    }
    if(radix==0){
        return 0;
    }
    else if(radix==1){
        return 1;
    }
    else{
        return -1;
    }
    
}
int main(){
    freopen("ComD8.txt","r",stdin);
    string line;
    while(getline(cin,line)){
        cout<<line;
        if(findStr(keywords,line)){
            cout<<" Keyword\n";
        }
        else if(findStr(arithmetic_operators,line)){
            cout<<" Arithmetic Operator\n";
        }
        else if(findStr(logical_operators,line)){
            cout<<" logocal Operator\n";
        }
        else if(findStr(relational_operators,line)){
            cout<<" Relational operator\n";
        }
        else if(findStr(bitwise_operators,line)){
            cout<<" bitwise_operators\n";
        }
        else if(findStr(assignment_operators,line)){
            cout<<" assignment_operators\n";
        }
         else if(findStr(increment_decrement_operators,line)){
            cout<<" increment_decrement_operators\n";
        }
        else if(isIdentifier(line)){
            cout<<" Identifier\n";        }
        else if( is_string_constant(line)){
            cout<<" string\n";
        }
        else{
            int n=isConstant(line);
            if(n==1){
                cout<<" Float\n";
            }
            else if(n==0){
                cout<<" Int\n";
            }
            else{
                cout<<" INVALID!\n";
            }
        }
        
    }
}