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

int t;

// (board, vis)
vector<pair<vector<vector<int>>, vector<vector<int>>>> cases;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

deque<pair<int, int>> q;

void bfs(int case_idx)
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
      if (cases[case_idx].first.size() > next_r && next_r >= 0 && cases[case_idx].first[0].size() > next_c && next_c >= 0 && cases[case_idx].second[next_r][next_c] == 1)
      {
        q.push_back(make_pair(next_r, next_c));
        cases[case_idx].second[next_r][next_c] = 0;
      }
    }
  }
}

void solve()
{
  for (int i = 0; i < t; i++)
  {
    int cnt = 0;
    for (int j = 0; j < cases[i].first.size(); j++)
    {
      for (int k = 0; k < cases[i].first[0].size(); k++)
      {
        if (cases[i].second[j][k] == 1)
        {
          cnt++;
          q.push_back(make_pair(j, k));
          bfs(i);
        }
      }
    }
    cout << cnt << endl;
  }
}

int main()
{
  cin >> t;
  int m, n, k;
  for (int i = 0; i < t; i++)
  {
    pair<vector<vector<int>>, vector<vector<int>>> c_temp;
    cin >> m >> n >> k;
    vector<int> r_temp(m, 0);
    vector<vector<int>> b_temp(n, r_temp);
    c_temp.first = b_temp;

    int r, c;
    for (int j = 0; j < k; j++)
    {
      cin >> c >> r;
      c_temp.first[r][c] = 1;
    }
    c_temp.second = c_temp.first;
    cases.push_back(c_temp);
  }

  solve();
}