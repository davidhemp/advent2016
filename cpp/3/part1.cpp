#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int main(){
    using namespace std;
    string line;
    string item;
    int count = 0;
    ifstream f ("input.txt");
    if (f.is_open()){
        while(getline(f, line)){
            vector<int> values;
            std::stringstream ssin(line);
            while (ssin.good()){
                ssin >> item;
                values.push_back(stoi(item));
            }
            sort(values.begin(), values.end());
            if (values[0] + values[1] > values[2]){
                count++;
            }
        }
        f.close();
    } else {
        cout << "Can not open file";
    }
    cout << count << endl;
}
