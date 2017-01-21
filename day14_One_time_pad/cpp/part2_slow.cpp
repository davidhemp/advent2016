#include <stdio.h>
#include <iostream>
#include <string>
#include <regex>
#include <list>
#include <openssl/md5.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct key{
    int x;
    string hash;
    string letter;
    bool used;
};

void run(){
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
        for (int n = 0; n < 2017; ++n){
            MD5((unsigned char*)&str,
            strlen(str),
            (unsigned char*)&digest);
            for (int i = 0; i < 16; i++){
                sprintf(&str[i*2], "%02x", (unsigned int)digest[i]);
            }
        }
        regex count3RGX("([a-f0-9])\\1{2,}");
        if (regex_search (str, match, count3RGX)){
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
                            // couts the keys, commented out for speed test
                            // cout << k.letter << " found at "<< k.x;
                            // cout << " in "<< k.hash << ", confirmed in ";
                            // cout << intAdded << " with " << mdString << endl;
                            k.used = true;
                        }
                    }
            } else {
                key k = {intAdded, str, match[1], false};
                keyList.push_back(k);
            }
            // Deleting the key once used messed with the it
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

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
