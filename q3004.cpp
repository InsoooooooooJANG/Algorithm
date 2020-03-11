#include <iostream>
#include <algorithm>
using namespace std;
typedef struct 
{
    int idx;
    int num;
    int sortedidx;
} ST;
bool cmp(const ST &p1, const ST &p2){
    if(p1.num < p2.num){
        return true;
    }
    else{
        return false;
    }
}
bool cmp2(const ST &p1, const ST &p2){
    if(p1.idx < p2.idx){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int cnt, i = 0;
    cin >> cnt;
    
    ST* arr = (ST*) malloc (sizeof(ST) * cnt);
    while(i<cnt){ arr[i].idx = i; cin >> arr[i].num; i++;}
    sort(arr, arr+cnt, cmp);
    i=0; 
    while(i<cnt){ arr[i].sortedidx = i; i++;}
    sort(arr, arr+cnt, cmp2);
    i=0;
    while(i<cnt){ cout << arr[i].sortedidx << ' '; i++;}
}