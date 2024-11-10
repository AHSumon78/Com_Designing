#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<string> splitString(string st, char delimiter)
{
    vector<string> words;
    int f = 0, l = 0;
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] == ' ')
        {
            words.push_back(st.substr(f, i - f));
            f = i + 1;
        }
    }
    words.push_back(st.substr(f));
    return words;
}

bool isVowel(char ch)
{
    ch = tolower(ch);
    if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isLetter(char ch){
    ch=tolower(ch);
    if(ch>='a'&&ch<='z'){
        return true;
    }
    else{
        return false;
    }
}

int main()
{

    freopen("ComD2.txt", "r", stdin);
    string line;
    getline(cin, line);
    cout << line;
    vector<string> words = splitString(line, ' ');
    set<char> vowels, consonants;
    int numVowel = 0, numConsonent = 0;
    string vowelsString="",consonentString="";
    for(int i=0;i<words.size();i++){
        if(isLetter(words[i][0]))
        if(isVowel(words[i][0])){
            vowelsString+=words[i];
            vowelsString+=" ";
        }
        else {
            consonentString+=words[i];
            consonentString+=" ";
        }
    }
    for (int i = 0; i < line.length(); i++)
    {
        if(isLetter(line[i]))
        if (isVowel(line[i]))
        {
            numVowel++;
            vowels.insert(tolower(line[i]));
        }
        else if (line[i] != ' ')
        {
            numConsonent++;
            consonants.insert(tolower(line[i]));
        }
    }

    cout << "\nNo of vowels present in the string    :" << numVowel << endl;
    cout << "No of consonent present in the string :" << numConsonent << endl;
    cout << "Vowels present in the string are :";
    for (char ch : vowels)
    {
        cout << "\'" << ch << "\' ";
    }
    cout << "\nConsonents present in the string are :";
    for (char ch : consonants)
    {
        cout << "\'" << ch << "\' ";
    }
    cout<<endl;
    cout<<"Vowel String     : "<<vowelsString<<endl;
    cout<<"Consonent String : "<<consonentString<<endl;
}