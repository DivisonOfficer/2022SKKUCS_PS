#include <iostream>

using namespace std;


#define NodeMAX 10000
int node[51000000];
double floor[100000];

 int h;

int getHeight(long long a)
{
    long long y;

    for(i=1;i<=h;i++)
    {
        y = ((i + 1) * i) / 2;
        if(y < a) continue;
        return i;
    }
}
long long getPost(int a)
{
    return (a * (a+1))/2;
}
int main()
{

    cin >> h;

    int q, r;
    cin >>q >>r;

    long long cell = (h *(h+1)) / 2;
    int ceh = h >NodeMAX ? 5000*5001 : cell;

    int i;
    for(i=0;i<n;i++) node[i] = 0;

    for(i=0;i<h;i++) floor[i] = 0;

    for(i=0;i<q;i++)
    {
        long long a, b;
        cin >>a >>b;
        if(a>NodeMax)
        {
            int hh = getHeight(a);
            int toJ = (h-hh) + 2 + a - getPost(h-1));
            int fromJ = getPost(h-1);
            int wid = (h-hh) + 2;
            double two = 1;
            for(int j=0;j<hh+1;j++) two *= 2;
            double modi = 0;
            for(long long j = 0; j < wid ; j++)
            {
                if(j <= (wid-1) / 2)
                {
                    modi += 1 / two;
                    if(j < (wid-1) / 2)
                    two /= 2;
                    else if(wid%2 == 1) two*=2;
                }
                else{

                    modi -= 1/two;
                    two *= 2;
                }
                floor[fromJ + j] += modi * b;
            }
        }
        else{
            node[a] = b;
        }
    }


    for(i=0;)
    return 0;
}
