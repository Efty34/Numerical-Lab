#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;

vector<double> v ;

void parse(string s){
    // ax^2+bx+c
    int i = 0 ;
    int sign = 1 ;
    int num = 0 ;
    int var = 0 ;
    if(s[0] == '-'){
        sign = -1 ;
        i = 1 ;
    }
    for(; i < s.length() ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i] - '0') ;
        }
        else{
            if(num == 0) num = 1 ;
            v.push_back(sign*num) ;
            num = 0 ;
            sign = 1 ;
            if(var == 0){
                var = 1 ;
                i += 3;
            }
            else{
                i++ ;
            }
            if(s[i] == '-'){
                sign = -1 ;
            }
        }
    }
    v.push_back(sign*num) ;
}



double d(double x){
    return 2*v[0]*x+v[1] ;
}

double f(double x){
    return v[0]*x*x + v[1]*x + v[2] ;
}

int main(){
    cout << fixed << setprecision(7) ;
    string eqn ;
    cout << "f(x) = " ;

    // x^2-5x+4
    // x^2-4x-10
    
    cin >> eqn ;
    parse(eqn) ;
    cout << v[0] << " " << v[1] << " " << v[2] << endl ;
    cout << endl ;
    cout << "1. Newton-raphson Method\n2. Secant Method\nEnter Choice: ";
    int ch  ; cin >> ch ;
    
    if(ch == 1){
        double x1 , x2 , x;
        cout << "Enter initial guess : " ;
        cin >> x1 >> x2;
        x1 = min(abs(x1) , abs(x2)) ;
        int it = 0 ;
        while(it++ < 50){
            x = x1 - (f(x1) / d(x1)) ;
            cout << "it " << it << " : " << x << endl ;
            if(abs(x-x1) < 0.0001){
                cout << "Ans : " << x << endl ;
                break ;
            }
            x1 = x ;
        }
        if(it >= 50) cout << "Not convergent \n" ;
    }

    else if(ch == 2){
        double x1 , x2 , x3 ;
        cout << "Enter initial guess : " ;
        cin >> x1 >> x2 ;
        int it = 0 ;
        while(abs(x1-x2) > 0.0001 && it < 50){
            if(f(x2)-f(x1) == 0){ cout << x2 ; x3 = x1 ; break ; }
            x3 = (f(x2)*x1 - f(x1)*x2)/(f(x2) - f(x1)) ;
            cout << "it " << ++it << " : " << x3 << endl ;
            x1 = x2 ;
            x2 = x3 ;
        }

        if(it >= 50) cout << "Not convergent \n" ;
        else cout << "Ans : " << x3 << endl ;

    }   
}