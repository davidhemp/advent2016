#include <stdio.h>
#include <iostream>
#include <string.h>
#include <openssl/md5.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void function(){
    // char doorID[] = "abc";
    char doorID[] = "uqwqemis";
    int intAdded = 0;
    char str[20];
    unsigned char digest[MD5_DIGEST_LENGTH];
    char mdString[33];
    int zeroCount = 0;
    int n = 0;
    char result[] = "--------";
    while (n < 8){
        snprintf(str, 20, "%s%d", doorID, intAdded);
        MD5((unsigned char*)&str,
            strlen(str),
            (unsigned char*)&digest);

        for (int i = 0; i < 3; i++){
            sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
        }
        for (int i = 0; i < 5; i++ ){
            if (mdString[i] == '0'){
                zeroCount++;
            }
        }
        if (zeroCount == 5){
            result[n] = mdString[5];
            printf("%s : %s : %d : %s \n", str, mdString, n, result);
            n++;
        }
        zeroCount = 0;
        intAdded++;
    }
    // printf("Result: %s\n", result);

}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    function();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
