#include <iostream>
using namespace std;

float rsum (float list [ ] ,int n)
 {
    
  count++ ;               // for if conditional
  if (n)
  count++ ;       // for return & rsum invocation
  return rsum (list,n-1) + list [n-1] ;
  }
   
