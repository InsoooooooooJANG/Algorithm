#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct st{
	int num;
	char name[11];
};
int isExist(struct st arr[], int num, int cnt)
{
	for(int i = 0; i<cnt; i++)
	{
		if(arr[i].num == num)
		{
			return i;
		}
	}
	return cnt;
}
bool cmp(const struct st &p1, const struct st &p2){
    if(p1.num < p2.num){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
	int cnt,delIdx=-1, inputIdx=0;
	struct st arr[20000];
	scanf("%d", &cnt);
	for(int i =0; i<cnt; i++)
	{
		char code;
		int num;
		char name[11];
		scanf(" %c", &code);
		scanf("%d", &num);
		scanf("%s",name);
		if(code=='I')
		{
			int idx = isExist(arr, num, cnt);
			if(idx ==cnt)
			{
				arr[inputIdx].num = num;
				strcpy(arr[inputIdx].name, name);
			}
			else
			{
				for(int j = cnt-1; j > idx ; j--)
				{
					arr[j].num = arr[j-1].num;
					strcpy(arr[j].name, arr[j-1].name);
				}
				arr[idx].num = num;
				strcpy(arr[idx].name, name);
			}
			inputIdx++;
		}
		else
		{
			int idx = isExist(arr, num, cnt);
			if(idx!=cnt) 
			{
				if(inputIdx==1)
				{
					arr[idx].num = 0;
					strcpy(arr[idx].name,"");
				}
				for(int j =idx; j<inputIdx-1; j++)
				{
					arr[j].num = arr[j+1].num;
					strcpy(arr[j].name, arr[j+1].name);
				}
				inputIdx--;
				
			}
		}			
	}
	
	int printIdx[5];
	scanf("%d%d%d%d%d",&printIdx[0],&printIdx[1],&printIdx[2],&printIdx[3],&printIdx[4]);
	
	sort(arr, arr+inputIdx, cmp);
	
	for(int i=0; i<5; i++)
	{
		printf("%d %s\n", arr[printIdx[i]-1].num, arr[printIdx[i]-1].name);
	}
}