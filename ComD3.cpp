#include<iostream>
#include <map>
using namespace std;
int main (){
    string code;
    cin>>code;
    map<string,string> departments;
    departments.insert({"CSE","Computer Science & Engineering"});
    departments.insert({"EEE","Electrical & Electronic Engineering"});
    departments.insert({"ICE","Information & Communication Engineering"});
    departments.insert({"MSE","Material Science & Engineering"});

//Dept from input
    string dept= code.substr(0,3);
     if(departments[dept]==""){
      cout<<dept<<" Department is not found!\n";
      return 1;
  }
   // cout<<dept;
    string result="";
    result+=(departments[dept]+", ");
    map<char,string> year;
    year.insert({'1',"1st Year"});
    year.insert({'2',"2nd year"});
    year.insert({'3',"3rd year"});
    year.insert({'4',"4th year"});
    if(code.length()>3){
     if(year[code[3]]==""){
      cout<<code[3]<<" year is not found!\n";
      return 1;
      }
    result+=(year[code[3]] +", ");
    }
    map<char,string> semister;
    semister.insert({'1',"1st semister"});
    semister.insert({'2',"2nd semister"});
    result+=semister[code[4]]+", ";
   

     map < char, string > course;
    course.insert({'1', "Software Engineering"});
    course.insert({'2', "Database Management Systems"});
    course.insert({'3', "Web Engineering"});
    course.insert({'4', "Compiler Design"});
    course.insert({'5', "Engineering Ethics"});
    course.insert({'6', "Communication Engineering"});
    course.insert({'6', "Mobile Application Development"});
    result+=course[code[5]]+", ";
    map < char, string > type;
    type.insert({'1', "Therory"});
    type.insert({'2', "Lab"});
    result+=course[code[6]];
     cout<<result;
}