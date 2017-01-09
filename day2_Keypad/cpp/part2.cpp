#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void function(){
    vector<int> currentDigit = {1,3};
    // Diamond shape
    vector<vector<int>> forbidden = { {3,0},
                                      {2,1}, {4,1},
                                      {1,2}, {5,2},
                                      {0,3}, {6,3},
                                      {1,4}, {5,4},
                                      {2,5}, {4,5},
                                      {3,6} };
    // Square, used for testing
    // vector<vector<int>> forbidden = { {0,-1}, {1,-1}, {2,-1},
                                        //  {-1,0}, {3,0},
                                        //  {-1,1}, {3,1},
                                        //  {-1,2}, {3,2},
                                        //  {0,3}, {1,3}, {2,3} };
    string direction;
    vector<int> nextDigit = {0,0};

    string p;
    ifstream f ("input.txt");
    if (f.is_open()){
        while(getline(f, p)){
            nextDigit =  currentDigit;
            for (int i = 0; i < p.length(); i++){
                direction = p[i];
                if (direction.compare("U") == 0){
                    nextDigit[1]--;
                }
                if (direction.compare("D") == 0){
                    nextDigit[1]++;
                }
                if (direction.compare("R") == 0){
                    nextDigit[0]++;
                }
                if (direction.compare("L") == 0){
                    nextDigit[0]--;
                }
                for (int k = 0; k < forbidden.size(); k++){
                    if (nextDigit == forbidden[k]){
                        nextDigit = currentDigit;
                    }
                }
                currentDigit = nextDigit;
            }
            cout << currentDigit[0] << ", " << currentDigit[1] << endl;
        }
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
