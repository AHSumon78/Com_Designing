#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool isOperatorwithBracket(char ch)
{
    return (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '(' or ch == ')');
}
bool isOperator(char ch)
{
    return (ch == '+' or ch == '-' or ch == '*' or ch == '/');
}
vector<string> split(string st)
{

    int f = 0;
    vector<string> words;
    for (int i = 0; i < st.length(); i++)
    {
        if (isOperatorwithBracket(st[i]))
        {
            if (st.substr(f, i - f).length())
            {
                words.push_back(st.substr(f, i - f));
            }
            f = i + 1;
        }
    }
    if (st.substr(f).length())
    {
        words.push_back(st.substr(f));
    }
    return words;
}
bool bracketCheck(string st)
{
    stack<char> bracket;

    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] == '(')
        {
            bracket.push(st[i]);
        }
        if (st[i] == ')')
        {
            if (!bracket.empty())
            {
                bracket.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (!bracket.empty())
    {
        return false;
    }
    return true;
}
bool operatorCheck(string st)
{
    int n = st.length() - 1;
    if (isOperator(st[0] or isOperator(st[n])))
    {
        return false;
    }
    for (int i = 1; i < n; i++)
    {
        if (isOperator(st[i]) and isOperator(st[i - 1]))
        {
            return false;
        }
        if ((isOperator(st[i]) and st[i - 1] == '(') or (st[i] == ')' and isOperator(st[i - 1])))
        {
            return false;
        }
    }
    return true;
}
bool isKeyword(string word)
{
    string keywords[] = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
        "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
        "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast",
        "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
        "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern",
        "false", "float", "for", "friend", "goto", "if", "inline", "int", "long",
        "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator",
        "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
        "requires", "return", "short", "signed", "sizeof", "static", "static_assert",
        "static_cast", "struct", "switch", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"};
    for (string a : keywords)
    {
        if (word == a)
        {
            return true;
        }
    }
    return false;
}
bool validIdentifier(string word)
{
    if (isKeyword(word))
    {
        return false;
    }

    if (!(word[0] == '_' or isalpha(word[0])))
    {
        return false;
    }
    for (int i = 1; i < word.length(); i++)
    {
        if (!(word[i] == '_' or isalnum(word[i])))
        {
            return false;
        }
    }
    return true;
}
bool isInteger(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (!isdigit(word[i]))
        {
            return false;
        }
    }
    return true;
}
bool validIdentifierOrInteger(vector<string> words)
{

    for (string word : words)
    {
        //  cout<<word<<" :"<<validIdentifier(word)<<":V:"<<isInteger(word)<<endl;
        if (!(validIdentifier(word) or isInteger(word)))
        {
            return false;
        }
    }
    return true;
}
bool isValid(string st)
{
    // cout<<operatorCheck(st)<<":B:"<<bracketCheck(st)<<endl;
    if (operatorCheck(st) and bracketCheck(st) and validIdentifierOrInteger(split(st)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("ComD12.txt", "r", stdin);
    string s = "b-c+jffkjn+g";

    while (getline(cin, s))
    {

        cout << s << endl;
     /*  vector<string> vs = split(s);
        for (string v : vs)
        {
            cout <<"\'"<< v <<"\' ";
        }
        cout << endl;
       */ 
        if (isValid(s))
        {
            cout << "Valid!\n\n";
        }
        else
        {
            cout << "Invalid\n\n";
        }
    }

    return 0;
}