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

vector<int> tt(1001);
vector<vector<vector<long long int>>> memo(1001, vector<vector<long long int>>(3, vector<long long int>(31, -1)));

long long int dp(int t, int p, int w)
{
  if (memo[t][p][w] != -1)
    return memo[t][p][w];
  int temp;
  if (w == w_g)
  {
    temp = dp(t + 1, p, w);
  }
  else
  {
    temp = max(dp(t + 1, p, w), dp(t + 1, 3 - p, w + 1));
  }
  if (tt[t] == p)
  {
    temp++;
  }
  memo[t][p][w] = temp;
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
    if (tt[t] == 1)
    {
      memo[t][1][i] = 1;
      memo[t][2][i] = 0;
    }
    else
    {
      memo[t][1][i] = 0;
      memo[t][2][i] = 1;
    }
  }

  cout << max(dp(1, 1, 0), dp(1, 2, 1)) << endl;
}