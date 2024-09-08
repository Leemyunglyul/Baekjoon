#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <map>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string pre, s;
    int i, check;

    while(1){
        cin>>s;
        if(s=="#") break;
        bool anw=true;
        while(1){
            check=0;
            pre=s;
            cin>>s;
            if(s=="#") break;
            //cout<<s.length()<<" " <<pre.length()<<endl;
            else if(!(s.length()==pre.length())){
                anw=false;
                continue;
            }
            for(i=0;i<s.size();i++){
                if(s[i]!=pre[i]) check++;
            }
            if(check>=2 || check==0) anw=false;
        }
        if(anw) cout<<"Correct\n";
        else cout<<"Incorrect\n";
    }

}

/*
for(i=1;i<=n;i++){
        
}
*/