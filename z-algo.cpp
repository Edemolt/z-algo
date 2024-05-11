#include <bits/stdc++.h>
using namespace std;

void create_z_array(string &str, int &n, vector<int> &z_vec){
    
    int l = 0, r = 0;
    int k;
    
    for(int i = 1; i < n; i++){
        
        //  if i > r -> nothing matches and we will calculate z_vec[i];
        
        if(i > r){
            l = i;
            r = i;
            // r - l = 0 -> starts checking from the zero index
            
            while((r < n) && (str[r - l] == str[r])) r += 1;
            
            z_vec[i] = r - l;
            r -= 1;
        }else{
            
            k =  i - l;
            //  if k = i - l -> k corresponds to a number that that matches in l,r interval
            // therefore z_vec[i] = z_vec[k];
            
            
            if(z_vec[k] < r - i + 1) z_vec[i] = z_vec[k];
            else{
                l = i;
                // need to check manually starting from right
                while((r < n) && (str[r - l] == str[r])) r += 1;
                
                z_vec[i] = r - l;
                r -= 1;
            }
        }
    }
}

void find(string &text, string &pattern){
    
    int m = pattern.size();
    
    string str = pattern;
    str.push_back('#');
    for(auto &it:text) str.push_back(it);
    
    int n = str.size();
    vector<int> z_vec(n);
    
    create_z_array(str, n, z_vec);
    
    for(int i = 0; i < n; i++){
        
        // if z_vec[i] matched any which is equal to pattern length 
        if(z_vec[i] == m){
            cout<<"pattern found at index -> "<< i - m - 1<<"\n";
        }
    }
    
}

void solve(){
    string text;
    cin >> text;
    string pattern;
    cin >> pattern;
    
    find(text, pattern);
}

int main(){
    solve();
}