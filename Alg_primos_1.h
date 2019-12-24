//Algoritmos de los números primos//
//Los algoritmos que se incluiran en esta sección serán: //
//El número primo ene-simo "eneprimo"// 
//El número n es primo "esprimo"//
//Identificación de coprimos "coprimo"//
//Encontrar primos gemelos "gemeloprimo"//
//Mayor potencia prima que divide a un numero "poprimadiv"//
//Enesimo primo que divide a un numero "eneprimadiv"//
//Número de primos que dividen a un numero "numprimadiv"//
//Máximo cómun divisor "maxdivisor"//
//Mínimo cómun multiplo "minmultiplo"//
//Número de divisores positivos"numdiv"//
//Función de Euler, Numero de coprimos a un número por coprimos "funeuler"//
//Enesimo número que divide a otro número "enediv"//
//La suma de los divisores positivos de un número, será dada por "sumdiv"//
//Posteriormente se incluirán más algoritmos para más funciones con los mismos números primos//

int eneprimo(int a);
int esprimo(int a);
int coprimo(int a, int b);
int gemeloprimo(int a);
int poprimadiv(int a, int b);
int eneprimadiv(int a, int b);
int numprimadiv(int a);
int maxdivisor(int a, int b);
int minmultiplo(int a, int b);
int numdiv(int a);
int funeuler(int a);
int enediv(int a, int b);
int sumdiv(int a);

//Aquí tenemos la suma de divisores positivos de un número, con el algoritmo de la suma, posteriormente, se podría reprogramar con el de//
//El producto//

int sumdiv(int a)
{
int n=numdiv(a);
int res=0;
for(int i=1;i<=n;i++)
{
res=res+enediv(i,a);
}
return(res);
}


//Al igual que su antecesor, el eneprimadiv, esta función primero coloca con a el enesimo termino, y con b el número evaluado//
//ESTE CÓDIGO ESTA PROPENSO A REPROGRAMACIÓN//
int enediv(int a, int b)
{
if(a>numdiv(b))
{
return(0);
}
else
{
int res=0;
int c=1;
for(int i=1;c<=a;i++)
{
if(b % i == 0)
{
res=i;
c++;
}
}
return(res);
}
}

int funeuler(int a)
{
int res=0;
for(int i=1;i<a;i++)
{
if(coprimo(i,a)==1)
{
res++;
}
}
return(res);
}

int numdiv(int a)
{
int res=1;
for(int i=1;i<=numprimadiv(a);i++)
{
res=res*(poprimadiv(eneprimadiv(i,a),a)+1);
}
return(res);
}

int minmultiplo(int a, int b)
{
int c=maxdivisor(a,b);
int d=a/c;
int e=b/c;
int res=d*e*c;
return(res);
}

int maxdivisor(int a, int b)
{
int p=0;
int c=a;
int d=b;
int res=1;
for(int i=1;p<=c;i++)
{
p=eneprimo(i);
if(c % p == 0)
{
if(d % p == 0)
{
c=c/p;
d=d/p;
res=res*p;
i=0;
}
}
}
return(res);
}

int numprimadiv(int a)
{
int p=0;
int c=0;
for(int i=1;p<=a;i++)
{
p=eneprimo(i);
if(a % p == 0)
{
c++;
}
}
return(c);
}

//a es el enesimo primo y b es el número evaluado//
int eneprimadiv(int a, int b)
{
if(eneprimo(a)>b||numprimadiv(b)<a)
{
return(0);
}
else
{
int p=0;
int p1=0;
int c=0;
for(int i=1;c<a&&p<=b;i++)
{
p=eneprimo(i);
if(b % p == 0)
{
c++;
p1=p;
}
}
if(p1<=b)
{
return(p1);
}
else
{
return(0);
}
}
}

//a es el primo b es el número que deberá ser dividido //
int poprimadiv(int a, int b)
{
if(esprimo(a)==1)
{
int c=b;
int d=0;
int e=0;
do{

if(c % a == 0)
{
c=c/a;
e++;
}
else
{
d=1;
}
}while(d==0);
return(e);
}
else
{
return(NULL);
}
}

int gemeloprimo(int a)
{
if(esprimo(a)==0)
{
 return(NULL);
}
else
{
if(esprimo(a+2)==1)
{
return(a+2);
}
if(esprimo(a-2)==1)
{
return(a-2);
}
else
{
return(0);
}
}
}

int coprimo(int a, int b)
{
int c=0; 
int residuo=0; 
int residuo2=0;

for(int i=1;i<=a;i++) 
{ 
residuo = a % i;
residuo2 = b % i;
if(residuo==0&&residuo2==0) {
c++;
}
residuo=0; 
} 
if(c==1){
return(1);
}
else{
return(0);
}
}

/*
FUNCIÓN DE ENEPRIMO 1
int c=1;
for(int i=3;c==a;i++){		
		int d=0;
		for(int j=2;j<=i;j++){
			int x=i % j;
			if(x==0){
			d=1;
			}
			}
			if(d==0){
				c++;
			}		
	}
if(c==1){
	return(2);
}
else{
return(c);
}
*/

int eneprimo(int a)
{
int c=0;
int d=0;
int res;
int residuo=0; 
for(int j=1;d<=a-1;j++)
{
c=0;
for(int i=1;i<=j;i++) 
{ 
residuo = j % i; 
if(residuo==0) {
c++;
}
residuo=0; 
} 
if(c==2){
d++;
res=j;
}
}
return(res);
}

int esprimo(int a)
{
int c=0; 
int residuo=0; 

for(int i=1;i<=a;i++) 
{ 
residuo = a % i; 
if(residuo==0) {
c++;
}
residuo=0; 
} 

if(c==2){
return(1);
}
else{
return(0);
}
}