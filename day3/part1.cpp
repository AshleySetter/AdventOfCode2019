#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int read_input(std::vector<char> &direction_vector_1, std::vector<int> &distance_vector_1, std::vector<char> &direction_vector_2, std::vector<int> &distance_vector_2){
  std::ifstream readfile;
  std::string filetext_wire1;
  std::string filetext_wire2;
  int distance;    
  std::stringstream ss;
    
  readfile.open("input.txt");
  getline(readfile, filetext_wire1); // path of wire 1
  getline(readfile, filetext_wire2); // path of wire 2
  readfile.close();
  //  std::cout << filetext << "\n";
  ss << filetext_wire1;
  for(char direction; ss >> direction;){ // pulls letter (R,L,U,D) as char, called direction, from stringstream
    ss >> distance; // pulls distance to travel as int from stringstream
    ss.ignore(); // skips the next character as it should be a comma (,)
    direction_vector_1.push_back(direction);
    distance_vector_1.push_back(distance);
  }
  ss.clear();
  ss << filetext_wire2;
  for(char direction; ss >> direction;){ // pulls letter (R,L,U,D) as char, called direction, from stringstream
    ss >> distance; // pulls distance to travel as int from stringstream
    ss.ignore(); // skips the next character as it should be a comma (,)
    direction_vector_2.push_back(direction);
    distance_vector_2.push_back(distance);
  }  
}

std::pair<int, int> move(int direction, int distance, std::pair<int, int> pos){
  if(direction == 'R'){pos.first + distance;}
  else if(direction == 'L'){pos.first - distance;}
  else if(direction == 'U'){pos.second + distance;}
  else if(direction == 'D'){pos.second - distance;}
  return pos;
}

std::vector<std::pair<int, int>> path_trace(std::vector<char> &direction_vector, std::vector<int> &distance_vector){
  std::vector<std::pair<int, int>> path;
  std::pair<int, int> pos (0, 0);
  char direction;
  int distance;
  
  for(int j=0; j<direction_vector.size(); j++){
    direction = direction_vector.at(j);
    distance = distance_vector.at(j);
    if(direction == 'R'){
      pos.first += distance;
      path.push_back(pos);
    }
    else if(direction == 'L'){
      pos.first -= distance;
      path.push_back(pos);
    }
    else if(direction == 'U'){
      pos.second += distance;
      path.push_back(pos);
    }
    else if(direction == 'D'){
      pos.second -= distance;
      path.push_back(pos);
    }
  }
  return path;
}


int part1(){
  std::vector<char> direction_vector_wire_1;
  std::vector<int> distance_vector_wire_1;
  std::vector<char> direction_vector_wire_2;
  std::vector<int> distance_vector_wire_2;

  // following function reads the file to get the list of directions and distances to move for the 2 wires
  read_input(direction_vector_wire_1, distance_vector_wire_1, direction_vector_wire_2, distance_vector_wire_2);

  // following function traces out the path the first wire traverses
  std::vector<std::pair<int, int>> path_wire_1 = path_trace(direction_vector_wire_1, distance_vector_wire_1);
  // following function traces out the path the second wire traverses
  std::vector<std::pair<int, int>> path_wire_2 = path_trace(direction_vector_wire_2, distance_vector_wire_2);

  
  // now we need to find the intersections
  


  
  std::vector<std::pair<int, int>>::iterator loc1;
  std::vector<std::pair<int, int>>::iterator loc2;
  std::vector<std::pair<int, int>> intersections;
  for(loc1 = path_wire_1.begin(); loc1 != path_wire_1.end(); loc1++){
    
    for(loc2 = path_wire_2.begin(); loc2 != path_wire_2.end(); loc2++){
      x0 = loc1->first;
      x1 = 
	
	intersections.push_back(*loc1);
	std::cout << "found one\n";
      }
    }
  }

  std::cout << intersections.size() << "\n";
  return 0;
}

int main(){
  part1();
  return 0;
}
