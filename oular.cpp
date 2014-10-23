/*
	若n是质数p的k次幂，φ(n)=φ(p^k)=p^k-p^(k-1)=(p-1)*p^(k-1)
	若gcd(m, n)=1  则φ(m*n)=φ(m)*φ(n)
*/
int eular(int n)
{
  int ret=1, i;  //ret为最终结果
  
  for(i=2; i*i<=n; i++)		//i*i<=n  <=> i<=(int)sqrt(n),不需要遍历到n/2
  {
	  if(n%i==0)		//可以根据注释里面的2个性质
	  {					//解释这个条件语句里面的实现
	      n/=i;
		  ret*=i-1;
		  while(n%i==0)
		  {
			  n/=i;
			  ret*=i;
		  }
	  } 
  }
  if(n>1)		//如果最后n不为1，说明n为一个质数
    ret*=n-1;
  return ret;
}
