#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


char S[1000001];
char T[1000001];

int len_s, len_t;

int cnt[30];



int ans = 0;
void find(int p)
{
    //x from T, p from S

    int j=1;
    for(int i=p;i<len_s;i++)
    {
        if(T[j] == S[i])
        {
            j++;
            S[i] = '\n';
            if(j==len_t)
            {
                ans++;
                return;
            }
        }
        else if(T[0] == S[i])
        {
            S[i] = '\n';
            find(i+1);
        }
    }
}

int idx[1000001];

int main()
{




    scanf("%s",S);
    scanf("%s",T);

    len_s=  strlen(S);
    len_t = strlen(T);

    int i, j;
    for(i=0;i<len_t;i++) cnt[i] = 0;

    for(i=0;i<len_s;i++)
    {
        idx[i] = -1;
        for(j=0;j<len_t;j++)
        {
            if(S[i] == T[j])
            {
                idx[i] = j;
                break;
            }
        }
    }

    for(i=0;i<len_s;i++)
    {
        if(idx[i] == 0) cnt[0]++;
        else if(cnt[idx[i]] < cnt[idx[i]-1]) cnt[idx[i]] ++;
    }


    printf("%d",cnt[len_t -1 ]);
    return 0;
}
