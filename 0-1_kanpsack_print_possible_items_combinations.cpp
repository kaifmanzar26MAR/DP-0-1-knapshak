#include<bits/stdc++.h>
using namespace std;
class Pair{
public:
    int i;
    int j;
    string psf;
    Pair(int i,int j,string psf){
        this->i=i;
        this->j=j;
        this->psf=psf;
    }
};
int main(){
    int n;
    cout<<"Enter the size"<<endl;
    cin>>n;
    int value[n];
    int weight[n];
    cout<<"Enter value array"<<endl;
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    cout<<"Enter weight array"<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    int cap;
    cout<<"enter capacity"<<endl;
    cin>>cap;
    vector<vector<int>> dp(n+1,vector<int>(cap+1,0));
    for(int i=1;i<=n;i++){
        for(int bag_capacity=1;bag_capacity<=cap;bag_capacity++){
            if(bag_capacity>=weight[i-1]){
                int remaining_cap_of_bag=bag_capacity-weight[i-1];
                dp[i][bag_capacity]=max(dp[i-1][remaining_cap_of_bag]+value[i-1],dp[i-1][bag_capacity]);
                // if(dp[i-1][remaining_cap_of_bag]+value[i-1]>dp[i-1][bag_capacity]){
                //     dp[i][bag_capacity]=dp[i-1][remaining_cap_of_bag]+value[i-1];
                // }else{
                //     dp[i][bag_capacity]=dp[i-1][bag_capacity];
                // }
            }else{
                dp[i][bag_capacity]=dp[i-1][bag_capacity];
            }
        }
    }
    cout<<dp[n][cap]<<endl;
    //Reverse engineering with bfs
    queue<Pair*> q;
    q.push(new Pair(n,cap,""));
    while(!q.empty()){
        Pair* rem=q.front();
        q.pop();
        if(rem->i==0 || rem->j==0){
            cout<<rem->psf<<endl;
            continue;
        }
        int exc=dp[rem->i-1][rem->j];
        int inc=-1;
        if(rem->j>=weight[rem->i-1])
            inc=dp[rem->i-1][rem->j-weight[rem->i-1]]+value[rem->i-1];

        if(dp[rem->i][rem->j]==inc){
            q.push(new Pair(rem->i,rem->j-weight[rem->i-1],to_string(rem->i-1)+" "+rem->psf));
        }
        if(dp[rem->i][rem->j]==exc){
            q.push(new Pair(rem->i-1,rem->j,rem->psf));
        }
        
    }
    
return 0;
}
// 5
// 15 14 10 45 30
// 2 5 1 3 4
// 7
//op: 75
//    3 4