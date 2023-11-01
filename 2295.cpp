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

vector<int> seq(1000, INT_MAX);
vector<int> ms;

int result = 0;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> seq[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      ms.push_back(seq[i] + seq[j]);
    }
  }

  sort(ms.begin(), ms.end());
  sort(seq.begin(), seq.end());

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (binary_search(ms.begin(), ms.end(), seq[i] - seq[j]))
      {
        result = max(result, seq[i]);
      }
    }
  }

  cout << result << endl;
}
