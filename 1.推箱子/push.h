#ifndef SOKOBAN_PUSH_H_	
#define SOKOBAN_PUSH_H_


#include<string>
#include<vector>

using std::vector;

class GameSystem {
 public:  
  void GameGuide(void)const;
  vector<char> GetMap(int length,int width) const;
  void GetMapSize(int& length, int& width);
  void Error(void);
  void Update(vector<char>& map,char input,int length,int width);
  bool CheckClear(const vector<char>& map,int length, int width);
  void Draw(const vector<char>& map,int width);
};

#endif