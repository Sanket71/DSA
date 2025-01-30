#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> b(n);
    map<int,int> mp;

    for(int i=0;i<n;i++){
        cin>>b[i];
        mp[b[i]]++;
    }

    vector<pair<int,int>> entries;
    for(auto&entry:mp){
        entries.push_back({entry.first,entry.second});
    }

    int size=entries.size();
    int step=0;

    for(int i=size-1;i>0;i--){
        entries[i-1].second+=entries[i].second;
        step+=entries[i].second;
    }

    cout<<step<<endl;
    return 0;
}