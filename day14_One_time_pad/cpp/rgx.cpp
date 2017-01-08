#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main(){
    smatch match;
    regex count3RGX("([A-Za-z0-9])\\1{2}");
    string line = "0034e0923cc38887a57bd7b1d4f953df";
    if (regex_search (line, match, count3RGX)){
        cout << match[0];
        for (auto x:match){
            cout << x << " ";
        }
    }
}
