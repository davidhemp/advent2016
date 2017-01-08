#include <stdio.h>
#include <iostream>
#include <string>
#include <regex>
#include <list>
#include <openssl/md5.h>

using namespace std;

struct key{
    int x;
    string hash;
    string letter;
    bool used;
};

int main(){
    char salt[] = "ihaygndm";
    // char salt[] = "abc";
    int intAdded = 0;
    char str[20];
    unsigned char digest[MD5_DIGEST_LENGTH];
    char mdString[33];
    int keyCount = 0;
    cmatch match;
    list<key> keyList;
    int lastKey = 0;
    while (keyCount < 63){
        snprintf(str, 20, "%s%d", salt, intAdded);
        MD5((unsigned char*)&str,
            strlen(str),
            (unsigned char*)&digest);

        for (int i = 0; i < 16; i++){
            sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
        }
        regex count3RGX("([a-f0-9])\\1{2,}");
        if (regex_search (mdString, match, count3RGX)){
            if (match.size() > 2){
                cout << "beep" << endl;
            }
            if (match[0].length() >=5){
                for (key k : keyList){
                    if (k.letter == match[1] &&
                        intAdded - k.x < 1001 &&
                        k.used != true){
                            keyCount++;
                            if (k.x > lastKey){
                                lastKey = k.x;
                            }
                            // cout << k.letter << " found at "<< k.x;
                            // cout << " in "<< k.hash << ", confirmed in ";
                            // cout << intAdded << " with " << mdString << endl;
                            k.used = true;
                        }
                    }
            } else {
                key k = {intAdded, mdString, match[1], false};
                keyList.push_back(k);
            }
            // for (auto it = keyList.begin(); it != keyList.end(); ++it){
            //     key k = *it;
            //     if (k.used){
            //         keyList.erase(it);
            //     }
            // }
        }
        intAdded++;
    }
    printf("%i\n", lastKey);
}
