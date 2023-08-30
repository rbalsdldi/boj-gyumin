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

vector<vector<int>> tri;

vector<vector<int>> memo;

int dp(int r, int c)
{
  if (memo[r][c] == -1)
  {
    memo[r][c] = max({dp(r + 1, c), dp(r + 1, c + 1)}) + tri[r][c];
  }
  return memo[r][c];
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    vector<int> row_temp;
    for (int j = 0; j < i + 1; j++)
    {
      int temp;
      cin >> temp;
      row_temp.push_back(temp);
    }
    tri.push_back(row_temp);
    vector<int> memo_row_temp(n, -1);
    memo.push_back(memo_row_temp);
  }

  for (int i = 0; i < n; i++)
  {
    memo[n - 1][i] = tri[n - 1][i];
  }

  cout << dp(0, 0) << endl;
}