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

string a, b;

vector<vector<int>> memo(1000, vector<int>(1000, -1));

int dp(int i, int j)
{
  if (i == -1 || j == -1)
    return 0;
  if (memo[i][j] != -1)
    return memo[i][j];
  if (a[i] == b[j])
  {
    memo[i][j] = dp(i - 1, j - 1) + 1;
  }
  else
  {
    memo[i][j] = max(dp(i - 1, j), dp(i, j - 1));
  }
  return memo[i][j];
}

int main()
{
  cin >> a >> b;

  cout << dp(a.size() - 1, b.size() - 1) << endl;
}