#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <openssl/md5.h>

using namespace std;

string openDoors(string &passcode, string &path){
    char mdString[4];
    unsigned char digest[MD5_DIGEST_LENGTH];
    char str[20];
    snprintf(str, 20, "%s", (passcode+path).c_str());
    MD5((unsigned char*)&str,
        strlen(str),
        (unsigned char*)&digest);
    for (int i = 0; i < 2; i++){
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }
    return (string)mdString;
}

int main(){
    vector<int> pos {0,0};
    string passcode = "hijkl";
    string path;
    string doors = openDoors(passcode, path);
    vector<char> directions {'U','D','L','R'};
    string open;
    for (int i=0; i < 4; ++i){
        if ((int)doors[i] > 97){
            open += directions[i];
        }
        cout << doors[i] << endl;
    }
    cout << open << endl;
}
