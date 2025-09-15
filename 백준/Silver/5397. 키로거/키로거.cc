#include <iostream>
#include <string>
#include <cmath>
#include <list>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int testn;

    cin>>testn;

    while(testn--){
        list<char> l;
        auto it=l.begin();
        string s;
        cin>>s;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='<'){
                if(it!=l.begin()){
                    it--;
                }
            }
            else if(s[i]=='>'){
                if(it!=l.end()){
                    it++;
                }
            }
            else if(s[i]=='-'){
                if(it != l.begin()){
                    it--;
                    it =l.erase(it);
                }
            }
            else{
                l.insert(it, s[i]);
            }
        }
        for(char c : l){
            cout<<c;
        }
        cout<<"\n";
    }

}