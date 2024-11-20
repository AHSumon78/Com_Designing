#include<iostream>
#include<bits/stdc++.h>
#include <map>
using namespace std;
 map<string,string> rules;
 string stk="",input,temp;
void reduce(){
    for(int i=stk.length()-2;i>=0;i--){
           temp=stk.substr(i);
          if(rules[temp]!=""){
            stk.erase(i);
            stk+=rules[temp];
            i=stk.length()-2;
            cout<< left << setw(13) <<"$"+stk<<right<< setw(13) <<input+"$"<<"         "<<"reduce "<<rules[temp]<<"->"<<temp<<endl; 
          }
    }
}
/*void reduce1(){
    for(auto rule:rules){
        int position= stk.find(rule.first);
        if(position!= string::npos){
            stk.erase(position);
            stk+=rule.second;
           cout<< left << setw(13) <<"$"+stk<<right<< setw(13) <<input+"$"<<"         "<<"reduce "<<rule.second<<"->"<<rule.first<<endl; 
            if(stk.length()==1){
        return;
    }
           reduce();
           return;
        }
    }
}*/

int main(){
     cout <<"Enter number of production : ";
     int n;
     cin>>n;
     cin.ignore();
     string line;
     string startsymbol="";
     while(n--){
        getline(cin,line);
        rules[line.substr(3)]=line[0];
        if(startsymbol==""){
            startsymbol=line[0];
        }
     }
     cout<<"Geven production is :\n";
     for(auto rule:rules){
        cout<<rule.second<<"->"<<rule.first<<endl;
     }
    //take input string 
    cout<<"type input string\n";
      cin>>input;
    cout<<"stack"<<"             "<<"input"<<"             "<<"action"<<endl;
     cout<< left << setw(13) <<"$"+stk<<right<< setw(13) <<input+"$"<<"         "<<"shift"<<endl;
    for(int i=0;!input.empty();i++){
        stk+=input[0];
        input.erase(0,1);
      cout<< left << setw(13) <<"$"+stk<<right<< setw(13) <<input+"$"<<"         "<<"shift"<<endl;
      reduce();
    }
    if(stk==startsymbol){
        cout<<"accepted\n";
    }
    else{
        cout<<"rejected\n";
    }

}