#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
#define pi 3.14159265358979323846264338327
int N;
struct vec {
	    double x, y;
	    void operator =(const vec a) {
		        if (fabs(a.x)>1e-20) x = a.x;
		        else x = 0;
	        if (fabs(a.y) > 1e-20) y = a.y;
		        else y = 0;
		
	}
	   vec operator +(const vec a) {
		        vec tmp;
		        tmp.x = x + a.x;
		        tmp.y = y + a.y;
		        return tmp;
		
	}
	   vec operator *(const vec a) {
		        vec tmp;
		        tmp.x = x*a.x - y*a.y;
		        tmp.y = x*a.y + a.x*y;
		        return tmp;
		
	}
	
};

vec* fft(vec *X, int n, vec w) {
	    if (n == 2) {
		        vec *y = (vec*)malloc(n * sizeof(vec));
		        y[0] = X[0] + X[1];
		        y[1] = X[0] + w*X[1];
		        return y;
		
	}
	    vec *odd = (vec*)malloc(n / 2 * sizeof(vec));
	    vec *even = (vec*)malloc(n / 2 * sizeof(vec));
	    int k1 = 0, k2 = 0;
	    for (int i = 0; i < n; i += 2)
		    {
		        odd[k1++] = X[i + 1];
		        even[k2++] = X[i];
		    }
	    vec *p = fft(even, n / 2, w*w);
	    vec *q = fft(odd, n / 2, w*w);
	    free(even); free(odd);
	    vec *y = (vec*)malloc(n * sizeof(vec));
	    vec wi; wi.x = 1; wi.y = 0;
	    for (int i = 0; i < n / 2; i++)
		    {
		        y[i] = p[i] + wi*q[i];
		        wi = wi*w;
		    }
	    for (int i = 0; i < n / 2; i++)
		    {
		        y[i + n / 2] = p[i] + wi*q[i];
		        wi = wi*w;
		    }
	    free(p); free(q);
	    return y;
	
		
}

int main() {
	    vec X[16400];
		//in
	    scanf("%d", &N);
	    for (int i = 0; i < N; i++)
		    {
		        scanf("%lf %lf", &X[i].x, &X[i].y);
		    }
	    //fft
		    vec w;
	    w.x = cos(2 * pi / N);      w.y = sin(2 * pi / N);
	
		    vec *Y = fft(X, N, w);
			//out
	    double m = N;
	    for (int i = 0; i < N; i++)
		        printf("%.2lf %.2lf\n", Y[i].x / m, Y[i].y / m);
	
		    return 0;
	
		
		
}
