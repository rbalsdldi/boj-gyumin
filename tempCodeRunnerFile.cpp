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

int t, w_g;

vector<int> tt(1001, 0);
vector<vector<vector<long long int>>> memo(1001, vector<vector<long long int>>(3, vector<long long int>(31, -1)));

long long int dp(int t, int p, int w)
{
  if (memo[t][p][w] != -1)
    return memo[t][p][w];
  if (w == w_g)
  {
    if (tt[t] == p)
    {
      memo[t][p][w] = dp(t - 1, p, w) + 1;
    }
    else
    {
      memo[t][p][w] = dp(t - 1, p, w);
    }
  }
  else
  {
    if (tt[t] == p)
    {
      if (p == 1)
      {
        memo[t][p][w] = max(dp(t - 1, 1, w), dp(t - 1, 2, w + 1)) + 1;
      }
      else
      {
        memo[t][p][w] = max(dp(t - 1, 2, w), dp(t - 1, 1, w + 1)) + 1;
      }
    }
    else
    {
      if (p == 1)
      {
        memo[t][p][w] = max(dp(t - 1, 1, w), dp(t - 1, 2, w + 1));
      }
      else
      {
        memo[t][p][w] = max(dp(t - 1, 2, w), dp(t - 1, 1, w + 1));
      }
    }
  }
  return memo[t][p][w];
}

int main()
{
  cin >> t >> w_g;

  for (int i = 1; i < t + 1; i++)
  {
    cin >> tt[i];
  }

  for (int i = 0; i < w_g + 1; i++)
  {
    if (tt[1] == 1)
    {
      memo[1][1][i] = 1;
      memo[1][2][i] = 0;
    }
    else
    {
      memo[1][1][i] = 0;
      memo[1][2][i] = 1;
    }
  }

  cout << dp(t, 1, 0) << endl;
}

// T(t, p, w) = T(t-1, p, w) if w = 30
//              max(T(t-1, p, w), T(t-1, (p+1)%2, w+1)) if w < 30