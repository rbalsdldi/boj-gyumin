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

vector<vector<int>> sets;

deque<int> q;

void backtracking(int c, int last)
{
  if (q.size() == 6)
  {
    for (auto i : q)
    {
      cout << i << ' ';
    }
    cout << endl;
    return;
  }
  for (int i = last + 1; i < sets[c].size(); i++)
  {
    q.push_back(sets[c][i]);
    backtracking(c, i);
    q.pop_back();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  while (true)
  {
    cin >> k;
    if (k == 0)
    {
      break;
    }
    vector<int> set_temp;
    for (int i = 0; i < k; i++)
    {
      int temp;
      cin >> temp;
      set_temp.push_back(temp);
    }
    sets.push_back(set_temp);
  }

  for (int i = 0; i < sets.size(); i++)
  {
    backtracking(i, -1);
    cout << endl;
  }
}
