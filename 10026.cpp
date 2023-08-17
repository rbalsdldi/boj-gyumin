#include <algorithm>
#include <bitset>
#include <complex>
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

int n;

// (not blind, blind)
pair<vector<vector<char>>, vector<vector<char>>> board;
pair<vector<vector<char>>, vector<vector<char>>> vis;

deque<pair<int, int>> q;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

void bfs(bool is_blind)
{
  int cur_r, cur_c;
  while (q.size() > 0)
  {
    tie(cur_r, cur_c) = q.front();
    q.pop_front();
    int next_r, next_c;
    for (int i = 0; i < 4; i++)
    {
      next_r = cur_r + dr[i];
      next_c = cur_c + dc[i];
      if (board.first.size() > next_r && next_r >= 0 && board.first[0].size() > next_c && next_c >= 0)
      {
        if (is_blind)
        {
          if (vis.second[next_r][next_c] == 'X')
          {
            continue;
          }
          if (board.second[cur_r][cur_c] == 'R' || board.second[cur_r][cur_c] == 'G')
          {
            if (board.second[next_r][next_c] == 'R' || board.second[next_r][next_c] == 'G')
            {
              q.push_back(make_pair(next_r, next_c));
              vis.second[next_r][next_c] = 'X';
            }
          }
          else
          {
            if (board.second[next_r][next_c] == 'B')
            {
              q.push_back(make_pair(next_r, next_c));
              vis.second[next_r][next_c] = 'X';
            }
          }
        }
        else
        {
          if (vis.first[next_r][next_c] == 'X')
          {
            continue;
          }
          if (board.first[cur_r][cur_c] == board.first[next_r][next_c])
          {
            q.push_back(make_pair(next_r, next_c));
            vis.first[next_r][next_c] = 'X';
          }
        }
      }
    }
  }
}

void solve()
{
  int not_blind_cnt = 0, blind_cnt = 0;

  // for not blind
  for (int i = 0; i < board.first.size(); i++)
  {
    for (int j = 0; j < board.first[0].size(); j++)
    {
      if (vis.first[i][j] != 'X')
      {
        not_blind_cnt++;
        vis.first[i][j] = 'X';
        q.push_back(make_pair(i, j));
        bfs(false);
      }
    }
  }

  // for blind
  for (int i = 0; i < board.first.size(); i++)
  {
    for (int j = 0; j < board.first[0].size(); j++)
    {
      if (vis.second[i][j] != 'X')
      {
        blind_cnt++;
        vis.second[i][j] = 'X';
        q.push_back(make_pair(i, j));
        bfs(true);
      }
    }
  }

  cout << not_blind_cnt << ' ' << blind_cnt << endl;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string temp;
    cin >> temp;
    vector<char> r_temp(temp.begin(), temp.end());

    board.first.push_back(r_temp);
    board.second.push_back(r_temp);
  }
  vis = board;

  solve();
}