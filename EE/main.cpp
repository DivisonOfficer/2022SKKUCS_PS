#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct Inputs{

    long long from;
    double n;
};


int getHeight(long long a)
{
    long long t=1;
    int h = 1;
    while(t<a)
    {

        h++;
        t = (h *(h+1))/2;
    }
    return h;
}
Inputs inputs[100000];

double floor[100001];
double oldFloor[100001];

void floorReplace(int n)
{
    for(int i=0;i<n +2;i++)
    {
      //  cout << floor[i] << " ";
        oldFloor[i] = floor[i];
        floor[i] = 0;
    }
   // cout <<endl;
}

bool compare(Inputs a, Inputs b)
{
    return a.from < b.from;
}

double sumfloor[100003];

vector<Inputs> input;
int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int n;
long long w;

    cin >>n;
    int q, r;
    cin >>q >>r;
    int i,j;
    for(i=0;i<q;i++)
    {
        cin >>inputs[i].from >>inputs[i].n;
    }


    sort(inputs,inputs+q,compare);


    for(i=0;i<=n;i++) floor[i] = 0;

    int inpcnt=0;

    long long st=1;
    for(i=1;i<=n;i++)
    {
        //cout <<i << " JJ"<<endl;
        for(j=0;j<i;j++)
        {


            while(inpcnt<q && inputs[inpcnt].from == j+st)
            {
                oldFloor[j] += inputs[inpcnt].n;
                inpcnt++;

               // cout << "inputs" <<j+st << " " <<oldFloor[j] <<endl;
            }


            floor[j] += oldFloor[j] /2;
            floor[j+1] += oldFloor[j] /2;

        }

        st += i;
        if(i<n) floorReplace(i+1);
    }

    sumfloor[0] = 0;
    for(i=0;i<=n+1;i++)

    {
        sumfloor[i+1] = sumfloor[i] + floor[i];
    }

    floorReplace(n+1);
    for(i=0;i<r;i++)
    {
        int a, b;
        cin >>a >>b;
        cout << sumfloor[b] - sumfloor[a-1] <<endl;
    }
    return 0;
}
