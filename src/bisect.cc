#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

float funct(float a){
    return a*a-4;
}

float bisect(float a, float b,  float (*f)(float), float tolerance = 0.0001){
	if(f(a) * f(b) > 0){
		throw out_of_range("Solution does not lie in given region");
	} else if(f(a) == 0){
		return a; // a is the solution
	} else if(f(b) ==0){
		return b; // b is the solution.
	} else {
		// This region contains the solution
		float c, fc;
		
		// So f(a) lies below the axis, lets swap it. It'll save us one multiplication. Suggestion : Kapildev	
		if(f(a) < 0) {
			float temp = b;
			b = a;
			a = temp;		
		}

		for(int i=0; i < 1000; i++){	// Prevent infinite loop
			c = (a+b) / 2;
			fc = f(c);

			if(fc == 0 || fabs(b - a) < tolerance){
				return c;
			}
			if(fc > 0){	// Both are same sign i.e. lie on the same side from solution.
				a = c;
			} else {
				b = c;
			}	
		}
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
