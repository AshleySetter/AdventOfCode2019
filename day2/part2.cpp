#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <typeinfo>

// pass vector by reference as passing the vector intself creates a copy
void read_initial_state(std::vector<int> &Intcode){
  std::ifstream readfile;
  std::string filetext;
  
  readfile.open("input.txt");
  getline(readfile, filetext); 
  readfile.close();
  //  std::cout << filetext << "\n";
  std::stringstream ss(filetext);

  // ss >> i reads the stringstream ss and because i is an integer
  // it reads characters which make up an integer until it gets
  // a character which can't be in a integer and stops
  // it also returns the condition true while integers are found
  // and returns false when an integer is not found so it
  // can't put any integer into i
  for(int i; ss >> i;){    
    Intcode.push_back(i); // pushes the extracted integer into the vector Intcode
    if (ss.peek() == ','){ // ss.peak returns the next character in the input sequence
      // without extracting it - allows you to check what it is
      ss.ignore(); // this line extracts the character from the input sequence and discards it
      // this is only performed if the next char is a ','
    }
  }
  /*  for(auto i = Intcode.begin(); i != Intcode.end(); i++){
    std::cout << *i << "\n";
    }*/
  return;
}

// in this case we want to work on a copy of the original vector so we do not pass it as a reference
int compute_output(int noun, int verb, std::vector<int> Intcode){
  std::string token;
  
  Intcode.at(1) = noun;
  Intcode.at(2) = verb;
  
  for(int i=0; Intcode.at(i) != 99; i+=4){
    if (Intcode.at(i) == 1){
      Intcode.at(Intcode.at(i+3)) = Intcode.at(Intcode.at(i+1)) + Intcode.at(Intcode.at(i+2));
    }
    else if (Intcode.at(i) == 2){
      Intcode.at(Intcode.at(i+3)) = Intcode.at(Intcode.at(i+1)) * Intcode.at(Intcode.at(i+2));
    }
    else{
      std::cout << "Invalid Opcode, " << "got opcode " << Intcode.at(i) << "\n";
      return -1;
    }
  }
  /*  for(auto i = Intcode.begin(); i != Intcode.end(); i++){
    std::cout << *i << "\n";
    }*/
  return Intcode.at(0);
}

int part2(){
  std::vector<int> Intcode;
  int output;
  
  read_initial_state(Intcode);
  /*  for(auto i = Intcode.begin(); i != Intcode.end(); i++){
    std::cout << *i << "\n";
    }*/
  for(int noun=0; noun<100; noun++){
    for(int verb=0; verb<100; verb++){
      output = compute_output(noun, verb, Intcode);
      if(output == 19690720){
	return 100*noun + verb;
      }
    }
  }
  return -1;
}

int main(){
  int result;

  result = part2();
  std::cout << result << "\n";
  return 0;
}
