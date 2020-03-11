#include <iostream>
#include <algorithm>

using namespace std;

typedef struct st{
    int id;
    int value;
}ST;

bool cmp(const ST &p1, const ST &p2){
    if(p1.id < p2.id){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int cnt = 0,idx = 0;
    cin >> cnt;
    
    ST *arr = (ST*)malloc(sizeof(ST) * cnt);
    
    while(idx < cnt){
        cin >> arr[idx].id;
        cin >> arr[idx].value;

        idx++;
    }
    
    sort(arr, arr+cnt, cmp);
    
    idx = 0;
    while(idx < cnt){
        cout << arr[idx].id << " " << arr[idx].value << endl;
        idx++;
    }
}