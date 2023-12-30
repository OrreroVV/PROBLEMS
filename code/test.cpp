#include <iostream>
#include <cstdio>
using namespace std;
bool isSxh(int k){
    int a,b,c;
    a=k/100;
    b=(k/10)%10;
    c=(k%10)%10;
    int sum=a*a*a+b*b*b+c*c*c;
    if(sum==k){
        return true;
    }
    else return false;
}

int main() {
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF) {
        int i = m;
        bool shuchu = false;
        for (i; i <= n; ++i) {
            if (isSxh(i)) {
                cout << i << " ";
                shuchu = true;
            }
        }
        if (shuchu) printf("\b");
        else cout << "no";
        cout<<endl;
    }
    printf("\b");
}