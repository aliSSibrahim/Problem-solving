
//CSES Problem Set: Sorting and Searching:E - Restaurant Customers

#include<bits/stdc++.h>
#include<cmath>
#include<string>
#include<vector>
#include <iostream>
#include<algorithm>
#include<iterator>
#include<deque>
#include<list>
#include<utility>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define ll long long
#define F first
#define S second
#define B begin()
#define E end()
#define ve vector
#define pb  push_back
#define in insert
#define yes "YES\n"
#define en '\n'
#define no "NO\n"
#define cinv for(int i=0;i<n;i++)cin>>v[i]
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#include <bits/stdc++.h>
using namespace std;

//compression
struct coordinateCopmression{
private:
    vector<ll>init;
    void compress(vector<ll>&v)
    {
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
    }
public:
    coordinateCopmression(vector<ll>&v)
    {
        init=v;
        compress(init);
    }
    int index(ll val)
    {
        return lower_bound(init.begin(),init.end(),val)-init.begin();
    }
    ll initVal(int idx)
    {
        return init[idx];
    }
};
int main() 
{
    ll n;
    cin>>n;
    ll l[n+1],r[n+1];
    ve<ll>idx;
    for(int i=0;i<n;i++)
    {
      cin>>l[i]>>r[i];
      idx.pb(l[i]);
      idx.pb(r[i]);
    }
    coordinateCopmression co(idx);
    for(int i=0;i<n;i++)
    {
      l[i]=co.index(l[i]);
      r[i]=co.index(r[i]);
    }
    ll par[2*n+1]={};
  
    for(int i=0;i<n;i++)
    {
  
      par[l[i]]++;
      par[r[i]+1]--;
    }
    for(int i=1;i<2*n+1;i++)
    {
      par[i]+=par[i-1];
    }
    cout<<*max_element(par,par+n+n+1);
   
    
    return 0;
}