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

vector<int> orig(1000001);
vector<int> seq(1000001, INT_MAX);

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &seq[i]);
    orig[i] = seq[i];
  }
  sort(seq.begin(), seq.end());
  auto itr = unique(seq.begin(), seq.end());
  for (int i = 0; i < n; i++)
  {
    int st = 0;
    int en = itr - seq.begin() - 1;
    int md;
    while (st < en)
    {
      md = (st + en) / 2;
      if (seq[md] >= orig[i])
      {
        en = md;
      }
      else
      {
        st = md + 1;
      }
    }
    printf("%d ", st);
  }
}