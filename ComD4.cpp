#include<iostream>
using namespace std;
bool isINT(string st){
    if(st.length()==0){
        return false;
    }
    if(st[0]=='0'){
        return false;
    }
    for(int i=1;i<st.length();i++){
        if(isdigit(st[i])){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
bool isVariable(string st){
    if(tolower(st[0])<'i' || tolower(st[0])>'n'){
        return false;
    }
    for(int i=1;i<st.length();i++){
        if(isalnum(st[i]))continue;
        else return false;
    }
    return true;
}
int main(){
     freopen("Comd4.txt","r",stdin);
     string line;
     while(getline(cin,line)){
     cout<<line;
     if(isVariable(line)){
        cout<<" is a Integer variable\n";
     }
     else if(isINT(line)){
        if(line.length()<5){
        cout<<" is ShortInt number\n";
        }
        else{
        cout<<" is LongInt number\n";
        }
     }
     else{
        cout<<" INVALID!\n";
     }
     }
}