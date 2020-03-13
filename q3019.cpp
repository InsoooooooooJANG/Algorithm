#include <cstdio>
#include <cstring>
#include <algorithm>
struct st{
    char schedule[100];
    int year, mon, day;
};
bool cmp(const struct st &p1, const struct st &p2){
    if(p1.year < p2.year){
        return true;
    }
	else if(p1.year==p2.year){
		if(p1.mon < p2.mon) return true;
		else if(p1.mon == p2.mon){
			if(p1.day < p2.day) return true;
			else if(p1.day == p2.day){
				if(strcmp(p1.schedule, p2.schedule) < 0) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
    else{
        return false;
    }
}
int main()
{
    int cnt;
    struct st arr[100];
    scanf("%d", &cnt);
    
    for(int i  = 0 ; i < cnt; i++)
    {
        scanf("%s%d%d%d", arr[i].schedule, &arr[i].year, &arr[i].mon, &arr[i].day);
    }
	
	std::sort(arr, arr+cnt, cmp);
	
	for(int i  = 0 ; i < cnt; i++)
    {
        printf("%s\n", arr[i].schedule);
    }
}