#include<iostream>
#include<vector>
#include"push.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void GameSystem::GameGuide(void) const {
  cout << "��������Ϸ����\n" << endl;
  cout << "#����ǽ�ڣ��ո����յذ壬p�����ɫ��o�������ӣ� .��������Ŀ�ĵ�\n" << endl;
  cout << "��Ϸ�������뱻ǽ�ڰ���������ᷢ������й¶����\n" << endl;
  cout << "����\
                ########\n\
                # .. p #\n\
                # oo   #\n\
                #      #\n\
                ########"       << endl;
}
vector<char> GameSystem::GetMap(int length,int width) const {
  char map_get;
  vector<char> map(0);
  cout << "�����ͼ\n"<<endl;
  while (cin.get(map_get)) {
    if (map_get != ' ' && map_get != '#' && map_get != 'p' && map_get != '.' &&
        map_get != 'o' && map_get != '\n') {
      cout << "�������\n";
      break;
    } else if (map_get != '\n') {
      map.push_back(map_get);
    }
    if (map.size() == width*length) {
      cout << "������ϣ�ִ����һ��\n";
      break;
    }
  }  
  return map;
}
void GameSystem::GetMapSize(int& length, int& width) {
  cout << "���볡���ĳ��ȺͿ��\n" << endl;
  cin >> length >> width;
}
void GameSystem::Error(void){ 
     cout << "�������\n"; }
void GameSystem::Update(vector<char>& map, char input, int length, int width) {
  int dx = 0;
  int dy = 0;
  if (input == 'a') dx = -1;
  if (input == 'd') dx = 1;
  if (input == 'w') dy = -1;
  if (input == 's') dy = 1;
  int i = 0;
  for (i = 0; i < width * length; ++i) {
    if (map[i] == 'p' || map[i] == 'P') {
      break;
    }
  }

  int x = i % width;
  int y = i / width;

  int tx = x + dx;
  int ty = y + dy;
  if (tx < 0 || ty < 0 || tx >= width || ty >= length) return;
  int p = x + y * width;
  int tp = tx + ty * width;
  if (map[tp] == ' ' || map[tp] == '.') {
    map[tp] = (map[tp] == '.') ? 'P' : 'p';
    map[p] = (map[p] == 'p') ? ' ' : '.';
  } else if (map[tp] == 'o' || map[tp] == '0') {
    int tx2 = tx + dx;
    int ty2 = ty + dy;
    if (tx2 < 0 || ty2 < 0 || tx2 >= width || ty2 >= length) {
      return;
    }

    int tp2 = (ty + dy) * width + (tx + dx);
    if (map[tp2] == ' ' || map[tp2] == '.') {
      map[tp2] = (map[tp2] == '.') ? '0' : ' ';
      map[tp] = (map[tp] == '0') ? 'P' : 'p';
      map[p] = (map[p] == 'P') ? '.' : ' ';
    }
  }
}
bool GameSystem::CheckClear(const vector<char>& map, int length, int width) {
  for (int i = 0; i < width * length; ++i) {
    if (map[i] == 'o') {
      return false;
    }
  }
  return true;
}

void GameSystem::Draw(const vector<char>& map,int width) {
  int i = 0;
  for (auto brick : map) {
    cout << brick;
    ++i;
    if (i % width  == 0) cout << '\n';
  }
}
    


