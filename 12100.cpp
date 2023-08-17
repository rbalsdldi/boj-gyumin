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
vector<vector<int>> board;

deque<int> temp;

enum Dir
{
  UP = 0,
  DOWN = 1,
  RIGHT = 2,
  LEFT = 3
};

void slide(Dir d, vector<vector<int>> &board)
{
  if (d == UP)
  {
    for (int c = 0; c < n; c++)
    {
      for (int r = 0; r < n; r++)
      {
        if (board[r][c] == 0)
        {
          continue;
        }
        temp.push_back(board[r][c]);
        board[r][c] = 0;
      }
      for (int r = 0; r < n; r++)
      {
        if (temp.size() == 0)
        {
          break;
        }
        board[r][c] = temp.front();
        temp.pop_front();
      }
    }
  }
  else if (d == DOWN)
  {
    for (int c = 0; c < n; c++)
    {
      for (int r = n - 1; r >= 0; r--)
      {
        if (board[r][c] == 0)
        {
          continue;
        }
        temp.push_back(board[r][c]);
        board[r][c] = 0;
      }
      for (int r = n - 1; r >= 0; r--)
      {
        if (temp.size() == 0)
        {
          break;
        }
        board[r][c] = temp.front();
        temp.pop_front();
      }
    }
  }
  else if (d == RIGHT)
  {
    for (int r = 0; r < n; r++)
    {
      for (int c = n - 1; c >= 0; c--)
      {
        if (board[r][c] == 0)
        {
          continue;
        }
        temp.push_back(board[r][c]);
        board[r][c] = 0;
      }
      for (int c = n - 1; c >= 0; c--)
      {
        if (temp.size() == 0)
        {
          break;
        }
        board[r][c] = temp.front();
        temp.pop_front();
      }
    }
  }
  else if (d == LEFT)
  {
    for (int r = 0; r < n; r++)
    {
      for (int c = 0; c < n; c++)
      {
        if (board[r][c] == 0)
        {
          continue;
        }
        temp.push_back(board[r][c]);
        board[r][c] = 0;
      }
      for (int c = 0; c < n; c++)
      {
        if (temp.size() == 0)
        {
          break;
        }
        board[r][c] = temp.front();
        temp.pop_front();
      }
    }
  }
}

void merge(Dir d, vector<vector<int>> &board)
{
  if (d == UP)
  {
    for (int c = 0; c < n; c++)
    {
      int last_i = -1;
      for (int r = 0; r < n; r++)
      {
        if (board[r][c] == 0)
        {
          continue;
        }
        if (last_i == -1)
        {
          last_i = r;
          continue;
        }
        if (board[last_i][c] == board[r][c])
        {
          board[last_i][c] *= 2;
          board[r][c] = 0;
          last_i = -1;
          continue;
        }

        last_i = r;
      }
    }
  }
  else if (d == DOWN)
  {
    for (int c = 0; c < n; c++)
    {
      int last_i = -1;
      for (int r = n - 1; r >= 0; r--)
      {
        if (board[r][c] == 0)
        {
          continue;
        }
        if (last_i == -1)
        {
          last_i = r;
          continue;
        }
        if (board[last_i][c] == board[r][c])
        {
          board[last_i][c] *= 2;
          board[r][c] = 0;
          last_i = -1;
          continue;
        }

        last_i = r;
      }
    }
  }
  else if (d == RIGHT)
  {
    for (int r = 0; r < n; r++)
    {
      int last_i = -1;
      for (int c = n - 1; c >= 0; c--)
      {
        if (board[r][c] == 0)
        {
          continue;
        }
        if (last_i == -1)
        {
          last_i = c;
          continue;
        }
        if (board[r][last_i] == board[r][c])
        {
          board[r][last_i] *= 2;
          board[r][c] = 0;
          last_i = -1;
          continue;
        }

        last_i = c;
      }
    }
  }
  else if (d == LEFT)
  {
    for (int r = 0; r < n; r++)
    {
      int last_i = -1;
      for (int c = 0; c < n; c++)
      {
        if (board[r][c] == 0)
        {
          continue;
        }
        if (last_i == -1)
        {
          last_i = c;
          continue;
        }
        if (board[r][last_i] == board[r][c])
        {
          board[r][last_i] *= 2;
          board[r][c] = 0;
          last_i = -1;
          continue;
        }

        last_i = c;
      }
    }
  }
}

deque<Dir> q_q;
int max_block = 0;
void search(deque<Dir> queue, vector<vector<int>> &cp)
{
  if (queue.size() == 5)
  {
    for (auto i : queue)
    {
      merge(i, cp);
      slide(i, cp);
    }

    for (auto i : cp)
    {
      for (auto j : i)
      {
        if (max_block < j)
        {
          max_block = j;
        }
      }
    }

    cp = board;
    return;
  }

  for (int d = 0; d < 4; d++)
  {
    queue.push_back(static_cast<Dir>(d));
    search(queue, cp);
    queue.pop_back();
  }
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    vector<int> row_temp;
    for (int j = 0; j < n; j++)
    {
      int temp = 0;
      cin >> temp;
      row_temp.push_back(temp);
    }
    board.push_back(row_temp);
  }

  vector<vector<int>> cp = board;

  search(q_q, cp);

  cout << max_block;
}