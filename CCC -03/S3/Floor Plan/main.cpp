#include <bits/stdc++.h>
#define R 25
#define C 25
#define ii pair<int,int>
using namespace std;
int r,c,f,rooms=0,floore=0;
vector<int> floors;
char M[R][C];

ii dir[4]={ {1,0},{0,1},{-1,0},{0,-1} };

void compute(int i,int j)
{
    if(M[i][j]=='.'){
       M[i][j]='m';
       floore++;
    }
    for(int x=0;x<4;x++){
        int t1=i+dir[x].first;
        int t2=j+dir[x].second;
        if( (M[t1][t2]== '.') ){
            compute(t1,t2);
        }
    }


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>f;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>M[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(M[i][j]=='.'){

                compute(i,j);

                floors.push_back(floore);
                floore=0;
            }
        }
    }
    sort(floors.begin(),floors.end());
    int l=floors.size()-1;
    while(f-floors[l]>0){
        rooms++;
        f-=floors[l];
        l--;
    }
    cout<<rooms<<" rooms, "<<f<<" square metre(s) left over \n";
    return 0;
}
