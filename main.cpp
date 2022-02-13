#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1580;

string toString(vector<string> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += e;
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

/*
Input: boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
Output: 4
*/
tuple<vector<int>, vector<int>, int> testFixture1()
{
  return make_tuple(vector<int>{1, 2, 2, 3, 4},
                    vector<int>{3, 4, 1, 2},
                    4);
}

/*
Input: boxes = [3,5,5,2], warehouse = [2,1,3,4,5]
Output: 3
*/
tuple<vector<int>, vector<int>, int> testFixture2()
{
  return make_tuple(vector<int>{3, 5, 5, 2},
                    vector<int>{2, 1, 3, 4, 5},
                    3);
}

/*
Input: boxes = [1,2,3], warehouse = [1,2,3,4]
Output: 3
*/
tuple<vector<int>, vector<int>, int> testFixture3()
{
  return make_tuple(vector<int>{1, 2, 3},
                    vector<int>{1, 2, 3, 4},
                    3);
}

/*
Input: boxes = [4,5,6], warehouse = [3,3,3,3,3]
Output: 0
*/
tuple<vector<int>, vector<int>, int> testFixture4()
{
  return make_tuple(vector<int>{4, 5, 6},
                    vector<int>{3, 3, 3, 3, 3},
                    0);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  auto result = sol.maxBoxes(get<0>(f), get<1>(f));
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  auto result = sol.maxBoxes(get<0>(f), get<1>(f));
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(result) << endl;
}
void test3()
{
  auto f = testFixture3();
  Solution sol;
  auto result = sol.maxBoxes(get<0>(f), get<1>(f));
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(result) << endl;
}
void test4()
{
  auto f = testFixture4();
  Solution sol;
  auto result = sol.maxBoxes(get<0>(f), get<1>(f));
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}