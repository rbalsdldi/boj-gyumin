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

int n, m;

vector<string> board(1000);

vector<vector<int>> memo(1000, vector<int>(1000, -1));

int cnt = 0;

int dp(int r, int c)
{
  if (memo[r][c] != -1)
  {
    return memo[r][c];
  }
  memo[r][c] = min({dp(r, c + 1), dp(r + 1, c), dp(r + 1, c + 1)}) + 1;
  if (board[r][c] == '0')
  {
    memo[r][c] = 0;
  }
  cnt = max(cnt, memo[r][c]);
  return memo[r][c];
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> board[i];
  }

  for (int i = 0; i < n; i++)
  {
    memo[i][m - 1] = board[i][m - 1] - '0';
    cnt = max(cnt, memo[i][m - 1]);
  }

  for (int i = 0; i < m; i++)
  {
    memo[n - 1][i] = board[n - 1][i] - '0';
    cnt = max(cnt, memo[n - 1][i]);
  }

  dp(0, 0);

  cout << cnt * cnt << endl;
}