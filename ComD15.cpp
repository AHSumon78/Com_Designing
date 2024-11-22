#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<map>
using namespace std;
vector<vector<int>> parseTable(50,vector<int>(50,0));
vector<char> leftr;
vector<string> rightr;
vector<char> terminals,variables;
void initialGrammer(){
    leftr.push_back('E');rightr.push_back("TQ");
    leftr.push_back('Q');rightr.push_back("+TQ");
    leftr.push_back('Q');rightr.push_back("@");
    leftr.push_back('T');rightr.push_back("FN");
    leftr.push_back('N');rightr.push_back("*FN");
    leftr.push_back('N');rightr.push_back("@");
    leftr.push_back('F');rightr.push_back("(E)");
    leftr.push_back('F');rightr.push_back("i");
    //variables
    variables.push_back('E');
    variables.push_back('Q');
    variables.push_back('T');
    variables.push_back('N');
    variables.push_back('F');
    //termials
    terminals.push_back('i');
    terminals.push_back('+');
    terminals.push_back('*');
    terminals.push_back('(');
    terminals.push_back(')');
    terminals.push_back('$');

    

}
int findTerminal(char ch){
    for(int i=0;i<terminals.size();i++){
        if(ch==terminals[i]){
            return i;
        }
    }
    return 0;
}
int findVariable(char ch){
    for(int i=0;i<variables.size();i++){
        if(ch==variables[i]){
            return i;
        }
    }
    return 0;
}

void createParseTable(){
        
        parseTable[0][0]=1;parseTable[0][3]=1;
        parseTable[1][1]=2;parseTable[1][4]=3;parseTable[1][5]=3;
        parseTable[2][0]=4;parseTable[2][3]=4;
        parseTable[3][1]=6;parseTable[3][2]=5;parseTable[3][4]=6;parseTable[3][5]=6;
        parseTable[4][0]=8;parseTable[4][3]=7;
}
 bool solve(string inputString){
    initialGrammer();
    createParseTable();
        stack<char> stk;
        stk.push('$');
        stk.push('E');
        inputString+='$';
        //cout<<inputString;
        int i=0;
        while(i<inputString.length()){
            if(stk.top()==inputString[i]){
                if(stk.top()=='$'){
                    return true;
                }
                stk.pop();
                i++;
            }
            else{
                //cout<<findVariable(stk.top())<<findTerminal(inputString[i]);
                
                int j=parseTable[findVariable(stk.top())][findTerminal(inputString[i])];
                if(j<1){
                    return false;
                }
                string s=rightr[j-1];
                cout<<leftr[j-1]<<"-->"<<rightr[j-1]<<endl;
                stk.pop();
                for(int i=s.length()-1;i>=0;i--){
                    if(s[i]!='@'){
                   stk.push(s[i]);
                    }
                }
            }
        }
        return false;
 }
int main(){
        string inputString;
        cin>>inputString;
        if(solve(inputString)){
            cout<<"Accepted!\n";
        }
        else{
            cout<<"Rejected!\n";
        }
}