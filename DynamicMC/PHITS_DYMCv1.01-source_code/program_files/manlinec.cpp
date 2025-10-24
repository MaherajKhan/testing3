#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int number_of_lines = 0;
    std::string line;
    std::ifstream myfile("manualinp.tmp");

    while (std::getline(myfile, line))
        ++number_of_lines;
  ofstream outfile;
  outfile.open ("manlines.tmp");
  outfile << (number_of_lines -1);
  outfile.close();
 // cout << number_of_lines-1 << endl;
    return 0;
}
