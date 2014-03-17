/**
 * @file main.cpp
 * @author  Bill Brouwer <whiskeyjulietb@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 * Copyright 2013 William J. Brouwer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @section DESCRIPTION
 *
 * A port of code developed by Fernando Pérez-Cruz; please cite:
 *
 * Sánchez-Fernández, M. and dePrado-Cumplido, M. and Arenas-García, J. and Pérez-Cruz, F.
 * SVM multiregression for nonlinear channel estimation in multiple-input multiple-output systems
 * IEEE Trans. Signal Proc., 52(8), 2298-2307, 2004
 */



#include <iostream>
#include "msvr.hpp"
#include "armadillo"
#include "utilities.hpp"
#include "msvr.hpp"


using namespace arma;

//a driver for MIMO svr
//data is column major

using namespace mimo_svr;

int main(int argc, char * argv[]){


	mat Xtest, Xtrain, Ytest, Ytrain;
	Xtrain.load(argv[1]);
	Xtest.load(argv[2]);
	Ytrain.load(argv[3]);
	Ytest.load(argv[4]);

	double param 	= mean_all(pdist(Xtest));
	double epsi 	= 2.0f,C = 5.0f, tol = 1e-20;

	msvr trainA(Xtrain,Ytrain,"rbf",C,epsi,param,tol);
	mat Ktest 	= k_mat(trans(Xtest),trans(Xtrain),"rbf",param);
	mat Ypred 	= Ktest*trainA.getBeta();

	double length = size(Ypred,0);
	mat diff = sqrt(sum(pow((Ypred-Ytest),2))/length);

	cout << "RMSE: " << endl;
	cout << diff << endl;
	cout << "Ypred: " << endl;
	cout << Ypred << endl;
	cout << "Ytest: " << endl;
	cout << Ytest << endl;
	
	return 0;

}
