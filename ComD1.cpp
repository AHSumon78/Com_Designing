#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool isLetter(char ch)
{
    ch = tolower(ch);
    if (ch >= 'a' && ch <= 'z')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void printVector(vector<char> vec){
  for(int i=0;i<vec.size();i++){
    cout<<"\'"<<vec[i]<<"\'";
    if(i!=vec.size()-1){
     cout<<", ";
    }
  }
  cout<<endl;

}
int main()
{
    vector<char> letters,digit,others;
    freopen("ComD1.txt","r",stdin);
    string line;
    getline(cin,line);
    cout<<line;
    int n=line.length();
    int words=0;
    for(int i=0;i<n;i++){
        if(i<n-1 and line[i]==' ' and line[i+1]!=' '){
            words++;
        }
        if(isLetter(line[i])){
            letters.push_back(line[i]);
        }
       else if(isdigit(line[i]))
        {
            digit.push_back(line[i]);
        }
      else if(line[i]!=' '){
        others.push_back(line[i]);
      }
      
    }
    cout<<endl;
    cout<<"No of words :"<<words<<endl;
    cout<<"No of letters :"<<letters.size()<<endl;
    cout<<"No of digit :"<<digit.size()<<endl;
    cout<<"No of other character :"<<others.size()<<endl;
    cout<<endl;
    printVector(letters);
    printVector(digit);
    printVector(others);
    
}