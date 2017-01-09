#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void function(){
    signed int y = 0;
    signed int x = 0;
    int yRepeats = 0;
    int xRepeats = 0;
    string digits [5];
    digits[0] = "RRDDLDDULDLLDU";
    digits[1] = "UURRLDDUDRUURUDLLDLDLURDLULDRLLLULLLUDLLDLD";
    digits[2] = "LLRRLLRDDULLDLDLDDLDLDULURRDURURDRDRRDLR";
    digits[3] = "DDRRRRLRLRDRURUDDRDLDRURLULDDL";
    digits[4] = "UUDDDLUDULRUUUUDRLDDD";
    string currentDigit;
    for (int j = 0; j < 5; j++){
        string digit = digits[j];
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
        cout << x << ", " << y << ": " << n << endl;
    }
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    function();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
