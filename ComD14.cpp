#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
map<char, vector<char>> first;
map<char, set<char>> follow;
set<char> terminal,variable;
map<char,int> tableCol,tableRow;
vector<vector<int>>  parseTable(50,vector<int>(50,0));

vector<char> leftr;
vector<string> rightr;
char firstVariable = ',';
void calFollow()
{
    follow[firstVariable].insert('$');
    char prev = ' ';
    for (int k = 0; k < leftr.size(); k++)
    {
        if (leftr[k] == prev)
        {
            continue;
        }
        prev = leftr[k];

        for (int i = 0; i < leftr.size(); i++)
        {
            for (int j = 0; j < rightr[i].length(); j++)
            {
                if (rightr[i][j] == prev)
                {
                AGAIN2:
                    if ((j + 1) == rightr[i].length())
                    {
                        for (auto gg : follow[leftr[i]])
                        {
                            follow[prev].insert(gg);
                        }
                    }
                    else if (isalpha(rightr[i][j + 1]) and rightr[i][j + 1] == toupper(rightr[i][j + 1]))
                    {
                        bool epsilon = false;
                        for (auto ff : first[rightr[i][j + 1]])
                        {
                            if (ff != '@')
                            {
                                follow[prev].insert(ff);
                            }
                            else
                            {
                                epsilon = true;
                            }
                        }
                        if (epsilon)
                        {
                            j += 1;
                            goto AGAIN2;
                        }
                    }
                    else
                    {
                        follow[prev].insert(rightr[i][j + 1]);
                    }
                }
            }
        }
    }
}
void printFirst()
{
    cout << "            First       Follow\n";
    int i = 0;
    map<char, set<char>>::iterator it = follow.begin();
    for (auto a : first)
    {
        i++;
        cout << "________________________________________\n";
        cout << "|  " << a.first << "  |      {";
        int j = 0;
        for (auto b : a.second)
        {
            cout << b;
            j++;
            if (j < a.second.size())
            {
                cout << ',';
            }
        }
        cout << "} ";

        j = 0;
        cout << "|  {";
        for (auto a : it->second)
        {
            cout << a;
            j++;
            if (j < it->second.size())
            {
                cout << ',';
            }
        }
        cout << "} " << endl;

        if (i == first.size())
        {
            cout << "________________________________________\n";
        }
        it++;
    }
}

int findchar(string st,char ch){
    int result=-1;
    for(int i=0;i<st.length();i++){
        if(st[i]==ch){
            result=i;
            return result;
        }
    }
    return result;
}
void inputGrammer()
{
    string line;
    int n;
    cout << "Enter the number of grammer: ";
    cin >> n;
    cout << "Enter  grammer\n";
    cin.ignore();
    string firstInput;
    while (n--)
    {
        getline(cin, line);
        int pos=findchar(line,' ');
        firstInput=line.substr(pos+1);
        line=line.substr(0,pos);
        for(char f:firstInput){
            first[line[0]].push_back(f);
        }
        if (firstVariable == ',')
        {
            firstVariable = line[0];
        }
        int f = 3;
        for (int i = 3; i < line.length(); i++)
        {
            if (line[i] == '|')
            {
                leftr.push_back(line[0]);
                rightr.push_back(line.substr(f, i - f));
                f = i + 1;
            }
        }
        leftr.push_back(line[0]);
        rightr.push_back(line.substr(f));
    }
}
void printGrammer()
{
    for (int i = 0; i < leftr.size(); i++)
    {
        cout << leftr[i] << "->" << rightr[i] << "\n";
    }
}
void getTerminaleVariable(){
    terminal.insert('$');
    for(int i=0;i<rightr.size();i++){
        for(auto a:rightr[i]){
            if(a!='@' and !(isalpha(a) and a==toupper(a)))
            terminal.insert(a);
        }
    }
    for(int i=0;i<leftr.size();i++){
        variable.insert(leftr[i]);
    }
    int col=0;
    for(auto ch: terminal){
          tableCol[ch]=col;
          col++;
    }
    int row=0;
    for(auto ch:variable){
        tableRow[ch]=row;
        row++;
    }
}
vector<char> findFirst(string r){
    vector<char> result;

    int x=r[0];
    if(isalpha(x) and x==toupper(x)){
       return first[x];
    }
    else{
        result.push_back(x);
    }
    return result;
}
void createPasingTable(){

    getTerminaleVariable();
    for(int i=0;i<leftr.size();i++){
      vector<char> tableFirst =findFirst(rightr[i]);
      
      for(char ch:tableFirst){
        if(ch!='@'){
            if(parseTable[tableRow[leftr[i]]][tableCol[ch]]==0)
            parseTable[tableRow[leftr[i]]][tableCol[ch]] = i+1;
            else{
                  parseTable[tableRow[leftr[i]]][tableCol[ch]] = -1;
            }
        }
        else{
            for(auto b:follow[leftr[i]]){
                if(parseTable[tableRow[leftr[i]]][tableCol[b]]==0)
                parseTable[tableRow[leftr[i]]][tableCol[b]] = i+1;
                else{
                    parseTable[tableRow[leftr[i]]][tableCol[b]]=-1;
                }
            }
        }
      }
    }

}
void printTable(){
    cout<<"   ";
    for(auto ch : terminal){
        cout<<ch<<"  ";
    }
    cout<<endl;
    int i=0;
    for(auto ch : variable){
        cout<< ch<<"  ";
        for(int j=0;j<terminal.size();j++){
            cout<<parseTable[i][j]<<"  ";
        }
        cout<<endl;
        i++;
    }
}

int main()
{
    inputGrammer();
    calFollow();
    printFirst();
    createPasingTable();
    printTable();
}

/*
E->TQ i(
Q->+TQ|@ +@
T->FN i(
N->*FN|@ *@
F->(E)|@ i(
*/