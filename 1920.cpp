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

vector<int> ns(100000, INT_MAX);
vector<int> ms(100000);

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &ns[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &ms[i]);
  }

  sort(ns.begin(), ns.end());

  for (int i = 0; i < m; i++)
  {
    int st = 0;
    int en = n;
    int md;
    while (st < en)
    {
      md = (st + en) / 2;
      if (ns[md] >= ms[i])
      {
        en = md;
      }
      else
      {
        st = md + 1;
      }
    }
    md = (st + en) / 2;

    if (en == n || ns[md] != ms[i])
    {
      printf("0\n");
    }
    else
    {
      printf("1\n");
    }
  }
}
