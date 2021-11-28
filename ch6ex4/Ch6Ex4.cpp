/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Tyler Goldsmith
 */

#include "std_lib_facilities.h"

class Name_Value{
    private:
        string name;
        int value;
    public:
        Name_Value();
        Name_Value(string N, int V);
        string getName();
        int getValue();
};

Name_Value::Name_Value(){}

Name_Value::Name_Value(string N, int V){
    name=N;
    value= V;
}

string Name_Value:: getName(){
    return name;
}

int Name_Value:: getValue(){
    return value;
}


//Checks if a given string is an integer by checking that each character is exclusively a number
bool isInteger(string str){
        for (int i = 0; i < str.length(); i++){
            if (isdigit(str[i]) == false){
                if(i==0 && str[0]=='+'||str[0]=='-'){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
}

bool allUnique(vector <Name_Value> Vec){
    //Note the last element of Vec is NoName 0 so it needs to be excluded
    if(Vec.size()>2){
    for(int i=0; i<Vec.size()-2; i++){
        for(int j=i+1; j<Vec.size()-1; j++){
            if(Vec[i].getName()==Vec[j].getName())
                return false;
        }
    }
}
    return true;
}

void printArray(vector <Name_Value> Vec){
    for(int i=0; i<Vec.size()-1; i++){
        cout <<Vec[i].getName() <<" " << Vec[i].getValue() <<"\n";
    }
}

int main(){
    cout <<"Enter Name Value combinations seperated by spaces, and break the code by entering NoName 0\n";
    cout <<"Note the program will not print names if any names are repeated\n\n";
    vector <Name_Value> allNameValues;

    do{
        cout <<"Enter a Name Value pair: ";
        string Name;
        string Value;
        cin >> Name >> Value;
        while (!isInteger(Value)){
            cout <<"Invalid input try again: ";
            cin >> Name >> Value;
        }
        allNameValues.push_back(Name_Value(Name,stoi(Value)));
    } while ((allNameValues[allNameValues.size()-1].getName()!="NoName"||allNameValues[allNameValues.size()-1].getValue()!=0));
    
    if(allUnique(allNameValues))
        printArray(allNameValues);
    else
        cout << "One of the names was repeated";
    }
