//wipro milestone 2 question
#include<bits/stdc++.h>
using namespace std;

string userIdgeneration(string firstName, string lastName, int N, int pin){
    string shorterName;
    string longerName;
    string newPin = to_string(pin);

    if(firstName.length() > lastName.length()){
        shorterName = lastName;
        longerName = firstName;
    }
    else if(firstName.length() < lastName.length()){
        shorterName =firstName;
        longerName = lastName;
    }
    else if(firstName.length() == lastName.length()){
        if(firstName.compare(lastName) > 0){
            shorterName = lastName;
            longerName = firstName;
        }
        else{
            shorterName = firstName;
            longerName = lastName;
        }
    }
    string userID = shorterName[0] + longerName;
    
    for(int i = 0;i < userID.length();i++){
        if(isupper(userID[i]))
            userID[i] = tolower(userID[i]);
        else if(islower(userID[i]))
            userID[i] = toupper(userID[i]);    
    }
    userID = userID + newPin[N-1] + newPin[newPin.length()-N];
    return userID;
}
int main(){

string firstName = "Rajiv";
string lastName = "Roy";
int N = 6;
int pin = 560037;

cout<<userIdgeneration(firstName, lastName, N, pin);
}