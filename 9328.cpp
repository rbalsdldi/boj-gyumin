#include <algorithm>
#include <bitset>
#include <complex>
#include <climits>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;


int t, h, w;

vector<vector<vector<char>>> board;
vector<vector<vector<int>>> vis;

deque<pair<int, int>> q;

vector<set<char>> keys;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool oob(vector<vector<char>> &board, int r, int c)
{
  if (board.size() > r && r >= 0 && board[0].size() > c && c >= 0)
  {
    return false;
  }
  return true;
}

int collect_keys(int c)
{
  int doc_cnt = 0;
  while (q.size() > 0)
  {
    int cr = q.front().first;
    int cc = q.front().second;
    if (isupper(board[c][cr][cc]))
    {
      return doc_cnt;
    }
    q.pop_front();
    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (oob(board[c], nr, nc) || board[c][nr][nc] == '*' || vis[c][nr][nc] == 1)
      {
        continue;
      }
      if (board[c][nr][nc] == '$')
      {
        doc_cnt++;
        q.push_front(make_pair(nr, nc));
        vis[c][nr][nc] = 1;
      }
      else if (board[c][nr][nc] == '.')
      {
        q.push_front(make_pair(nr, nc));
        vis[c][nr][nc] = 1;
      }
      else if (isupper(board[c][nr][nc]))
      {
        q.push_back(make_pair(nr, nc));
        vis[c][nr][nc] = 1;
      }
      else
      {
        keys[c].insert(board[c][nr][nc]);
        q.push_front(make_pair(nr, nc));
        vis[c][nr][nc] = 1;
      }
    }
  }
  return doc_cnt;
}

int unlock_doors(int c)
{
  deque<pair<int, int>> q_temp;
  int unlocked_cnt = 0;
  while (q.size() > 0)
  {
    int cr = q.front().first;
    int cc = q.front().second;
    q.pop_front();
    if (keys[c].find(tolower(board[c][cr][cc])) != keys[c].end())
    {
      board[c][cr][cc] = '.';
      unlocked_cnt++;
      q_temp.push_front(make_pair(cr, cc));
    }
    else
    {
      q_temp.push_back(make_pair(cr, cc));
    }
  }
  q = q_temp;
  return unlocked_cnt;
}

void solution()
{
  for (int i = 0; i < t; i++)
  {
    bool is_done = false;
    int result = 0;
    for (int j = 0; j < board[i].size(); j++)
    {
      for (int k = 0; k < board[i][0].size(); k++)
      {
        if (j == 0 || j == board[i].size() - 1 || k == 0 || k == board[i][0].size() - 1)
        {
          if (board[i][j][k] == '*')
          {
            continue;
          }
          if (board[i][j][k] == '.')
          {
            q.push_front(make_pair(j, k));
          }
          else if (islower(board[i][j][k]))
          {
            keys[i].insert(board[i][j][k]);
            q.push_front(make_pair(j, k));
          }
          else if (isupper(board[i][j][k]))
          {
            q.push_back(make_pair(j, k));
          }
          else if (board[i][j][k] == '$')
          {
            result += 1;
            q.push_front(make_pair(j, k));
          }
          vis[i][j][k] = 1;
        }
      }
    }
    while (!is_done)
    {
      result += collect_keys(i);
      if (unlock_doors(i) == 0)
      {
        is_done = true;
      };
    }
    cout << result << endl;
    q.clear();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> h >> w;
    vector<vector<char>> board_temp;
    vector<vector<int>> vis_temp;
    for (int j = 0; j < h; j++)
    {
      string temp;
      cin >> temp;
      vector<char> row_temp(temp.begin(), temp.end());
      board_temp.push_back(row_temp);
      vector<int> vis_row_temp(w, 0);
      vis_temp.push_back(vis_row_temp);
    }
    board.push_back(board_temp);
    vis.push_back(vis_temp);

    string temp;
    cin >> temp;
    if (temp == "0")
    {
      set<char> key_temp;
      keys.push_back(key_temp);
    }
    else
    {
      set<char> key_temp(temp.begin(), temp.end());
      keys.push_back(key_temp);
    }
  }

  solution();
}
