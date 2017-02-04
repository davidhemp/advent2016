#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <regex>
#include <chrono>
//Why can't you string switch!! lol

using namespace std;
using namespace std::chrono;
struct bot{
    int number=0;
    vector<int> chips;
    bot *low;
    bot *high;
};

int run(){
    ifstream txtFile("input.txt");
    if(txtFile.is_open()){
        int chip_count = 0;
        vector<bot> bots(220);
        for (int i=0; i < bots.size(); ++i){
            bots[i].number = i;
        }
        vector<bot> outputs(21);
        string line;
        smatch match;
        regex loadRGX("value (\\d+) goes to bot (\\d+)");
        regex flowRGX("(\\d+).*(bot|output) (\\d+).*(bot|output) (\\d+)");
        while(!txtFile.eof()){ //build network
                getline(txtFile, line);
                if (regex_search (line, match, loadRGX)){
                    bots[stoi(match[2])].chips.push_back(stoi(match[1]));
                    chip_count++;
                } else if (regex_search (line, match, flowRGX)){
                    bot *selected_bot = &bots[stoi(match[1])];
                    if (match[2].compare("bot") == 0){
                        selected_bot->low = &bots[stoi(match[3])];
                    } else {
                        selected_bot->low = &outputs[stoi(match[3])];
                    }
                    if (match[4].compare("bot") == 0){
                        selected_bot->high = &bots[stoi(match[5])];
                    } else {
                        selected_bot->high = &outputs[stoi(match[5])];
                    }
                }
            }
        txtFile.close();
        // let network propogate
        int output_count = 0;
        while (output_count < chip_count){
            //for some reason I couldn't get the iter to work?
            for (int b=0; b<bots.size(); ++b){
                bot *b_t = &bots[b];
                if (b_t->chips.size() == 2){
                    auto maxMin =
                        minmax_element(b_t->chips.begin(),b_t->chips.end());
                    if (*maxMin.first == 17 && *maxMin.second == 61){
                        cout << b_t->number << endl;
                    }
                    b_t->low->chips.push_back(*maxMin.first);
                    b_t->high->chips.push_back(*maxMin.second);
                    b_t->chips.push_back(0);
                }
            }
            output_count = 0;
            for (auto o:outputs){
                output_count += o.chips.size();
            }
        }
        int total = 1;

        for (int i = 0; i<outputs.size(); ++i){
            cout << i << ": " <<outputs[i].chips[0] << endl;
            if (i == 0 || i == 1 ||i == 2){
                total *= outputs[i].chips[0];
            }
        }
        cout << total << endl;

    }
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << duration << " milliseconds" << endl;
    return 0;
}
