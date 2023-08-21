#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;

vector<double> string_to_coefficient(string s){
    vector<double>v ;
    int num = 0 ;
    int sign = 1 ;
    int idx = 0 ;
    if(s[0] == '-'){
        sign = -1 ;
        idx = 1 ;
    }

    for(;idx < s.length() ; idx++){
        if(s[idx] <= '9' && s[idx] >= '0'){
            num = num*10 + (s[idx] - '0') ;
        }
        else{
            if(num == 0) num = 1 ;
            v.push_back(sign*num) ;
            num = 0 ;
            sign = 1 ;
            idx++ ;
            if(s[idx] == '-'){
                sign = -1 ;
            }
        }
    }
    v.push_back(sign*num) ;
    return v ;
}

int main(){
    string e1 , e2 , e3 ;
    cin >> e1 >> e2 >> e3 ;
    
    vector<double>v1 = string_to_coefficient(e1) ;
    vector<double>v2 = string_to_coefficient(e2) ;
    vector<double>v3 = string_to_coefficient(e3) ;

    double a1 , b1 , c1 , d1 ;
    a1 = v1[0] ; b1 = v1[1] ; c1 = v1[2] ; d1 = v1[3] ;

    cout << a1 << " " << b1 << " " << c1 << " " << d1 << endl ;


    double a2 , b2 , c2 , d2 ;
    a2 = v2[0] ; b2 = v2[1] ; c2 = v2[2] ; d2 = v2[3] ;

    cout << a2 << " " << b2 << " " << c2 << " " << d2 << endl ;


    double a3 , b3 , c3 , d3 ;
    a3 = v3[0] ; b3 = v3[1] ; c3 = v3[2] ; d3 = v3[3] ;

    cout << a3 << " " << b3 << " " << c3 << " " << d3 << endl ;


    double x , y , z ;
    x = y = z = 0 ;
    double px , py , pz ;
    px = py = pz =  9 ;

    while(abs(px-x) > 0.0001 || abs(py-y) > 0.0001 || abs(pz-z) > 0.0001){
        px = x ;
        py = y ;
        pz = z ;
        x = (d1 - b1*y - c1*z)/a1 ;
        y = (d2 - a2*x - c2*z)/b2 ;
        z = (d3 - a3*x - b3*y)/c3 ;
    }


    cout << fixed << setprecision(5) << x << " " << y << " " << z << endl ;
}