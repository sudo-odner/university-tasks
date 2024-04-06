#include <iostream>
#include <fstream>

void FQ() {
    std::ifstream input("/Users/odner/GitHub/university-tasks/work-with-bin-file/first-question.txt", std::ios::binary | std::ios::in);
    std::ofstream output("/Users/odner/GitHub/university-tasks/work-with-bin-file/test-question.bin", std::ios::binary | std::ios::out);
    std::string line;

    if ( input.is_open() ) {
        while (getline(input, line)) {
            if (line.find("НовГУ, 2007") != std::string::npos) {
                output.write(line.c_str(), line.size());
            }
        }
    }
    input.close();
    output.close();

    std::ifstream read("/Users/odner/GitHub/university-tasks/work-with-bin-file/test-question.bin", std::ios::binary);

    if (read.is_open()) {
        while (getline(read, line)) {
            std::cout << line << std::endl;
        }
    }
    read.close();
}

int main() {
    FQ();
    return 0;v
}
