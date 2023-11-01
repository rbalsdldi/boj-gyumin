#include <algorithm>
#include <bitset>
#include <climits>
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

int m, n;

vector<vector<int>> board(500, vector<int>(500));

vector<vector<int>> memo(500, vector<int>(500, -1));

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool oob(int r, int c)
{
  if (m > r && r >= 0 && n > c && c >= 0)
  {
    return false;
  }
  return true;
}

int dp(int r, int c)
{
  if (memo[r][c] != -1)
    return memo[r][c];
  int temp = 0;
  for (int i = 0; i < 4; i++)
  {
    int nr = r + dr[i], nc = c + dc[i];
    if (oob(nr, nc) || board[nr][nc] >= board[r][c])
      continue;
    temp += dp(nr, nc);
  }
  memo[r][c] = temp;
  return memo[r][c];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }

  memo[m - 1][n - 1] = 1;

  cout << dp(0, 0) << endl;
}