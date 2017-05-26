#include <iostream>
#include <cmath>

using namespace std;
float funct(float a){
    return a*a-4;
}

float bisect(float a, float b,  float (*f)(float), float tolerance = 0.000001){
	if( a > b){	// we need always a < b
		float temp = b;
		b = a;
		a = temp;
	}
	float fa = f(a), fb = f(b), fab = fa * fb;

	if(fab > 0){
		throw out_of_range("Solution does not lie in given region");
	} else if(fa == 0){
		return a; // a is the solution
	} else if(fb ==0){
		return b; // b is the solution.
	} else {
		// This region contains the solution
		float c, lastc;
		do{
			c = (a + b) / 2;
			float fc = f(c);

	        	if(fc == 0){	// We have found a solution.
	        		break;
	        	} else if(fc > 0 ){
				a = c;
			} else {
				b = c;
			}
	        	lastc = c;
	        	c= (a+b) / 2;
		} while(abs(lastc -c ) > tolerance);
		return c;
	}
}

int main(){
    float a, b;

    cout << "Enter a and b :" ;
    cin >> a >> b;

    try{
	float value = bisect (a, b, funct);
	cout << "a = " << value << endl;
    } catch(out_of_range &e){
	cout << e.what() << endl;
    }
}
