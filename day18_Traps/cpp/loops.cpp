#include <iostream>
#include <string>

using namespace std;

int main(){
    string input_str =
    ".^^..^...^..^^.^^^.^^^.^^^^^^.^.^^^^.^^.^^^^^^.^...^......^...^^^..^^^.....^^^^^^^^^....^^...^^^^..^";

    int safe_count = 0;
    for (auto c:input_str){
        if (c == '.'){
            ++safe_count;
            cout << c << " " << safe_count;
        }
        cout << " beep" << endl;
    }
    cout << safe_count << endl;
}
