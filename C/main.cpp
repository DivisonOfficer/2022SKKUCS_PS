#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


char t[100011];



#define mid 200000

int cntmx[400055], cntmn[400055];
int orix[400055], orin[4000055];

int main()
{


    cin >>t;

    int len = strlen(t);
    int i;
   for(i=0;i<=400044;i++) {cntmx[i] = -1;
    cntmn[i] = -1;
    orix[i] = -1;
    orin[i] = -1;
    }
    int value = 0;
    cntmn[mid] = 0;
    int cntS = 0;
    int cntK = 0;
    int ismodi=0;
    for(i=0;i<len;i++)
    {

        ismodi = 0;
        if(t[i] =='\0' || t[i] == '\n') continue;
        if(t[i] == 'S') {value+= 2;
            cntS ++;
            ismodi=1;
        }
        else if(t[i] == 'K') {value-=1;
        ismodi=1;
        cntK ++;
        }
        //if(value == 0 &&( cntS<1 || cntK <2)) continue;
        //if(value != 0 && !ismodi) continue;
        int vv= value +mid;
        if(cntmx[vv] == -1 || cntmx[vv] < i) {cntmx[vv] = i;
        if(ismodi) orix[vv] = i;
        }
        if(cntmn[vv] == -1 || cntmn[vv] > i) {cntmn[vv] = i;
        if(ismodi) orin[vv] = i;
        }

    }

    int ans = -1;
    if(cntS < 1 || cntK < 2)
    {
       printf("%d",ans);
        return 0;
    }
    for(i=0;i<=len*2;i++)
    {
        int cm = cntmx[i+mid] - cntmn[mid+i] + (i==0?1 :0);
         if(cm>=3 &&cntmx[i+mid]!=-1 && cntmn[mid+i] !=-1 && cm > ans && orin[mid+i] != orix[mid+i]) {ans = cm;
          //  cout << i << " a " << cntmx[i+mid] << " " << cntmn[mid+i] << endl;
        }
        int cn = cntmx[mid-i] - cntmn[mid-i] + (i==0?1 :0);

         if(cn>=3 &&cntmx[mid-i]!=-1 && cntmn[mid-i] !=-1 && cn > ans &&orin[mid-i] != orix[mid-i]) {ans = cn;
           // cout << i << " b " << cntmx[mid-i] << " " << cntmn[mid-i] << endl;
        }

    }
    if(ans<3) ans = -1;
    printf("%d",ans);
    return 0;
}
