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

int n;

vector<vector<bool>> board;
vector<bool> diag;

int max_cnt = 0;
void backtrack(int depth, int cnt, vector<bool> d)
{
  if (depth >= 2 * n - 1)
  {
    max_cnt = max(max_cnt, cnt);
    return;
  }
  bool is_full = true;
  for (int i = 0; i < abs(n - abs(n - 1 - depth)); i++)
  {
    int idx = 2 * i + abs(n - depth - 1);
    int r = min(depth, n - 1) - i;
    int c = depth - r;
    if (board[r][c] == false || d[idx] == true)
    {
      continue;
    }
    vector<bool> dc = d;
    dc[idx] = true;
    backtrack(depth + 2, cnt + 1, dc);
    is_full = false;
  }
  if (is_full)
  {
    backtrack(depth + 2, cnt, d);
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    vector<bool> row_temp;
    for (int j = 0; j < n; j++)
    {
      bool temp;
      cin >> temp;
      row_temp.push_back(temp);
    }
    board.push_back(row_temp);
  }

  vector<bool> d_temp(2 * n - 1, false);
  diag = d_temp;

  backtrack(0, 0, diag);
  int temp = max_cnt;
  max_cnt = 0;
  backtrack(1, 0, diag);
  temp += max_cnt;
  cout << temp << endl;
}