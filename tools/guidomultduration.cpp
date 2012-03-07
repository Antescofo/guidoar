/*
	this file is automatically generated from template.cxx
	don't modify unles you're ready to loose your changes
*/

#include <iostream>
#include <sstream>
#include <vector>

#include "common.cxx"

#include "desc/guidomultduration.h"

//_______________________________________________________________________________
static void usage(char * name)
{
	cerr << "usage: " << basename(name) << " score  " << gArg  << endl;
	cerr << "       " << gDesc << endl;
	cerr << "       " << scoredesc << endl;
	cerr << "       " << gArg << ": " << gArgDesc  << endl;
	exit (-1);
}

//_______________________________________________________________________________
template <typename T> class operation
{
	typedef garErr (*TOperator)(const char*, T, ostream&);
	TOperator		fOperator;
	string			fScore;			// the score argument
	string			fScoreArg;		// to store the second score argument
	vector<string>	fScoreArgs;		// to store the second score argument
	T			fArg;
	string		fSdtIn;			// intended to share stdin
	

	bool readArg(const char* arg, int& value) const			{ return intVal (arg, value); }
	bool readArg(const char* arg, float& value) const		{ return floatVal (arg, value); }
	bool readArg(const char* arg, rational& value) const	{ return rationalVal (arg, value); }
	bool readArg(const char* arg, string& value)			{ return gmnVal (arg, value, fSdtIn); }
	bool readArg(const char* arg, const char*& value)		{
			if (gmnVal (arg, fScoreArg, fSdtIn)) {
				value = fScoreArg.c_str();
				return true;
			} 
			return false; 
		}

	public :
				 operation(TOperator op) : fOperator (op) {}
		virtual ~operation() {}
		
		// strict run method: expects exaclty 2 arguments
		bool strict_init (int argc, char* argv[]) {
			if (argc != 3) return false;
			if (!readArg (argv[1], fScore)) return false;
			if (!readArg (argv[2], fArg)) return false;
			return true;
		}
		
		// relaxed run method: takes more than 2 arguments but only strings args are supported
		bool init (int argc, char* argv[]) {
			if (argc < 3) return false;
			if (!readArg (argv[1], fScore)) return false;
			for (int i=2; i<argc; i++) {
				if (!readArg (argv[i], fScoreArg)) return false;
				fScoreArgs.push_back (fScoreArg);
			}
			return true;
		}
		// strict run method: _strict_init should be called before
		garErr strict_run (ostream& out)		{ return fOperator (fScore.c_str(), fArg, out); }
		
		// relaxed run method: init should be called before
		garErr  run (ostream& out)		{ 
			string score (fScore.c_str());
			for (int i=0; i<fScoreArgs.size(); i++) {
				stringstream sstr;
				garErr err = fOperator (score.c_str(), fScoreArgs[i].c_str(), sstr);
				if (err) return err;
				score = sstr.str();
			}
			out << score;
		}
};


//_______________________________________________________________________________
int main (int argc, char* argv[])
{
	operation<float> op (guidoVMultDuration);
	if (op.strict_init(argc, argv)) {
		garErr err = op.strict_run (cout);
		if (err != kNoErr) {
			error (err);
			return err;
		}
	}
	else usage (argv[0]);
	return 0;
}

