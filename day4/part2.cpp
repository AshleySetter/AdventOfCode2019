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
  int adjacent_count;
  bool adjacent_same;
  int num_of_valid_passwords;
  for(int i=range.first; i<range.second+1; i++){
    adjacent_count = 0;
    last_digit = 0;
    never_decrease = 1;
    adjacent_same = 0;
    number = std::to_string(i);
    ss << number;
    for(char digit; ss >> digit;){
      int idigit = digit - '0'; // a - '0' is equivalent to ((int)a) - ((int)'0'), which means the ascii values of the characters are subtracted from each other. Since 0 comes directly before 1 in the ascii table (and so on until 9), the difference between the two gives the number that the character a represents.
      if(idigit < last_digit){
	never_decrease = 0; // checks that digits don't increase in value
      }
      if(idigit == last_digit && !adjacent_same){
	adjacent_count++; // counts number of adjacent identical digits
      }
      else if(adjacent_count == 1){
	adjacent_same = 1; // if the next is not the same and we have counted 2 adjacent identical digits
      }
      else{
	adjacent_count = 0; // if the next is not the same and we have counted more than 2 adjacent identical digits reset the adjacent counter
      }
      last_digit = idigit;
    }
    if(adjacent_count == 1){ // checks if the final 2 numbers were an adjacent pair
      adjacent_same = 1; //  if the final 2 digits were counted as 2 adjacent identical digits
    }
    if(never_decrease && adjacent_same){
      num_of_valid_passwords++; // increment number of valid passwords
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
