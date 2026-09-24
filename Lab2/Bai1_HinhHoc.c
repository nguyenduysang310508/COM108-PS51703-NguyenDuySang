#include  <stdio.h>
#define PI 3.14
int main()
{
  float d , r , bk , cv_hcn , dt_hcn , cv_ht, dt_ht;
  // du lieu hinh cn
  printf("chieu dai hinh chu nhat: ");
  scanf("%f",&d);
  printf("chieu rong hinh chu nhat: ");
  scanf("%f",&r);


  // Tính hình cho hcn    
  cv_hcn = (d+r)*2;
  dt_hcn = d*r;
  // tính hình tròn 
  cv_ht = 2 * PI * r; 
  dt_ht = PI *r * r;
  // kq
  printf("Chu vi hinh chu nhat: %g\n", cv_hcn);
    printf("Dien tich hinh chu nhat: %g\n", dt_hcn);
    printf("Chu vi hinh tron: %.2f\n", cv_ht);
    printf("Dien tich hinh tron: %.2f\n", dt_ht);

    return 0;
}