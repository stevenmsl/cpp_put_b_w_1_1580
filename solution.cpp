#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace sol1580;
using namespace std;

/* takeaways
   - check the takeaways in q1564 first
   - don't be confused that the boxes
     can enter the room either from
     the left or the right
   - from a room perspective the best it
     can do is to allow a box to enter
     through the less restrictive path
     if the box can fit. left or right
     doesn't matter
   - we start trying filling up the
     most restrictive room first with
     the shortest box as this is the
     farthest you can reach from
     either sides
   - This is different from q1564 where
     the box needs  pass through the
     most restrictive room to get to
     the right most room first.
*/

int Solution::maxBoxes(vector<int> &boxes, vector<int> &ws)
{
  const int n = boxes.size();
  const int m = ws.size();

  auto left = vector<int>(ws.size(), 0);
  /*
    - set the left gate from left
      to right
    - set the gate for those who
      come after me (on the right)
  */
  int gate = ws[0];
  for (auto i = 0; i < m; i++)
    left[i] = min(gate, ws[i]);

  /*
     - set the right gate from right to left
       and combine with the left gate at the
       same time

  */
  gate = ws[m - 1];
  for (int i = m - 1; i >= 0; i--)
    /*
      - pick the taller one as we want
        the room to accomodate a taller
        box entering from the left or
        right
    */
    ws[i] = max(left[i], min(gate, ws[i]));

  /*
    - we are allowing boxes to coming
      in from either left or right
    - which direction taken is not
      important as long as the box
      can reach the room
    - start with the shortest room
      and box first
    - soring the room ascendingly by 
      effective height already covers 
      the scenarios a box trying to
      come in from left or right.
      Don't overthink this
  */
  sort(ws.begin(), ws.end());
  sort(boxes.begin(), boxes.end());

  auto b = 0;
  int w = 0;
  auto count = 0;
  while (b < n && w < m)
  {
    if (boxes[b] <= ws[w])
    {
      count += 1;
      b++; // next taller box
    }
    w++; // next taller room
  }

  return count;
}