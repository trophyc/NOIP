#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
   int mx,n,ans=0;
   int a[30001];
   cin >> mx >> n;

   for(int i=1;i<=n;i++) {
      cin >> a[i];
   }

   sort(a+1, a+n+1);

   int l=1, r=n;
   while (l<=r) {
      if (a[l] + a[r] <= mx) {
         l++;
         r--;
      } else {
         r--;
      }
      ans++;
   }
   if (l == r) {
      ans++;
   }
   cout << ans;
   return 0;
}