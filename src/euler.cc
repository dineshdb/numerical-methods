#include <iostream>
#include <cmath>

using namespace std;

float df(float x , float y){
    return x + y;
}

float eigen(float x0, float y0, float xn, float h, float (*f)(float, float)){
	while(x0 < xn){
		y0 += f(x0, y0) * h;
		x0 += h;
	}
	return y0;
}

int main(){
    float xo,yo,xn,h;

    cout << " x0, xn =";
    cin >> xo >> xn;

    cout << " h = " ;
    cin >> h;

    cout << " y(" << xo << ") = ";
    cin >> yo;

    float approx = eigen (xo, yo, xn, h, df);
    cout << "y(" << xn << ")=" << approx << endl;
    return 0;
}
