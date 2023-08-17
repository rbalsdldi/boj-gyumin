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
vector<int> memo;

int dp(int num)
{
  if (memo[num] != -1)
  {
    cout << "used memo: " << num << endl;
    return memo[num];
  }
    cout << "not used memo: " << num << endl;
  vector<int> list;
  if (num % 3 == 0)
  {
    list.push_back(dp(num / 3));
  }
  if (num % 2 == 0)
  {
    list.push_back(dp(num / 2));
  }
  list.push_back(dp(num - 1));
  memo[num] = *min_element(list.begin(), list.end()) + 1;
  return memo[num];
}

int main()
{
  cin >> n;
  for (int i = 0; i < n+1; i++)
  {
    memo.push_back(-1);
  }

  memo[1] = 0;

  cout << dp(n) << endl;
  for (auto i : memo)
  {
    cout << i << ' ';
  }
  cout << endl;
}