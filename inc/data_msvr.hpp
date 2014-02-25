

#ifndef _DATA_SVR
#define _DATA_SVR

#include <boost/shared_array.hpp>
#include <boost/make_shared.hpp>

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace boost;
using namespace std;

namespace mimo_svr{
class data_msvr{


	private:
		int _dimx;
		int _dimy;	
		int _samples;

		float _tolerance;
		float _epsilon;
		float _C;


		//test/train data
		//mat _x;
		//mat _y;

		//any predictions
		//mat _pred;

	public:
		data_msvr(int dimx, 
				int dimy, 
				int samples,
				const char * indata,
				const char * outdata);

		//mat<float> getX(){
		//	return _x;
		//}
		//mat<float> getY(){
		//	return _y;
		//}

		friend ostream& operator<<(ostream &out, data_msvr& in);


		//yay smart arrays
		~data_msvr(){};



};
};
#endif
