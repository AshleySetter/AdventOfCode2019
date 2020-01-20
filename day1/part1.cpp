#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

int part1(){
  std::ifstream readfile;
  std::string filetext;
  float mass;
  float result;
  int flooredresult;
  int total_fuel = 0;
  
  readfile.open("input.txt");
  while(getline(readfile, filetext)){  // standard pattern to read a file (don't use eof)
    mass = std::stoi(filetext); // convert string to integer
    result = mass/3;
    flooredresult = std::floor(result); // round down mass/3
    total_fuel += flooredresult - 2; // increment total fuel with value (mass/3-2)
  }
  readfile.close();
  return total_fuel;
}

int main(){
  int total_fuel;
  for(int i=0; i<100000; i++){
    total_fuel = part1(); // run code 100000 times to get average execution time
  }
  std::cout << total_fuel << "\n";
}
