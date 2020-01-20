#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

int calculate_fuel(float mass){
  float result;
  int flooredresult;
  int fuel;
  result = mass/3;
  flooredresult = std::floor(result); // round down mass/3
  fuel = flooredresult - 2; // fuel needed is floor(mass/3)-2
  if (fuel <= 0){
    return 0;
  }
  else{
    return fuel + calculate_fuel(fuel);
  }
}

int test(int N){
  if (N == 0){
    return 0;
  }
  return N + test(N-1);
}

int part2(){
  std::ifstream readfile;
  std::string filetext;
  float mass;
  int fuel_required;
  int total_fuel = 0;
  
  readfile.open("input.txt");
  while(getline(readfile, filetext)){  // standard pattern to read a file (don't use eof)
    mass = std::stoi(filetext); // convert string to integer
    fuel_required = calculate_fuel(mass); // calculates fuel for module and fuel's masss
    total_fuel += fuel_required; // increment total fuel
  }
  readfile.close();
  return total_fuel;
}


int main(){
  int total_fuel;
  for(int i=0; i<100000; i++){
    total_fuel = part2(); // run code 100000 times to get average execution time
  }
  std::cout << total_fuel << "\n";

}
