#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <openssl/md5.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

static const int num_threads = 1;

void md5_thread(int intAdded) {
    // char salt[] = "ihaygndm";
    char salt[] = "abc";
    char str[33];
    unsigned char digest[MD5_DIGEST_LENGTH];
    char mdString[33];
    snprintf(str, 33, "%s%d", salt, intAdded);
    for (int n = 0; n < 2017; ++n){
        MD5((unsigned char*)&str,
        strlen(str),
        (unsigned char*)&digest);
        for (int i = 0; i < 16; i++){
            sprintf(&str[i*2], "%02x", (unsigned int)digest[i]);
        }
    }
    cout << str << " " << intAdded << endl;
}

int run() {
     thread t[num_threads];
     int j = 0;
     for (int i = 0; i < num_threads; ++i) {
         t[i] = thread(md5_thread, j);
         j++;
     }
     for (int i = 0; i < num_threads; ++i) {
         t[i].join();
     }
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
