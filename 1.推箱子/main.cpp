#include <iostream>
#include <string>
#include<vector>
#include"push.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;


int main() {
  int length = 0;
  int width = 0;
  GameSystem game_system;
  game_system.GameGuide();
  game_system.GetMapSize(length, width);
  vector<char> map = game_system.GetMap(length,width);
  

  while (true) {
    game_system.Draw(map,width);
    if(game_system.CheckClear(map, length, width))break;
    cout << "\n输入方向，a向左，d向右，w向上，s向下\n" << endl;
    char input;
    while (cin.get(input)) {
      if (input == 'a' || input == 's' || input == 'w' || input == 'd') {
        break;
      }
    }
    game_system.Update(map,input,length,width);   
  }
}