#include <stdio.h>
#include <iostream>
#include <string.h>
#include <openssl/md5.h>

#include <sys/time.h>
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main()
{
    using namespace std;
    timestamp_t t0 = get_timestamp();
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
    printf("Result: %s\n", result);
    timestamp_t t1 = get_timestamp();
    double secs = (t1 - t0) / 1000000.0L;
    cout << secs << " seconds" <<endl;
}
