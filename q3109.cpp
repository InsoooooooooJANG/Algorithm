#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
struct st{
	int num;
	char name[11];
};
int isExist(vector<struct st> &arr, int num, int cnt)
{
	struct st tmp;
	for(int i = 0; i<cnt; i++)
	{
		tmp = arr[i];
		if(tmp.num == num)
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
	int cnt;
	scanf("%d", &cnt);
	
	vector<struct st> arr;
	
	for(int i =0; i<cnt; i++)
	{
		char code;
		struct st tmp;
		vector<struct st>::iterator iter = arr.begin();
		scanf(" %c", &code);
		scanf("%d", &tmp.num);
		scanf("%s",tmp.name);
		
		if(code=='I')
		{
			int idx = isExist(arr, tmp.num, arr.size());
			
			if(idx ==arr.size())
			{
				arr.push_back(tmp);
			}
			else
			{
				arr.insert(iter+idx, tmp);
			}
		}
		else
		{
			int idx = isExist(arr, tmp.num, arr.size());
			if(idx!=arr.size()) 
			{
				iter += (idx);
				arr.erase(iter);
			}
		}	
	}
	
  sort(arr.begin(), arr.end(), cmp);
	
	int printIdx[5];
	scanf("%d%d%d%d%d",&printIdx[0],&printIdx[1],&printIdx[2],&printIdx[3],&printIdx[4]);
	
	for(int i=0; i<5; i++)
	{
		struct st tmp;
		tmp = arr[printIdx[i]-1];
		printf("%d %s\n", tmp.num, tmp.name);
	}
}
