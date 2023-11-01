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

int n, k;
vector<long long int> seq(10000, LONG_MAX);

int result = 0;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> k >> n;
  for (int i = 0; i < k; i++)
  {
    cin >> seq[i];
  }

  long long int st = 0;
  long long int en = LONG_MAX;
  long long int md;
  long long int temp = 0;
  while (st < en)
  {
    md = (st + en) / 2;
    for (int i = 0; i < k; i++)
    {
      temp += seq[i] / md;
    }
    if (temp < n)
    {
      en = md;
    }
    else
    {
      st = md + 1;
    }
    temp = 0;
  }
  cout << st - 1 << endl;
}
