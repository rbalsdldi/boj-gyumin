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
vector<int> cases;

vector<int> memo(11, 0);

int dp(int num)
{
  if (memo[num] != 0)
  {
    return memo[num];
  }
  memo[num] = dp(num - 1) + dp(num - 2) + dp(num - 3);
  return memo[num];
}

int main()
{
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int temp;
    cin >> temp;
    cases.push_back(temp);
  }

  memo[1] = 1;
  memo[2] = 2;
  memo[3] = 4;

  for (auto i : cases)
  {
    cout << dp(i) << endl;
  }
}