#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <map>

void FQ() {
    std::map <char, int> maper;
    std::ifstream file ("/Users/odner/GitHub/university-tasks/work-with-file/first-question.txt");

    if ( file.is_open() ) {
        char fileChar;
        while ( file ) {
            fileChar = file.get();
            maper[fileChar]++;
        }
    }

    for (const auto& [key, value] : maper) {
        std::cout << key << "\t" << static_cast<float>(value) / static_cast<float>(maper.size()) << std::endl;
    }
}

bool checkNumber(std::string data){
    char& back = data.back();
    if (back == '0' || back == '1' || back == '2' || back == '3' || back == '4' ||
        back == '5' || back == '6'|| back == '7' || back == '8' || back == '9') {
        return true;
    }
    return false;
}

void SQ() {
    int arrNumLen = 0;
    std::vector<std::string> arrNum;

    std::ifstream file ("/Users/odner/GitHub/university-tasks/work-with-file/second-question.txt");
    if ( file.is_open() ) {
        char fileChar = '\n';

        while ( file ) {
            std::string fileLastString{fileChar};
            fileChar = file.get();
            std::string fileString{fileChar};

            if (checkNumber(fileLastString)) {
                if (checkNumber(fileString)) {
                    arrNum[arrNumLen-1] = arrNum[arrNumLen-1] + fileString;
                }
            } else {
                if (checkNumber(fileString)) {
                    arrNum.push_back(fileString);
                    arrNumLen++;
                }
            }
        }
    }
    std::ofstream newFile("/Users/odner/GitHub/university-tasks/work-with-file/second-question-output.txt");
    for (const auto & i : arrNum) {
        if (stoi(i) % 2 == 0) {
            newFile << i << " ";
        }
    }


}

int main() {
    SQ();
    return 0;
}
