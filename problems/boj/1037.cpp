#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int A[51];
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",A+i);
    sort(A,A+n);
    printf("%d\n",A[0]*A[n-1]);

    return 0;
}
