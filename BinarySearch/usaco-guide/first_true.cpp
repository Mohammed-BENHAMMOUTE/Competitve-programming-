#include <bits/stdc++.h>
#include <functional>
using namespace std;

// return the minimum x such that f(x) = true, so we have [false , false , false , true , true , true]



int first_true(int l , int h , function<bool(int)> f)
{
  // if no position was found where f(x) = true, we want to return h + 1
  h++;
  while(l < h)
  {
    int mid = l + (h - l)/2;
    if(f(mid))
    {
      h = mid;
    }else{
      l = mid + 1;
    }
  }
  return l;
}





int main()
{

}
