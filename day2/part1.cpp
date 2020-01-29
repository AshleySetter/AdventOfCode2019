#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <typeinfo>

int part1(){
  std::ifstream readfile;
  std::string filetext;
  std::vector<int> Intcode;
  std::string token;
  
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
  }
  std::cout << "after processing\n";*/
  Intcode.at(1) = 12;
  Intcode.at(2) = 2;
  
  for(int i=0; Intcode.at(i) != 99; i+=4){
    //    std::cout << Intcode.at(i) << " " << Intcode.at(i+3) << " "  << Intcode.at(i+1) << " "  << Intcode.at(i+2) << " "  << "\n";
    //    std::cout << typeid(Intcode.at(i)).name() << "\n";
    if (Intcode.at(i) == 1){
      //      std::cout << "opcode 1\n";
      Intcode.at(Intcode.at(i+3)) = Intcode.at(Intcode.at(i+1)) + Intcode.at(Intcode.at(i+2));
    }
    else if (Intcode.at(i) == 2){
      //      std::cout << "opcode 2\n";
      Intcode.at(Intcode.at(i+3)) = Intcode.at(Intcode.at(i+1)) * Intcode.at(Intcode.at(i+2));
    }
    else{
      std::cout << "Invalid Opcode, " << "got opcode " << Intcode.at(i) << "\n";
      return -1;
    }
    /*    for(auto i = Intcode.begin(); i != Intcode.end(); i++){
      std::cout << *i << "\n";
    }
    std::cout << "run" << i << "\n"; */
  }
  /*  for(auto i = Intcode.begin(); i != Intcode.end(); i++){
    std::cout << *i << "\n";
    }*/
  return Intcode.at(0);
}

int main(){
  int output;
  
  output = part1();
  std::cout << output << "\n";
  return 0;
}
