// Shunting Yard algorithm to convert infix to postfix notation
// Example 
// Infix : A + B * C
// Postfix : A B C * +

#include<bits/stdc++.h>
using namespace std;

int precedence(string s){
    if(s == "+" || s == "-")
        return 1;
    else if(s == "*" || s == "/")
        return 2;
    else if(s=="^")
        return 3;
  return 0;
}
vector<string> shuntingYard(vector<string> token) {
    stack<string> st;
    vector<string> output;
    for(int i=0;i<token.size();i++){
        string s = token[i];
        if(s == "+" || s == "-" || s == "*" || s == "/" || s== "^"){
            while(!st.empty() && precedence(st.top()) >= precedence(s)){
                output.push_back(st.top());
                st.pop();
            }
            st.push(s);
        }
        else if(s=="("){
            st.push(s);
        }
        else if(s==")"){
            while(st.top()!="("){
                output.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            output.push_back(s);
        }
    }
    while(!st.empty()){
        output.push_back(st.top());
        st.pop();
    }
    return output;
}
int main(){
    int n; cin>>n;
    vector<string>input;
    for(int i=0;i<n;i++){
        string token;
        cin>>token;
        input.push_back(token);
    }
    vector<string> output = shuntingYard(input);
    for(auto i:output){
        cout<<i<<" ";
    }
}