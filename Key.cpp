#include "Key.h"

#define RANGE(begin, end) \
    (key >= begin && key <= end)

#define RETURN_CHAR_FROM(begin, end, name, ...) \
    if RANGE(begin, end){ \
        char chars_##name[] ={ __VA_ARGS__}; \
        return chars_##name[key - begin]; \
    }

#define SPEC_KEY(key, alias) case key: return #alias;

string KeyToString(int key, bool is_downCapsLock, bool is_en, bool is_DownShift){
    return detail::KeyToString(key, is_DownShift, is_en, is_downCapsLock);
}

namespace detail{
    string KeyToString(int key, bool shift, bool en, bool CapsLock){
        string str;
        switch (key){

        SPEC_KEY(VK_LBUTTON, "LBUTTON")
        SPEC_KEY(VK_RBUTTON, "RBUTTON")
        SPEC_KEY(VK_CANCEL, "CANCEL")
        SPEC_KEY(VK_MBUTTON, "MBUTTON")
        SPEC_KEY(VK_XBUTTON1, "XBUTTON1")
        SPEC_KEY(VK_XBUTTON2, "XBUTTON2")
        SPEC_KEY(VK_BACK, "BACKSPACE")
        SPEC_KEY(VK_TAB, "TAB")
        SPEC_KEY(VK_CLEAR, "CLEAR")
        SPEC_KEY(VK_RETURN, "ENTER")
        SPEC_KEY(VK_SHIFT, "SHIFT")
        SPEC_KEY(VK_CONTROL, "CONTROL")
        SPEC_KEY(VK_MENU, "MENU")
        SPEC_KEY(VK_PAUSE, "PAUSE")
        SPEC_KEY(VK_CAPITAL, "CAPITAL")
        SPEC_KEY(VK_HANGEUL, "HANGEUL")
        SPEC_KEY(VK_JUNJA, "JUNJA")
        SPEC_KEY(VK_FINAL, "FINAL")
        SPEC_KEY(VK_HANJA, "HANJA")
        SPEC_KEY(VK_ESCAPE, "ESCAPE")
        SPEC_KEY(VK_NONCONVERT, "NONCONVERT")
        SPEC_KEY(VK_ACCEPT, "ACCEPT")
        SPEC_KEY(VK_MODECHANGE, "MODECHANGE")
        SPEC_KEY(VK_SPACE, "SPACE")
        SPEC_KEY(VK_PRIOR, "PRIOR")
        SPEC_KEY(VK_NEXT, "NEXT")
        SPEC_KEY(VK_END, "END")
        SPEC_KEY(VK_HOME, "HOME")
        SPEC_KEY(VK_LEFT, "LEFT")
        SPEC_KEY(VK_UP, "UP")
        SPEC_KEY(VK_RIGHT, "RIGHT")
        SPEC_KEY(VK_DOWN, "DOWN")
        SPEC_KEY(VK_SELECT, "SELECT")
        SPEC_KEY(VK_PRINT, "PRINT")
        SPEC_KEY(VK_EXECUTE, "EXECUTE")
        SPEC_KEY(VK_SNAPSHOT, "SNAPSHOT")
        SPEC_KEY(VK_INSERT, "INSERT")
        SPEC_KEY(VK_DELETE, "DELETE")
        SPEC_KEY(VK_HELP, "HELP")
        SPEC_KEY(VK_LWIN, "LWIN")
        SPEC_KEY(VK_RWIN, "RWIN")
        SPEC_KEY(VK_APPS, "APPS")
        SPEC_KEY(VK_SLEEP, "SLEEP")
        SPEC_KEY(VK_NUMPAD0, "NUMPAD0")
        SPEC_KEY(VK_NUMPAD1, "NUMPAD1")
        SPEC_KEY(VK_NUMPAD2, "NUMPAD2")
        SPEC_KEY(VK_NUMPAD3, "NUMPAD3")
        SPEC_KEY(VK_NUMPAD4, "NUMPAD4")
        SPEC_KEY(VK_NUMPAD5, "NUMPAD5")
        SPEC_KEY(VK_NUMPAD6, "NUMPAD6")
        SPEC_KEY(VK_NUMPAD7, "NUMPAD7")
        SPEC_KEY(VK_NUMPAD8, "NUMPAD8")
        SPEC_KEY(VK_NUMPAD9, "NUMPAD9")
        SPEC_KEY(VK_MULTIPLY, "MULTIPLY")
        SPEC_KEY(VK_ADD, "ADD")
        SPEC_KEY(VK_SEPARATOR, "SEPARATOR")
        SPEC_KEY(VK_SUBTRACT, "SUBTRACT")
        SPEC_KEY(VK_DECIMAL, "DECIMAL")
        SPEC_KEY(VK_DIVIDE, "DIVIDE")
        SPEC_KEY(VK_F1, "F1")
        SPEC_KEY(VK_F2, "F2")
        SPEC_KEY(VK_F3, "F3")
        SPEC_KEY(VK_F4, "F4")
        SPEC_KEY(VK_F5, "F5")
        SPEC_KEY(VK_F6, "F6")
        SPEC_KEY(VK_F7, "F7")
        SPEC_KEY(VK_F8, "F8")
        SPEC_KEY(VK_F9, "F9")
        SPEC_KEY(VK_F10, "F10")
        SPEC_KEY(VK_F11, "F11")
        SPEC_KEY(VK_F12, "F12")
        SPEC_KEY(VK_F13, "F13")
        SPEC_KEY(VK_F14, "F14")
        SPEC_KEY(VK_F15, "F15")
        SPEC_KEY(VK_F16, "F16")
        SPEC_KEY(VK_F17, "F17")
        SPEC_KEY(VK_F18, "F18")
        SPEC_KEY(VK_F19, "F19")
        SPEC_KEY(VK_F20, "F20")
        SPEC_KEY(VK_F21, "F21")
        SPEC_KEY(VK_F22, "F22")
        SPEC_KEY(VK_F23, "F23")
        SPEC_KEY(VK_F24, "F24")
        SPEC_KEY(VK_NUMLOCK, "NUMLOCK")
        SPEC_KEY(VK_SCROLL, "SCROLL")
        //SPEC_KEY(VK_OEM_NEC_EQUAL, "OEM_NEC_EQUAL")
        //SPEC_KEY(VK_OEM_FJ_MASSHOU, "OEM_FJ_MASSHOU")
        SPEC_KEY(VK_CONVERT, "CONVERT")
        //SPEC_KEY(VK_OEM_FJ_TOUROKU, "OEM_FJ_TOUROKU")
        //SPEC_KEY(VK_OEM_FJ_LOYA, "OEM_FJ_LOYA")
        //SPEC_KEY(VK_OEM_FJ_ROYA, "OEM_FJ_ROYA")
        SPEC_KEY(VK_LSHIFT, "LSHIFT")
        SPEC_KEY(VK_RSHIFT, "RSHIFT")
        SPEC_KEY(VK_LCONTROL, "LCONTROL")
        SPEC_KEY(VK_RCONTROL, "RCONTROL")
        SPEC_KEY(VK_LMENU, "LALT")
        SPEC_KEY(VK_RMENU, "RALT")
        SPEC_KEY(VK_BROWSER_BACK, "BROWSER_BACK")
        SPEC_KEY(VK_BROWSER_FORWARD, "BROWSER_FORWARD")
        SPEC_KEY(VK_BROWSER_REFRESH, "BROWSER_REFRESH")
        SPEC_KEY(VK_BROWSER_STOP, "BROWSER_STOP")
        SPEC_KEY(VK_BROWSER_SEARCH, "BROWSER_SEARCH")
        SPEC_KEY(VK_BROWSER_FAVORITES, "BROWSER_FAVORITES")
        SPEC_KEY(VK_BROWSER_HOME, "BROWSER_HOME")
        SPEC_KEY(VK_VOLUME_MUTE, "VOLUME_MUTE")
        SPEC_KEY(VK_VOLUME_DOWN, "VOLUME_DOWN")
        SPEC_KEY(VK_VOLUME_UP, "VOLUME_UP")
        SPEC_KEY(VK_MEDIA_NEXT_TRACK, "MEDIA_NEXT_TRACK")
        SPEC_KEY(VK_MEDIA_PREV_TRACK, "MEDIA_PREV_TRACK")
        SPEC_KEY(VK_MEDIA_STOP, "MEDIA_STOP")
        SPEC_KEY(VK_MEDIA_PLAY_PAUSE, "MEDIA_PLAY_PAUSE")
        SPEC_KEY(VK_LAUNCH_MAIL, "LAUNCH_MAIL")
        SPEC_KEY(VK_LAUNCH_MEDIA_SELECT, "LAUNCH_MEDIA_SELECT")
        SPEC_KEY(VK_LAUNCH_APP1, "LAUNCH_APP1")
        SPEC_KEY(VK_LAUNCH_APP2, "LAUNCH_APP2")
        /*SPEC_KEY(VK_OEM_AX, "OEM_AX")
        SPEC_KEY(VK_OEM_102, "OEM_102")
        SPEC_KEY(VK_ICO_HELP, "ICO_HELP")
        SPEC_KEY(VK_ICO_00, "ICO_00")
        SPEC_KEY(VK_PROCESSKEY, "PROCESSKEY")
        SPEC_KEY(VK_ICO_CLEAR, "ICO_CLEAR")
        SPEC_KEY(VK_PACKET, "PACKET")
        SPEC_KEY(VK_OEM_RESET, "OEM_RESET")
        SPEC_KEY(VK_OEM_JUMP, "OEM_JUMP")
        SPEC_KEY(VK_OEM_PA1, "OEM_PA1")
        SPEC_KEY(VK_OEM_PA2, "OEM_PA2")
        SPEC_KEY(VK_OEM_PA3, "OEM_PA3")
        SPEC_KEY(VK_OEM_WSCTRL, "OEM_WSCTRL")
        SPEC_KEY(VK_OEM_CUSEL, "OEM_CUSEL")*/
        //SPEC_KEY(VK_OEM_ATTN, "OEM_ATTN")
        //SPEC_KEY(VK_OEM_FINISH, "OEM_FINISH")
        //SPEC_KEY(VK_OEM_COPY, "OEM_COPY")
        //SPEC_KEY(VK_OEM_AUTO, "OEM_AUTO")
        //SPEC_KEY(VK_OEM_ENLW, "OEM_ENLW")
        //SPEC_KEY(VK_OEM_BACKTAB, "OEM_BACKTAB")
        SPEC_KEY(VK_ATTN, "ATTN")
        SPEC_KEY(VK_CRSEL, "CRSEL")
        SPEC_KEY(VK_EXSEL, "EXSEL")
        SPEC_KEY(VK_EREOF, "EREOF")
        SPEC_KEY(VK_PLAY, "PLAY")
        SPEC_KEY(VK_ZOOM, "ZOOM")
        SPEC_KEY(VK_NONAME, "NONAME")
        SPEC_KEY(VK_PA1, "PA1")
        SPEC_KEY(VK_OEM_CLEAR, "OEM_CLEAR")

                 default:
            //NUMBERS
            if RANGE(0x30, 0x39){
                if (shift)
                    str += GetSymbolNumber(key, en);
                else
                    str += key;
                return str;
             //CHARS
            }else if (RANGE(0x41, 0x5A) || RANGE(VK_OEM_1, VK_OEM_8)){
                str += GetKeySymbol(key, shift, en);

                if (shift || (!shift && (CapsLock & 1)))
                    RegUp(str);

                return str;
            }

            return to_string(key);
		}
	}

    char GetKeySymbol(int key, bool shift, bool en){

        if (!en){
            RETURN_CHAR_FROM(0x41, 0x5A,
                        RUSSIAN_SYMBOLS,
                        'ô', 'è', 'ñ', 'â',  'ó', 'à', 'ï', 'ð',
                        'ø', 'î', 'ë', 'ä',  'ü', 'ò', 'ù', 'ç',
                        'é', 'ê', 'û', 'å',  'ã', 'ì', 'ö', '÷', 'í', 'ÿ');


            //VK_OEM_3 = 0xC0 <-1A-> VK_OEM4 = 0xDB
            //remove gup
            if (key >= 219){
                key = key - 26;
            }

            if (!shift){
                RETURN_CHAR_FROM(VK_OEM_1, VK_OEM_8,
                            OTHER_RUSSIAN_SYMBOLS_UP_SHIFT,
                            'æ', '=', 'á', '-', 'þ', '.',
                            '¸', 'õ', '\\', 'ú', 'ý', '@');
            }else{
                RETURN_CHAR_FROM(VK_OEM_1, VK_OEM_8,
                            OTHER_RUSSIAN_SYMBOLS_DOWN_SHIFT,
                            'Æ', '=', 'Á', '_', 'Þ', ',',
                            '¨', 'Õ', '/', 'Ú', 'Ý', '$');
            }

        }else{
            if RANGE(0x41, 0x5A){
                return key + 32;
            }

            //VK_OEM_3 = 0xC0 <-1A-> VK_OEM4 = 0xDB
            //remove gup
            if (key >= 219){
                key = key - 26;
            }

            if (!shift){
                RETURN_CHAR_FROM(VK_OEM_1, VK_OEM_8,
                            OTHER_ENGLISH_SYMBOLS_UP_SHIFT,
                            ';', '=', ',', '-', '.', '/',
                            '`', '[', '\\', ']', '\'', '@');
             }else{
                RETURN_CHAR_FROM(VK_OEM_1, VK_OEM_8,
                            OTHER_ENSGLISH_SYMBOLS_DOWN_SHIFT,
                            ':', '+', '<', '_', '>', '?',
                            '~', '{', '|', '}', '"', '%');
             }
        }

        return key;
    }

    char GetSymbolNumber(int key, bool en){

        if (en){
            RETURN_CHAR_FROM(0x30, 0x39,
                         NUMBER_SYMBOLS_ENGLISH,
                         ')', '!', '@', '#', '$',
                         '%', '^', '&', '*', '(');

        }else{
            RETURN_CHAR_FROM(0x30, 0x39,
                         NUMBER_SYMBOLS_RUSSIAN,
                         ')', '!', '"', '¹', ';',
                         '%', ':', '?', '*', '(');
        }


        return key;
    }

    void RegUp(string& str){
		for (int i = 0; i < str.length(); i++){
            if (str[i] >= 'à'&&str[i] <= 'ÿ')
                str[i] += ('À' - 'à');
            else
            if (str[i] >= 'a'&&str[i] <= 'z')
                str[i] -= 32;
        }
	}
}

