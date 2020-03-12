#include <iostream>
#include <cstring>
using namespace std;
struct node
{
    char name[10];
    int score;
    struct node *next;
};

int main()
{
    char rank[100][10]={0,};
    int cnt,printCnt, idx =0, j=0;
    struct node *header = 0;
    struct node *ptr = 0;
    cin >> cnt >> printCnt;
    for(int i =0 ; i < cnt; i++)
    {
        struct node new;
        cin>>new.name>>new.score;
        
        if(header==0)
        {
            header = &new;
        }
        else
        {
            ptr = header;
            
            while(ptr->next != 0)
            {
                if(ptr->score > new.score)
                {
                    
                }
            }
        }
    }
}