
#include <set>
int solution(string &R) {
    // write your code in C++14 (g++ 6.2.0)
  int N = R.size();

  if(N == 1)
  {
      if(R[0] == 'S')
        return 30;
      else
        return 5;
  }
  int S[N];
  int A[N];
  int acnt = 0;
  int scnt =0;
  A[0] = 0;
  S[0] = 0;
  for (auto j = N-1; j > 0; --j )
  {
      if(R[j] == 'S')
      {
          S[j]= scnt + 1;
          scnt +=1;
          A[j] = acnt;
      }
      else {
          S[j] = scnt;
          A[j] = acnt + 1;
          ++acnt;
      } 
  }


  int cf =0;
  int cs =0;
  set<int> C;
  set<int> mC;
  for(auto i=0; i < N-1; ++i)
  {
      if(R[i] == 'S')
      {
          cs += 40;
          cf += 30;
      }
      else {
          cs += 5;
          cf += 20;
      }
      int crS = A[i+1] * 5 + S[i+1] * 40;
      int crF = A[i+1] * 20 + S[i+1] *  30;

     C.insert(cs + crS);
     C.insert(cf + crF);
     C.insert(cs + crF);
     if(!C.empty())
     {
         mC.insert(*C.begin());
     }
  }
  return *mC.begin();


}
