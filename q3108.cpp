#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct st{
	int num;
	char name[10];
};
int isExist(struct st arr[], int num)
{
	for(int i = 0; i<100; i++)
	{
		if(arr[i].num == num)
		{
			return i;
		}
	}
	return 0;
}
bool cmp(const struct st &p1, const struct st &p2){
    if(p1.num > p2.num){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
	int cnt,delIdx=0, inputIdx=0;
	struct st arr[100];
	scanf("%d", &cnt);
	for(int i =0; i<cnt; i++)
	{
		char code;
		int num;
		char name[10];
		scanf("%c%d%s", &code, &num, name);
		if(code=='I')
		{
			if(isExist(arr, num)==0)
			{
				if(delIdx != 0)
				{
					arr[delIdx].num = num;
					strcpy(arr[delIdx].name, name);
					delIdx =0;
					inputIdx++;
					
				}
				else
				{
					arr[inputIdx].num = num;
					strcpy(arr[inputIdx].name, name);
					inputIdx++;
					
				}
			}
		}
		else
		{
			int idx = isExist(arr, num);
			if(idx!=0) 
			{
				delIdx =idx;
				inputIdx--;
				
			}
		}			
	}
	
	int printIdx[5];
	scanf("%d%d%d%d%d",&printIdx[0],&printIdx[1],&printIdx[2],&printIdx[3],&printIdx[4]);
	
	sort(arr, arr+inputIdx, cmp);
	
	for(int i=0; i<5; i++)
	{
		printf("%d %s\n", arr[printIdx[i]].num, arr[printIdx[i]].name);
	}
}