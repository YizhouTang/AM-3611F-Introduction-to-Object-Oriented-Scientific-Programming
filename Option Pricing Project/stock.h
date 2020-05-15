#ifndef STOCK_H
#define STOCK_H
#include<utility>
#include<iostream>
#include<string>

class Stock{

public:
	double mu;//Drift coefficient
	double sigma;//Diffusion coefficient
	int T = 252;//Time period
	double adjustedClose[252] = {};
	double priceDelta[252] = {};
	
	Stock(std::string fileName);
	void printHistoricalData();
	std::pair<double*, double*> Brownian(int seed, int N);
	std::pair<double*, double*> GBM(double S0, double mu, double sigma,double*W, double T, int N);	
	std::pair<double*, double*> EM(double S0, double mu, double sigma, double* b, double T, int N);
	std::pair<double*, double*> LinearResult(double S0,double mu,double T, int N);
	void PrintValues(double* A,double* B,int N);
	double simulate(int N,double seed)	;
	double simulate_final(int N, double seed);
	void simulation();
};

#endif	