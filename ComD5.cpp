#include<iostream>
using namespace std;
bool isVariable(string st){
    char ch=tolower(st[0]);
    if((ch>='a' and ch<='h') or (ch>='0' and ch<='z')){
        for(int i=1;i<st.length();i++){
            if(isalnum(st[i])){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    else{
    return false;
    }
}
int isFloat(string st){
    string beforeRadix="";
    string afterRadix="";
     int r=st.find('.');
     beforeRadix= st.substr(0,r);
     afterRadix=st.substr(r+1);
     
     if(beforeRadix.length()==0 or (beforeRadix[0]=='0' and st[1]!='.')){
        return -1;
     }else{
        for(int i=1;i<beforeRadix.length();i++){
            if(isdigit(beforeRadix[i])){
                continue;
            }
            else{
                return false;
            }
        }
     }
     if(afterRadix.length()<2){
        return -1;
     }else{
        for(int i=0;i<afterRadix.length();i++){
            if(isdigit(afterRadix[i])){
                continue;

            }
            else{
                return -1;
            }
        }
     }
     
     return afterRadix.length();
}

int main(){
     freopen("ComD5.txt","r",stdin);
     string line;
     while(getline(cin,line)){
        cout<<line;
        if(isVariable(line)){
            cout<<" is Float variable\n";
        }
        else {
            int n=isFloat(line);
            if(n==-1){
            cout<<" is INVALID!\n";
            }
            else if(n==2){
               cout<<" is a Float Number\n";
            }
            else {
                cout<<" is a Double Number\n";
            }
            
        }
     }

}