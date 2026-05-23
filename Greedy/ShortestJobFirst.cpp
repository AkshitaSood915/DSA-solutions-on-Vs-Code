#include <bits/stdc++.h>
using namespace std;

class shortestJobFirst{
public:

 long avgWaitingTime(vector <int>& arr){

     sort(arr.begin(),arr.end());

     int t=0, wtTime=0, n=arr.size();

     for(int i=0;i<n;i++){
        wtTime+=t;
        t+=arr[i];
     }
     return wtTime/n;
 }
};

int main(){
 int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter burst time of processes: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    shortestJobFirst obj;

  long avgWaitingTime = obj.avgWaitingTime(arr);

  cout<<"Average Waiting time of the processes is "<<avgWaitingTime;

    return 0;
}