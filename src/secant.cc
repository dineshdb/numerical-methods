#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;
float f(float x){
	return (sin(x)+3*x+2);
}

class Indeterminate{};

float secant(float (*f)(float), float tolerance = 0.000001, float a = 1, float b =2 ){
	float c;
	do{
		if(f(b) == f(a)){
			throw Indeterminate();
		}
		c = (a * f(b) - b * f(a)) / (f(b) - f(a));
		a = b;
		b = c;

	} while(fabs(f(c)) < tolerance);
	return c;
}
int main(){
    float ans = secant (f);
    cout << "f(x) = sinx + 3x^2, x =" << ans << endl;
}
