#include "Stock1.c"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <random>
#include <cassert>


	//Constructor
	Stock::Stock(std::string fileName){
		//Read historical data from SPY.txt
		std::ifstream file(fileName);
		if(file.is_open()){
			for(int i = 0; i < T; ++i){
				file >> adjustedClose[i];
			}
		}
		//Calculate daily price delta
		//Calculate mu by using the expected return of past 12 months
		//Calculate sigma by using the volatility of past 12 months' returns
		double sum = 0;
		for (int i = 0; i < T; i++){
			if (i == 0){
				priceDelta[i] = 0;
			}
			else{
				priceDelta[i] = adjustedClose[i] / adjustedClose[i-1] - 1;
			}
			sum += priceDelta[i];
		}
		mu = sum/252;
		
		double variance = 0;
		for (int i = 0; i <T; i++){
			variance += pow(priceDelta[i] - mu,2);
		}
		sigma = sqrt(variance/252);
		
		//Annualize
		mu = mu * 252;
		sigma = sigma * sqrt(252.0);
	}
		
	void Stock::printHistoricalData(){
		for (int i = 0; i < T; i++)
		{
			std::cout << adjustedClose[i] << std::endl;
		}
	}
	
	//Brownian Motion
	//N: increments
	std::pair<double*, double*> Stock::Brownian(int seed, int N){
		double dt = 1./N;
		std::default_random_engine generator(seed);
		std::normal_distribution<double> normalDistr(0.0,1.0);
		double *b = new double[N];
		double *W = new double[N];
		for (int i = 0; i < N; i++){
			b[i] = normalDistr(generator) * sqrt(dt);
			//std::cout<< "b[i]"<< b[i] <<std::endl;
			if (i == 0){
				W[i] = b[i];
			}
			else{
				W[i] = W[i-1] + b[i];
			}
			//std::cout<< W[i] <<std::endl;	
		}
		return std::make_pair(b,W);
	}
	
	
	//S0: Spot price @ time 0
	//mu: Drift coefficient
	//W: Brownian motion
	//T: Time period
	//N: Number of increments
	std::pair<double*,double*> Stock::GBM(double S0, double mu, double sigma,double*W, double T, int N){
		
		double* t = new double[N+1];
		double step = (T - 0) / static_cast<int>(N);
		t[0] = 0;
		for ( int i = 0; i < N+1 ; ++i){
			t[i] = i * step;
			//std::cout <<t[i]<<std::endl;
		}
		
		double* S = new double[N+1];
		S[0] = S0;
		double drift, diffusion;
		double S_temp;
		
		//std::cout<< S[0] <<std::endl;	
		for (int i = 1; i < N+1; i ++){
			drift = (mu - 0.5 * pow(sigma,2) * t[i]);
			diffusion = sigma * W[i-1];
			S_temp = S0 * exp(drift + diffusion);
			S[i] = S_temp;
			//std::cout<< S[i] <<std::endl;	
		}
		return std::make_pair(S,t);
	}
	
	//Euler Maruyama Approximation
	//S0: Spot price @ time 0
	//mu: Dirft coefficient
	//sigma: Diffusion coefficient
	//T: Time period(Annualized)
	//N: number of increment
	//b: Brownian increments
	std::pair<double*, double*>	Stock::EM(double S0, double mu, double sigma, double* b, double T, int N){
		double* t = new double[N+1];
		double dt = (T - 0) / N; // EM step size
		t[0] = 0;
		for ( int i = 0; i < N+1 ; ++i){
			t[i] = i * dt;
		}
		// The approximation
		double* S= new double[N+1];
		S[0]=S0;
		for (int i =1; i< N+1;i++){
			S[i]=S[i-1]+S[i-1]*mu*dt+S[i-1]*sigma*b[i-1];
		}
		return std::make_pair(S,t);
	}
	
	// The linear solution (when sigma=0) of the simulated stock
	std::pair<double*,double*> Stock::LinearResult(double S0,double mu,double T, int N){
		double* t = new double[N+1];
		double dt = (1.0 - 0) / N; // EM step size
		for ( int i = 0; i < N+1 ; ++i){
			t[i] = i * dt;
		}
		double* S= new double[N+1];
		S[0]=S0;
		for (int i =1; i< N+1;i++){
			S[i]=S0+S0*t[i]*mu;
		}
		return std::make_pair(S,t);		 
	}
	
	//Print out the simulated values
	void Stock::PrintValues(double* A,double* B,int N){
		std::cout <<"Sample Path" << std::endl;
		std::cout <<"time     Price" << std::endl;	
		for (int i = 0; i < N+1; i ++){
			std::cout << A[i] << "     "<<B[i]<< std::endl;
		}
	}
	
	//Return the predicted price of both GBM and Euler Maruyama Approximation
	double Stock::simulate(int N,double seed){
		double T = 1.0;
		auto BM = this ->Brownian(seed,N);
		double* b = BM.first;
		double* W = BM.second;
	
		auto GBMResults = this->GBM(this->adjustedClose[251],this->mu,this->sigma,W,T,N);
		double* S1 = GBMResults.first;
		
		auto EMResults = EM(this->adjustedClose[251],this->mu,this->sigma, b, T, N);
		double* S2 = EMResults.first;
		
		//Return the error
		return fabs(S2[N]-S1[N]);
	}
	// Return the predicted final day price of GBM

	
	//Perform the simulations to understand the relationship between the Euler Maruyama 
	//Method's accuracy and its step sizes.
	
	void Stock::simulation(){
		double* simulationResult = new double[10];
		std::ofstream write_output("simulationResults.dat");
		//Check if the file is opened
		assert(write_output.is_open());
		std::cout<< "N         Step Size         Average Error"<<std::endl;
		for (int i = 1; i < 11; i ++){
			double temp;
			double sum = 0;
			double result;
			for (int j = 0; j < 10000; j ++){
				temp = this->simulate(i,j);
				
				sum += temp;
			}
			simulationResult[i] = sum / 10000;
			std::cout<< i << "            "<<1.0/i<< "            "<<simulationResult[i]<<std::endl;
			write_output << i << "            "<< 1.0/i << "            "<<simulationResult[i]<< "\n";
		}
	}

class Option: public Stock// Class option inheriated from class stock
{
public:
	using Stock::LinearResult;
	double K;// Strike Price
	double r;// Risk- free interest rate
	double T;// Expiry data(1)
	double S;//Current Stock Price
	double S0;
	Option(std::string fileName,double S0_input,double K_input, double r_input, double T_input):Stock(fileName){
		S0 = S0_input;
		K = K_input;
		r = r_input;
		T = T_input;
		auto linearresult = LinearResult(S0,mu,T,100);
		S = linearresult.first[100];
	}
	//Standard normal probability desity function
	double norm_pdf(const double x){
		return (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x);
	}
	
		
	//An approxiamtion to the cumulative distribution function
	//For the standard normal distribution
	double norm_cdf(const double x){
		double k = 1.0/(1.0+0.2316419*x);
		double k_sum = k*(0.319381530+k*(-0.356563782+k*(1.781477937+k*(-1.821255978+k*1.330274429))));
		
		if(x>=0.0){
			return (1.0-(1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x)*k_sum);
		}
		else {
			return 1.0-norm_cdf(-x);
		}
	}
	
	//The formula of d1 and d2, d_j for j={1,2}, This term appears in the closed form solution for the European call or put price
	double d_j(const int j){
		return (log(S/K)+(r+pow(-1,j-1)*0.5*sigma*sigma)*T)/(sigma*(pow(T,0.5)));
	}
	
	//Calculate the European call price thourgh the Black-Scholes formula
	double BS_Call_price(){
		return S*norm_cdf(d_j(1))-K*exp(-r*T)*norm_cdf(d_j(2));
	}

};	

class Greeks: public Option// The class greeks that derived from option
{
public:
	using Option::norm_pdf;
	using Option::norm_cdf;
	using Option::d_j;
	Greeks(std::string fileName,double S0,double K_input, double r_input, double T_input):Option(fileName,S0,K_input, r_input, T_input){}	
//Calculate the European call Delta
	double call_delta(){
		double result = norm_cdf(d_j(1));
		std::cout<<"Delta: "<< result<<std::endl;
		return result;
	}	 
	
	//Calculate the European call Gamma
	double call_gamma(){
		double result = norm_pdf(d_j(1))/(S*sigma*sqrt(T));
		std::cout<<"Gamma: "<< result<<std::endl;
		return result;
	}
	
	//Calculate the European call Vega 
	double call_vega(){
		double result =  S* norm_pdf(d_j(1))/sqrt(T);
		std::cout<<"Vega: "<< result<<std::endl;
		return result;
	} 
	 
	 //Calculate the European call Theta
	double call_theta(){
		double result = -(S* norm_pdf(d_j(1))*sigma)/(2*sqrt(T))-r*K*exp(-r*T)* norm_cdf(d_j(2));
		std::cout<<"theta: "<< result<<std::endl;
		return result;
	}

	//Calculate the European call Rho
	double call_rho(){	
		double result = K*T*exp(-r*T)*norm_cdf(d_j(2));
		std::cout<<"Rho: "<< result<<std::endl;
		return result;
	}
	
};


	
int main(int argc, const char * argv[])
{
	double S0 = 100;
	//double mu = 0.05;
	//double sigma = 0.2;
	double K = 110;
	double T=1;
	double r=0.04;
	std::string fileName = "SPY.txt";

	Option option1(fileName,S0,K,r,T);
	double call = option1.BS_Call_price();
	std::cout<<"Call Price: "<<call<<std::endl;
	
	Greeks greeks1(fileName,S0,K,r,T);
	double call_delta = greeks1.call_delta();
	double call_gamma = greeks1.call_gamma();
	double call_vega = greeks1.call_vega();
	double call_theta = greeks1.call_theta();
	double call_rho = greeks1.call_rho();
	
	double OptionPrice[100];
	double StockPrice[100];
	double OptionDelta[100];
	
	double stockprice_0 = 100;
	for(int i =0;i<100;i++){
		StockPrice[i] = stockprice_0+ i*0.5;
		Option option(fileName,StockPrice[i],K,r,T);		
		OptionPrice[i] = option.BS_Call_price();
		Greeks greeks(fileName,StockPrice[i],K,r,T);
		OptionDelta[i] = greeks.call_delta();
	}
	
	//Create a file option delta
	std::ofstream writeoutput_Delta("Option_Delta.dat");
	assert(writeoutput_Delta.is_open());
	for(int i =0; i<100;i++){
		writeoutput_Delta<<StockPrice[i]<<"   "<<OptionPrice[i]<<std::endl;
	}
	
	//Create a file option gamma
	std::ofstream writeoutput_Gamma("Option_Gamma.dat");
	assert(writeoutput_Gamma.is_open());
		for(int i =0; i<100;i++){
		writeoutput_Gamma<<StockPrice[i]<<"   "<<OptionDelta[i]<<std::endl;
	}
}
	