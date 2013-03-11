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
  int wsp_x;
  int wsp_y;

  punkt();
  
  punkt(int x,int y)
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
   double pi = 3.1415926535897932384626;
  //double bok = double(RAND_MAX); // bok jest potega liczby 10;
 //  double r_kola = double(RAND_MAX);
  double bok = 9999.0; // bok jest potega liczby 10;
  double r_kola = 9999.0;
  std::cout << bok << std::endl << r_kola;
  long x = 1;
  long y =1 ;
  int cnt_kwd = 0;
  int cnt_kol= 0;
  int cnt_srand = 1;
  int cnt_poza = 0;
  double por;
  //  punkt *p = new punkt(x,y);
  srand(time(NULL));
  for (long i = 0;i<10000000000000;i++)
    {
      
      //      cnt_kwd++;
      /*  if(cnt_kwd=2^31)
	  {
	  cnt_srand++;
	  srand(cnt_srand);
	  }*/// w razie przekroczenia okresu funkcji (2^32 liczb) rand (kiedy pobierzemy 2^32 liczbe losowa w kolejnosci od poczatku) należy uzyc innego seeda tutaj poprzez zwiekszenie  o 1 2147483647
      x = rand()%10000;
      y = rand()%10000;
      //     std::cout << x << std::endl <<y<<std::endl;
      //            punkt *p = new punkt(x,y);
      //      p->ustaw(x,y);
      //      p->wsp_y = y;
      //std::cout << p->wsp_x << std::endl <<p->wsp_y<<std::endl;
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
      if((pi-0.00000000001)<=(4.0*(long double)cnt_kol/(long double)cnt_kwd)&&(4.0*(long double)cnt_kol/(long double)cnt_kwd)<=(pi+0.00000000001))
	{
	  break;
	}
      if(cnt_kol%10000000==0){std::cout << cnt_kol << "  " << cnt_kwd << "  "<< " "<< cnt_poza << " "<< (4.0*(long double)cnt_kol/(long double)cnt_kwd) << std::endl; }
    }
  
  
  
    std::cout << cnt_kwd << std::endl << cnt_kol << std::endl;
    std::cout << "Pi wynosi "  << std::setprecision(15)<< (long double)(4.0*cnt_kol/cnt_kwd) << " "<< RAND_MAX<<std::endl;

    
    //    std::cout << double(4*cnt_kol/(cnt_kwd))<<std::endl;
    //      punkt *p = new punkt(10,10);
    //  std::cout << p->wsp_x << std::endl <<p->wsp_y<<std::endl
  //std::cout << time(NULL) << std::endl;
  //srand(1);
  //std::cout << rand()<< std::endl;
  //  srand(2);
  //std::cout << rand()<< std::endl;
 
 
  return 0;

}
