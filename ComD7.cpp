#include<iostream>
#include <vector>
using namespace std;
vector<string> keywords={
    "int","float","double","string","char","bool","void",
    "if","else","else if","switch","case","break",
    "for","while","do","goto",
    "main",
    "typedef","class",
    "true","false","or","and","xor"


}, operators={
        "+","-","*","/","%",
        "==","!=","<=",">=","<",">",
        "&&","||","!",
        "+=","-=","*=","/=","=","%=","&=","|=",
        "++","--",
        "?",":",
        ".","->"

};
bool iskeyWord(string st){
    for(string word: keywords){
        if(word.compare(st)==0){
            return true;
        }
    }
return false;
}
bool isOperator(string st){
        for(string word: operators){
        if(word.compare(st)==0){
            return true;
        }
    }
return false;
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
bool isConstant(string st){
    int radix=0;
    for(int i=0;i<st.length();i++){
        if(st[i]=='.'){
            radix++;
        }
        if(!isdigit(st[i]) && st[i]!='.'){
            return false;
        }
    }
    if(radix>1){
        return false;
    }
    return true;
}
int main(){
      freopen("ComD7.txt","r",stdin);
      string line;
      while(getline(cin,line)){
        cout<<line;
        if(iskeyWord(line)){
            cout<<" is a keyword\n";
        }
        else if(isOperator(line)){
             cout<<" is a operator\n";
        }   else if(isIdentifier(line)){
             cout<<" is a Identifier\n";
        }
        else if( is_string_constant(line)){
            cout<<" is a string constant\n";
        }
        else if(isConstant(line)){
            cout<<" is a constant\n";
        }
        else{
            cout<<" invalid!";
        }
      }
}