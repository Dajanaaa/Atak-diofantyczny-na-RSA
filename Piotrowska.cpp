#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> ulamek(long long int e ,long long int N)
{
	long long int q, tmp;
	vector<int>wektor;
	do
	{
		q=e/N;
		tmp=e;
		e=N;
		N=tmp-N*q;
		wektor.push_back(q);
		cout<<q<<" ";
	}while(N);

return wektor;	
	
}


struct redukt {
	long long int k;
	long long int d;
};

vector<redukt> utworz_redukty(vector<int>wektor)
{
	int i=0;
	vector<redukt> redukty;
	redukt pom;
	
	for(i=0;i<wektor.size();i++)
	{
		if(i==0)
		{
		    pom.k=0;
	        pom.d=1;
	        redukty.push_back(pom);
	        cout<<pom.k<<"/"<<pom.d<<" ";
			
		}
		if(i==1)
		{
			pom.k=1;
			pom.d=wektor[1];
			redukty.push_back(pom);
			cout<<pom.k<<"/"<<pom.d<<" ";
			
		}
		if(i>1)
		{
		pom.k=(wektor[i]*redukty[i-1].k+redukty[i-2].k);
		pom.d=(wektor[i]*redukty[i-1].d+redukty[i-2].d);
		cout<<pom.k<<"/"<<pom.d<<" ";

		redukty.push_back(pom);
		}
	}
		return redukty;
	
}

void rownanie( long long int e ,long long int N, vector<redukt>redukty)
{
	long long int p=1, q=1, a=1, b, delta, fi=1;
	int i=1;
	
	while(p*q!=N)
	{
		fi=((e*redukty[i].d-1)/redukty[i].k);
		b=-((N-fi)+1);
		delta=(b*b)-(4*(a*N));
		
		p=(-b+sqrt(delta))/2*a;
		q=(-b-sqrt(delta))/2*a;
	
		i++;
	}
	cout<<"\n\nN rozklada sie na p rowne :"<<p;
	cout<<"\nOraz na q rowne : "<<q;
	cout<<"\nWspolczynnik deszyfracji wynosi: ";
	cout<<redukty[i-1].d;
}

int main()
{
	long long int e, N;
    vector<int> wektor;
    vector<redukt> redukty1;

    cout<<"Wpisz wartosc wspolczynnika szyfracji e= ";
    cin>>e;
   
    cout<<"Wpisz wartosc N= ";
    cin>>N;

	cout<<"Ulamek lancuchowy ";
    wektor=ulamek(e , N);
    cout<<"\nRedukty ";
    redukty1=utworz_redukty(wektor);
    rownanie( e, N, redukty1);

    return 0;
	
	
}

