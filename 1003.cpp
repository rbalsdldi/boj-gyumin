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

int t;
vector<int> ns;

vector<pair<int, int>> memo(41, {0, 0});

void dp(int n)
{
  if (memo[n] == make_pair(0, 0))
  {
    dp(n - 1);
    dp(n - 2);
    memo[n] = {memo[n - 1].first + memo[n - 2].first, memo[n - 1].second + memo[n - 2].second};
  }
}

int main()
{
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int temp;
    cin >> temp;
    ns.push_back(temp);
  }

  memo[0] = {1, 0};
  memo[1] = {0, 1};

  for (auto i : ns)
  {
    dp(i);
    cout << memo[i].first << ' ' << memo[i].second << endl;
  }
}