#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
map<char, vector<char>> first;
map<char, set<char>> follow;

vector<char> leftr;
vector<string> rightr;
char firstVariable=',';
void calFollow(){
      follow[firstVariable].insert('$');
      char prev=' ';
      for(int k=0;k<leftr.size();k++){
           if(leftr[k]==prev){
            continue;
           }
           prev=leftr[k];
   
        for(int i=0;i<leftr.size();i++){
           for(int j=0;j<rightr[i].length();j++){
            if(rightr[i][j]==prev){
                AGAIN2:
                if((j+1)==rightr[i].length()){
                    for(auto gg: follow[leftr[i]]){
                        follow[prev].insert(gg); 
                    }
                }
               else if(isalpha(rightr[i][j+1]) and rightr[i][j+1]== toupper(rightr[i][j+1])){
                        bool epsilon=false;
                       for(auto ff:first[rightr[i][j+1]]){
                        if(ff!='@'){
                            follow[prev].insert(ff);
                        }
                        else{
                            epsilon=true;
                        }
                       }
                       if(epsilon){
                        j+=1;
                        goto AGAIN2;
                       }
                }
                else{
                    follow[prev].insert(rightr[i][j+1]);
                }
            }
           }
        }

      }

} 
void printFirst()
{
    cout<<"            First       Follow\n";
    int i=0;
    map<char,set<char>> :: iterator it=follow.begin();
    for (auto a : first)
    {
        i++;
        cout<<"________________________________________\n";
        cout <<"|  "<< a.first << "  |      {";
        int j=0;
        for (auto b : a.second)
        {
            cout << b ;
            j++;
            if(j<a.second.size()){
                cout<<',';
            }
        }
        cout << "} " ;


             j=0;
         cout <<"|  {";
         for(auto a : it->second){
            cout<<a;
            j++;
             if(j<it->second.size()){
                cout<<',';
            }
         }
         cout << "} "<<endl;
         
        if(i==first.size()){
           cout<<"________________________________________\n";
        }
       it++;
    }
}
void calFirst()
{

    int n = leftr.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        int firstvar = 0;
    AGAIN:
        if (isalpha(rightr[i][firstvar]) and rightr[i][firstvar] == toupper(rightr[i][firstvar]))
        {
            bool epsilon = false;
            for (auto a : first[rightr[i][firstvar]])
            {
                if (a != '@')
                {
                    first[leftr[i]].push_back(a);
                }
                else
                {
                    epsilon = true;
                }
            }
            if (epsilon)
            {
                firstvar++;
                if (firstvar < rightr[i].size())
                {
                    goto AGAIN;
                }
                else
                {
                    first[leftr[i]].push_back('@');
                }
            }
        }
        else
        {
            first[leftr[i]].push_back(rightr[i][firstvar]);
        }
    }
}
void inputGrammer()
{
    string line;
    int n;
    cout << "Enter the number of grammer: ";
    cin >> n;
    cout << "Enter  grammer\n";
    cin.ignore();
    while (n--)
    {
        getline(cin, line);
        if(firstVariable==','){
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
int main()
{
    inputGrammer();
   // printGrammer();
    calFirst();
    calFollow();
    printFirst();
}