#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() { 
    int number_of_lines = 0;
    std::string line;
    std::ifstream myfile("runphits.bat");

    while (std::getline(myfile, line))
        ++number_of_lines;
   // std::cout << "Number of lines in text file: " << number_of_lines;
  ofstream outfile;
  outfile.open ("dynamics_points.tmp");
  outfile << (number_of_lines/4);
  outfile.close();
    return 0;
}