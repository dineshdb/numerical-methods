#include <iostream>
#include <cmath>

using namespace std;
void curveFitting(float d[][2], float n, float *a, float *b, bool isExpo = false);

void curveFittingExpo(float d[][2], float n, float *a, float *b){
    curveFitting (d, n, a, b, true);
}

void curveFittingLinear(float d[][2], float n, float *a, float *b){
    curveFitting (d, n, a, b);
}

void curveFitting(float d[][2], float n, float *a, float *b, bool isExpo){
    float sx = 0, sy = 0, sx2 = 0, sxy = 0;

    for(int i=0;i < n;i++){
        float x = d[i][0];
	float y = d[i][1];
	if(isExpo)
        	y = log(y);
        sx += x;
        sy += y;
        sx2 += x * x;
        sxy += x * y;
    }

    float det = n * sx2 - sx * sx;
    float deta = sx2 * sy - sxy * sx;
    float detb = n * sxy  - sy  * sx;
    *a = deta / det;
    *b = detb / det;
}

int main() {
    int n;
    float aa, bb;

    float m[][2] = {
	{2 , 3},
	{4, 5},
	{6, 7},
	{5, 4}
    };
    n=4;
    curveFitting (m, n, &aa, &bb);
    cout << "Linear a :" << exp(aa) << " b : " << bb << endl;
    curveFittingExpo (m, n, &aa, &bb);
    cout << "Expo a :" << exp(aa) << " b : " << bb << endl;
    return 0;
}
