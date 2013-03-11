#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <iomanip>


long double epsilon_in;

int main()
{
	std::cout << "Write what  approximation You want to have when calculating Pi number:  ";
	std::cin >> epsilon_in;
	std::cout << epsilon_in;
	long double epsilon_var = epsilon_in;
	long double abs_epsilon_var = 0.01;
	long double pi_exact = 3.14159265358979;
	long double pi_approx;
	const int period = log((RAND_MAX)/log(2)); // here we define the  period of rand() function as the power of 2
	double bok = 9999.0; // here we define  square size
	double r_kola = 9999.0; // here we define radius of circle
	long x = 1;
	long y =1 ;
	int cnt_kwd = 0;
	int cnt_kol= 0;
	int cnt = 0;
	int cnt_poza = 0;
	srand(time(NULL)); /// using different seeds to have more statistically proper results

	//main loop --------------------------------------------
	while(std::abs(epsilon_var)>=epsilon_in)
	{
		cnt++;
		/// we use this condition in case that number of iterations exceeds the period of rand() function, which is defined by RAND_MAX (each number appears only once)
		if(cnt==pow(2,period))
		{
			srand(time(NULL));
			cnt = 0;
		}

		x = rand()%10000;
		y = rand()%10000;

		if((long double)x<=bok&&(long double)y<=bok)
		{
			cnt_kwd++;
		}
		if((long double)(sqrt(x*x+y*y))<=(r_kola))
		{
			cnt_kol++;
		}
		else
		{
			cnt_poza++;
		}

		pi_approx = (4.0*(long double)cnt_kol/(long double)cnt_kwd);
		epsilon_var = pi_exact-pi_approx;
		abs_epsilon_var = std::abs(epsilon_var)<=epsilon_in;
		
		// this condition shows current calculated value of pi, epsilon_var, and number of points in circle and square
		if(cnt_kol%10000000==0)
		{
			std::cout << " number of points in circle: "<<cnt_kol << " square : " << cnt_kwd << " current Pi value: \t"<<  pi_approx << "current absolute error:\t"<< abs_epsilon_var << std::endl; 
		} 
	}

	std::cout << cnt_kwd << std::endl << cnt_kol << std::endl;
	std::cout << "PI Approximation: "  << std::setprecision(15) << pi_approx << std::endl;

	return 0;
}
