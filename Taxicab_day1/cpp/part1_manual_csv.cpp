#include <iostream>
#include <string>

int main(){
    int coords[4] = {0, 0, 0, 0};
    char comp[4] = {'N', 'E', 'S', 'W'};
    signed int currentDirection = 0;
    std::string inputString = "L1, R3, R1, L5, L2, L5, R4, L2, R2,";
    std::string dictionsStringList[20];
    std::string stepString;
    int j = 0;
    for (int i = 0; i < inputString.length(); i++){
        switch (inputString[i]) {
            case ',':
                dictionsStringList[j] = stepString;
                ++j;
                stepString.clear();
            case ' ':
                break;
            default:
                stepString.push_back(inputString[i]);
        }
    }
    for (int i = 0; i < 9; i++){
        if(dictionsStringList[i][0] == 'L'){
                --currentDirection;
                if (currentDirection < 0){
                    currentDirection = 3;
                }
        } else {
                ++currentDirection;
                if (currentDirection > 3){
                    currentDirection = 0;
                }
        }

        int move = std::stoi(dictionsStringList[i].erase(0,1));
        std::cout << currentDirection << " " << move << comp[currentDirection]<< std::endl;
        coords[currentDirection] += move;
    }
    int x = coords[1] - coords[3];
    int y = coords[0] - coords[2];
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
}
