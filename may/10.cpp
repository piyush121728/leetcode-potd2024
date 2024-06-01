#include<bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            float ans = arr[i]*1.0/arr[j];
            cout<<arr[i]<<" / "<<arr[j]<<" = "<<ans<<endl;
        }
    }
    cout<<endl;
    return {};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(auto &x:arr){
        cin>>x;
    }

    kthSmallestPrimeFraction(arr,0);
}