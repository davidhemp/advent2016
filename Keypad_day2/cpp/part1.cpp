#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include <sys/time.h>
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(){
    timestamp_t t0 = get_timestamp();
    signed int y = 0;
    signed int x = 0;
    int yRepeats = 0;
    int xRepeats = 0;
    std::string digits [5];
    digits[0] = "RRDDLDDULDLLDU";
    digits[1] = "UURRLDDUDRUURUDLLDLDLURDLULDRLLLULLLUDLLDLD";
    digits[2] = "LLRRLLRDDULLDLDLDDLDLDULURRDURURDRDRRDLR";
    digits[3] = "DDRRRRLRLRDRURUDDRDLDRURLULDDL";
    digits[4] = "UUDDDLUDULRUUUUDRLDDD";
    std::string currentDigit;
    for (int j = 0; j < 5; j++){
        std::string digit = digits[j];
        for (int i = 0; i < digit.length(); i++){
            currentDigit = digit[i];
            if (currentDigit.compare("U") == 0){
                y--;
                if (y < 0){
                    y = 0;
                }
            }
            if (currentDigit.compare("D") == 0){
                y++;
                if (y > 2){
                    y = 2;
                }
            }
            if (currentDigit.compare("R") == 0){
                x++;
                if (x > 2){
                    x = 2;
                }
            }
            if (currentDigit.compare("L") == 0){
                x--;
                if (x < 0){
                    x = 0;
                }
            }
        }
        int n = (x+1) +(y*3);
        std::cout << x << ", " << y << ": " << n << std::endl;
    }
    timestamp_t t1 = get_timestamp();
    double secs = (t1 - t0) / 1000000.0L;
    std::cout << secs << " seconds" << std::endl;
}
