#include <iostream>
#include <cmath>

using namespace std;
float funct(float a){
    return a*a-4;
}

float bisect(float a, float b, float tolerance,  float (*funct)(float)){
	if( a > b){	// we need always a < b
		float temp = b;
		b = a;
		a = temp;
	}
	float fa = funct(a), fb = funct(b), fab = fa * fb;

	if(fab > 0){
		throw out_of_range("Solution does not lie in given region");
	} else if(fab == 0){
		// One of the input is solution
		return fa == 0 ? a : b;
	} else {
		// This region contains the solution
		float c, lastc;
		do{
			c = (a + b) / 2;
			float fc = funct(c);

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
    float tolerance = 0.0000001;
    float a, b;

    cout << "Enter a and b :" ;
    cin >> a >> b;

    try{
	float value = bisect (a, b, tolerance, funct);
	cout << "a = " << value << endl;
    } catch(out_of_range &e){
	cout << e.what() << endl;
    }
}
