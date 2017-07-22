#include <iostream>
#include <cmath>
using namespace std;
#define e 2.718
#define pi 3.1415926
#define length 100
const double mu = 3;
const double xigema = 1;
double random(double a,double mu,double xigema)
{
	return 1 / (sqrt(2 * pi)*xigema)*pow(e, -(a - mu)*(a - mu) / (2 * xigema*xigema));
}
int main()
{
	
	double ans = 0;
	for (int i = 1; i <= length-1; ++i)
	{
		double t = i * (6 * xigema) / length + mu - 3 * xigema;
		cout << random(t, mu, xigema)<<'\n';
		ans+=random(t, mu, xigema)*(6 * xigema)/length;
	}
	cout << ans;
	return 0;
}