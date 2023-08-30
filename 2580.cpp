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

// bitmasking
// 9, 8, ..., 2, 1
vector<int> r_check(9, 0);
vector<int> c_check(9, 0);
vector<int> s_check(9, 0);

vector<vector<int>> board;

int blank_cnt = 0;
bool is_complete = false;

bool check_cell(int n, int r, int c)
{
  if ((r_check[r] & (1 << n)) ||
      (c_check[c] & (1 << n)) ||
      (s_check[(r / 3) * 3 + (c / 3)] & (1 << n)))
  {
    return false;
  }
  return true;
}

void backtrack(int r, int c, int cnt)
{
  if (is_complete)
  {
    return;
  }
  if (cnt == blank_cnt)
  {
    for (auto i : board)
    {
      for (auto j : i)
      {
        cout << j << ' ';
      }
      cout << endl;
    }
    is_complete = true;
    return;
  }
  int nr = r, nc = c + 1;
  if (nc == 9)
  {
    nr++;
    nc = 0;
  }
  if (board[r][c] != 0)
  {
    backtrack(nr, nc, cnt);
    return;
  }
  for (int i = 1; i < 10; i++)
  {
    if (check_cell(i, r, c))
    {
      r_check[r] |= 1 << i;
      c_check[c] |= 1 << i;
      s_check[(r / 3) * 3 + (c / 3)] |= 1 << i;
      board[r][c] = i;
      backtrack(nr, nc, cnt + 1);
      r_check[r] &= ~(1 << i);
      c_check[c] &= ~(1 << i);
      s_check[(r / 3) * 3 + (c / 3)] &= ~(1 << i);
      board[r][c] = 0;
    }
  }
}

int main()
{
  for (int i = 0; i < 9; i++)
  {
    vector<int> row_temp;
    for (int j = 0; j < 9; j++)
    {
      int temp;
      cin >> temp;
      row_temp.push_back(temp);
      if (temp == 0)
      {
        blank_cnt++;
        continue;
      }
      r_check[i] |= 1 << temp;
      c_check[j] |= 1 << temp;
      s_check[(i / 3) * 3 + (j / 3)] |= 1 << temp;
    }
    board.push_back(row_temp);
  }

  backtrack(0, 0, 0);
}