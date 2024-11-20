#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> split(string sentence, char delimiter){
    vector<string> words;
    int f=0;
    int n=sentence.length();
    for(int i=0;i<n-1;i++){
        if(sentence[i]==' ' and sentence[i+1]!=' '){
            words.push_back(sentence.substr(f,i-f));
            f=i+1;
        }
    }
    words.push_back(sentence.substr(f));
    return words;
}
 int main(){
    vector<string> PN ={"Sagor","Selim","Salma","Nipu"};
    vector<string> P={"he","she","I","we","you","they"};
    vector<string> N = {"book","cow","dog","home","grass","rice","mango"};
    vector<string> V = {"read","eat","take","run","write"};
    string sentence;
    freopen("ComD9.txt","r",stdin);
    vector<string> words ;
    while(getline(cin,sentence)){
        cout<<sentence<<" : ";
          words=split(sentence,' ');
        if(words.size()<2 or words.size()>3){
            printf("Invalid sentence\n");
            continue;
        }
        else{
          if(find(PN.begin(), PN.end(), words[0])==PN.end() and find(P.begin(), P.end(), words[0])==P.end()){
            printf("Invalid sentence\n");
            continue;
          }
          if(find(V.begin(),V.end(),words[1])==V.end()){
            printf("Invalid sentence\n");
            continue;
          }
          if(words.size()==3){
            if( find(N.begin(), N.end(), words[2])==N.end()){
                printf("Invalid sentence\n");
                continue;
            }
          }
          printf("Valid\n");

        }
    }

 }