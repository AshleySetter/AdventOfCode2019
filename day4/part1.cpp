#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

std::pair<int, int> read_input_range(){
  std::ifstream readfile;
  std::string filetxt;
  std::stringstream ss;
  int start_range;
  int end_range;
  std::pair<int, int> range;
  
  readfile.open("input.txt");
  getline(readfile, filetxt); // path of wire 1
  readfile.close();
  ss << filetxt;
  ss >> range.first;
  ss.ignore(); // skip - seperating character
  ss >> range.second;
  return range;
}

void part1(){
  std::pair<int, int> range = read_input_range();

  std::string number;
  std::stringstream ss;
  int last_digit;
  bool never_decrease;
  bool adjacent_same;
  int num_of_valid_passwords;
  for(int i=range.first; i<range.second+1; i++){
    last_digit = 0;
    never_decrease = 1;
    adjacent_same = 0;
    number = std::to_string(i);
    ss << number;
    for(char digit; ss >> digit;){
      int idigit = digit - '0'; // a - '0' is equivalent to ((int)a) - ((int)'0'), which means the ascii values of the characters are subtracted from each other. Since 0 comes directly before 1 in the ascii table (and so on until 9), the difference between the two gives the number that the character a represents.
      if(idigit < last_digit){
	never_decrease = 0;
      }
      if(idigit == last_digit){
	adjacent_same = 1;
      }
      last_digit = idigit;
    }
    if(never_decrease && adjacent_same){
      num_of_valid_passwords++;
    }
    ss.clear();
  }
  std::cout << num_of_valid_passwords << "\n";
    
  return;
}

int main(){
  part1();
  return 0;
}
