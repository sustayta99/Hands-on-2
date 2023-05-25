#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	
	double X[9] = {23,26,30,34,43,48,52,57,58};
	double Y[9] = {651,762,856,1063,1190,1298,1421,1440,1518};
	
	double sumx, sumy, sumxx, sumxy, sumx2, b_1, b_0, y_hat, YP, SSR = 0, SST = 0, RS, YH;
	int x;
	
	sumx = 0;
	sumy = 0;
	sumxx = 0;
	sumxy = 0;
	sumx2 = 0;
	
	for(int i=0; i<9; i++){
		
			
			sumx = sumx + X[i];
			sumy = sumy + Y[i];
			
			sumxy = sumxy + X[i] * Y[i];
			sumxx = sumxx + X[i] * X[i];
	}
	
	sumx2 = sumx * sumx;
	cout<<"Suma de x: "<< sumx <<endl;
	cout<<"Suma de y: "<< sumy <<endl;
	cout<<"Suma de las x's al cuadrado: "<< sumxx <<endl;
	cout<<"Suma de xy: "<< sumxy <<endl;
	cout<<"Resultado de al suma de x al cuadrado: "<< sumx2 <<endl;
	
	b_1 = (9 * sumxy - sumx * sumy) / (9 * sumxx - sumx2);
	b_0 = (sumy - b_1 * sumx) / 9;
	YP = sumy/9;

	//RS = 1 - (SSR/SST);
	
	cout<<"Valor de beta1: "<<b_1<<endl;
	cout<<"Valor de beta0 "<<b_0<<endl;
	cout<<"Promedio de y: "<<YP<<endl;

	cout<<"Ingrese el valor de x: ";
	cin>> x;
	
	y_hat = b_0 + b_1 * x;

	cout<<"El valor de y_hat es: "<<y_hat<<endl;

	for(int i=0; i<9; i++){

		//float SSTI, SSRI;

		SST = SST = Y[i]-YP;
		YH = b_0 + b_1 * X[i];
		SSR = SSR = Y[i] - YH;
		
	}

	SST = SST*SST;
	SSR = SSR*SSR;

	RS = 1 - (SSR/SST);

	cout<<"El valor de R-squered es: "<<RS<<endl;

	return 0;
}