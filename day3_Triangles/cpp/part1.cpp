#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void function(){
    int num_tri = 0;
    string line;
    string item;
    ifstream f ("input.txt");
    vector<int> values(3, 0);
    if (f.is_open()){
        stringstream ssin;
        while(getline(f, line)){
            ssin << line;
            for (int i = 0; i < 3; i++){
                ssin >> item;
                values[i] = stoi(item);
            }
            sort(values.begin(), values.end());
            if (values[0] + values[1] > values[2]){
                num_tri++;
            }
            ssin.clear();
        }
        f.close();
        cout << num_tri << endl;
    } else {
        cout << "Can not open file";
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
