#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    char name[10];
    int score;
};
bool cmp(const struct node &p1, const struct node &p2){
    if(p1.score > p2.score){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int cnt, printCnt, i =0;
    scanf("%d%d", &cnt, &printCnt);
    struct node *arr = (struct node*)malloc(sizeof(struct node) * cnt);
    while(i<cnt)
    {
        scanf("%s%d", arr[i].name, &arr[i].score);
        i++;
    }
    i=0;
    stable_sort(arr, arr+cnt, cmp);

    while(i<printCnt)
    {
        printf("%s ", arr[i].name);
        i++;
    }
}