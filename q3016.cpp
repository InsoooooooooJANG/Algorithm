#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    char name[10];
    int score1;
	int score2;
	int score3;
};
bool cmp(const struct node &p1, const struct node &p2){
    if(p1.score1 > p2.score1){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int cnt, rank2 = 0, rank3 = 0;
	char name[10];
    scanf("%d", &cnt);
    struct node *arr = (struct node*)malloc(sizeof(struct node) * cnt);
    for(int i = 0 ;i < cnt; i++)
    {
        scanf("%s%d%d%d", arr[i].name, &arr[i].score1, &arr[i].score2, &arr[i].score3);
    }
    sort(arr, arr+cnt, cmp);
	strcpy(name, arr[0].name);
	
	for(int i = 1; i < cnt; i++)
	{
		if(arr[0].score2 < arr[i].score2)
		{
			rank2++;
		}
		if(arr[0].score3 < arr[i].score3)
		{
			rank3++;
		}
	}
	
	printf("%s %d %d\n", name, ++rank2, ++rank3);
	
}