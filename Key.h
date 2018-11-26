#include <Windows.h>
#include <string>

using namespace std;

void KeyToChar(int key, bool is_downCapsLock, bool is_en, bool is_DownShift, char* buffer);
string KeyToString(int key, bool is_downCapsLock, bool is_en, bool is_DownShift);

namespace detail{
    string KeyToString(int key, bool shift, bool en, bool CapsLock);

    char GetKeySymbol(int key, bool shift, bool en);

    char GetSymbolNumber(int key, bool en);

    void RegUp(string& str);
}
