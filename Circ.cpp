#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <iomanip>



/*class wspolrzedna
{
public:
  int x,y;
  int rand_x()
  {
    x = rand()%10000;
    return x;
  }
  
  int rand_y()
  {
    y = rand()%10000;
    return y;
  }
};*/

class punkt
{
public:
  long wsp_x;
  long wsp_y;

  punkt();
  
  punkt(long x,long y)
  {
    wsp_x = x;
    wsp_y = y;
  }

  //metody

  void ustaw(int x, int y)
  {
     wsp_x = x;
     wsp_y = y;
  }


  int pokaz_x()
  {
    return wsp_x;
  }

  int pokaz_y()
  {
    return wsp_y;
  }
  
  bool punkt_w_kole( int r_kola)
  {
    if(sqrt(wsp_x^2+wsp_y^2)<=r_kola)
      return true;
    else false;
  }

  bool punkt_w_kwadracie(int wsp_x, int wsp_y, int bok)
  {
    if( wsp_x<=bok&&wsp_y<bok)
      return true;
    else false;
  }
};


int main()
{
  long double epsilon_in = 0.00000000001;
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
  srand(time(NULL));

  //main loop --------------------------------------------

  while(std::abs(epsilon_var)>=epsilon_in)
    {
      cnt++;
      if(cnt==pow(2,period))
	  {
	  srand(time(NULL));
	  cnt = 0;
	  }/// we use this condition in case that number of iterations exceeds the period of rand() function, which is defined by RAND_MAX (each number appears only once)
      x = rand()%10000;
      y = rand()%10000;
      //punkt *p;
      //p->ustaw(x,y);
      //            std::cout << p->wsp_x << "\t"<<p->wsp_y;break;
      //      p->wsp_y = y;
      //      if(p->punkt_w_kole(r_kola))
      if((long double)x<=bok&&(long double)y<=bok)
	{
	  cnt_kwd++;
	}
      if((long double)(sqrt(x*x+y*y))<=(r_kola))
	{
	  cnt_kol++;
	  //	  std::cout << p->pokaz_x() << std::endl << p->pokaz_y() << std::endl;
	}
      else
	{
	  cnt_poza++;
	}

      pi_approx = (4.0*(long double)cnt_kol/(long double)cnt_kwd);
      epsilon_var = pi_exact-pi_approx;
      abs_epsilon_var = std::abs(epsilon_var)<=epsilon_in;
      if(cnt_kol%10000000==0)
	{std::cout << " number of points in circle: "<<cnt_kol << " square : " << cnt_kwd << " current Pi value: \t"<<  pi_approx << "current absolute error:\t"<< abs_epsilon_var << std::endl; // this condition shows current calculated value of pi, epsilon_var, and number of points in circle and square
	} 
    }
  
    std::cout << cnt_kwd << std::endl << cnt_kol << std::endl;
    std::cout << "Pi wynosi "  << std::setprecision(15)<< pi_approx << " "<< cnt_kwd << "\t"<< std::abs(epsilon_var) <<std::endl;
 
  return 0;

}
