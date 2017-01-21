#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <thread>
#include <mutex>
#include <openssl/md5.h>
#include <regex>
#include <chrono>

using namespace std;
using namespace std::chrono;

static const int num_threads = 10;

struct key{
    int x;
    string hash;
    string letter;
    bool used;
};
list<key> keyList;
mutex key_list_mutex;
list<int> keys;
mutex keys_mutex;

void md5_thread(int intAdded) {
    // char salt[] = "ihaygndm";
    char salt[] = "ihaygndm";
    char str[33];
    unsigned char digest[MD5_DIGEST_LENGTH];
    snprintf(str, 33, "%s%d", salt, intAdded);
    for (int n = 0; n < 2017; ++n){
        MD5((unsigned char*)&str,
        strlen(str),
        (unsigned char*)&digest);
        for (int i = 0; i < 16; i++){
            sprintf(&str[i*2], "%02x", (unsigned int)digest[i]);
        }
    }
    cmatch match;
    regex count3RGX("([a-f0-9])\\1{2,}");
    if (regex_search (str, match, count3RGX)){
        lock_guard<mutex> list_guard(key_list_mutex);
        if (match[0].length() >=5){
            for (key k : keyList){
                if (k.letter == match[1] &&
                    intAdded - k.x < 1001 &&
                    k.used != true){
                        lock_guard<mutex> count_guard(keys_mutex);
                        keys.push_back(k.x);
                        k.used = true;
                    }
                }
        } else {
            key k = {intAdded, str, match[1], false};
            keyList.push_back(k);
        }
    }
}

int run() {
     thread t[num_threads];
     int j = 0;
     while (keys.size() < 64){
         for (int i = 0; i < num_threads; ++i) {
             t[i] = thread(md5_thread, j);
             j++;
         }
         for (int i = 0; i < num_threads; ++i) {
             t[i].join();
         }
     }
     keys.sort();
     j = 1;
     for (int i : keys){
         cout << j << " : " << i << endl;
         j++;
     }
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<seconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
