#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int i,n;
    int hanger[4]={0,};
    queue<int> hanger_type;
    int u,d;
    int uin1, uin3, din2, din3;

    cin >> n;
    for(i=1;i<=n;i++){
        int temp;
        cin >> temp;
        hanger_type.push(temp);
        hanger[temp]++;
    }
    cin >> u >> d;

    if(hanger[1]>=u) uin1=u;
    else{
        uin1 = hanger[1];
        if(hanger[3]>=(u-hanger[1])) uin3 = (u-hanger[1]);
        else{
            cout << "NO";
            return 0;
        }
    }

    if(hanger[2]>=d) din2=d;
    else{
        din2 = hanger[2];
        if(hanger[3]>=(d-hanger[2])) din3 = (d-hanger[2]);
        else{
            cout << "NO";
            return 0;
        }
    }

    cout << "YES"<< endl;
    for(i=1;i<=n;i++){
        int temp = hanger_type.front();
        hanger_type.pop();
        if(temp==3){
            if(uin3){
                uin3--;
                cout << "U";
            }
            else if(din3){
                din3--;
                cout << "D";
            }
        }
        else{
            if(temp==2) cout << "D";
            else cout << "U";
        }
    }

    return 0;
}