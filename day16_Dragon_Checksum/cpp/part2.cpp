#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> shuffle(vector<int> &input_vector){
    vector<int> output_vector (input_vector.size()*2+1, 0);
    int i = 0;
    int j = output_vector.size()-1;
    for(;i<input_vector.size();){
        output_vector[i] = input_vector[i];
        output_vector[j] = abs(input_vector[i]-1);
        i++;
        j--;
    }
    return output_vector;
}

vector<int> checksum(vector<int> &data){
    vector<int> rtn;
    while (data.size()%2 == 0){
        for (int i = 0; i < data.size(); i+=2){
            if (data[i]== data[i+1]){
                rtn.push_back(1);
            } else {
                rtn.push_back(0);
            }
        }
        data = rtn;
        rtn.clear();
    }
    return data;
}

void run(){
    int length_needed = 35651584;
    char input[] = {"11110010111001001"};
    vector<int> input_vector;
    for (int i =0; i < sizeof(input)-1;++i){
        input_vector.push_back((int)input[i] - 48);
    }
    while (input_vector.size() < length_needed){
        input_vector = shuffle(input_vector);
    }
    input_vector.resize(length_needed);
    vector<int> check_sum = checksum(input_vector);
    for (auto i:check_sum){
        cout << i;
    }
    cout << endl;
}

int main(){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << duration << endl;
}
