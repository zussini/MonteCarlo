#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>

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
  int wsp_x,wsp_y;
  /*  void ustaw()
  {
    //  srand(time(NULL));
    int wsp_x = rand()%1000;
    //srand(time(NULL));
    int wsp_y = rand()%1000;
    }*/
  punkt(int x,int y)
  {
    wsp_x = x;
    wsp_y= y;
  }
  int pokaz_x()
  {
    return wsp_x;
  }
  int pokaz_y()
  {
    return wsp_y;
  }

private:
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
  double pi;
  int bok = 10^3; // bok jest potega liczby 10;
  int r_kola = bok/2;
  // cnt_wszystkie ++; if point <= sqrt(wsp_x^2+wsp_y) cnt_kolo++
  int x = 1;
  int y =1 ;
  int cnt_kwd = 0;
  int cnt_kol= 0;
  for (int i = 0;i<5;i++)
    {
      cnt_kwd++;
      x = rand()%bok; /// okres - 2^32
      y = rand()%bok;
      punkt* p = new punkt(x,y);
      if(x<=r_kola&&y<=r_kola)
	{
	  cnt_kol++;
	  //	  std::cout << p->pokaz_x() << std::endl << p->pokaz_y() << std::endl;
	}
    }
   std::cout << cnt_kwd << std::endl << cnt_kol << std::endl;
  std::cout << time(NULL);
  srand(1);
  std::cout << rand()<< std::endl;
  srand(1);
  std::cout << rand()<< std::endl;
  return 0;
}
