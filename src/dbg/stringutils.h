#ifndef _STRINGUTILS_H
#define _STRINGUTILS_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

typedef std::string String;
typedef std::wstring WString;
typedef std::vector<String> StringList;
typedef std::vector<WString> WStringList;

class StringUtils
{
public:
    static StringList Split(const String & s, char delim, std::vector<String> & elems);
    static StringList Split(const String & s, char delim);
    static String Escape(const String & s);
    static bool Unescape(const String & s, String & result, bool quoted = true);
    static String Trim(const String & s, String delim = StringUtils::WHITESPACE);
    static String TrimLeft(const String & s, String delim = StringUtils::WHITESPACE);
    static String TrimRight(const String & s, String delim = StringUtils::WHITESPACE);
    static String PadLeft(const String & s, size_t minLength, char ch);
    static String Utf16ToUtf8(const WString & wstr);
    static String Utf16ToUtf8(const wchar_t* wstr);
    static WString Utf8ToUtf16(const String & str);
    static WString Utf8ToUtf16(const char* str);
    static void ReplaceAll(String & s, const String & from, const String & to);
    static void ReplaceAll(WString & s, const WString & from, const WString & to);
    static String sprintf(const char* format, ...);
    static WString sprintf(const wchar_t* format, ...);
    static String ToLower(const String & s);
    static bool StartsWith(const String & h, const String & n);
    static bool FromHex(const String & text, std::vector<unsigned char> & data, bool reverse = false);
    static String ToHex(unsigned long long value);
    static String ToHex(unsigned char* buffer, size_t size, bool reverse = false);
    static String ToCompressedHex(unsigned char* buffer, size_t size);
    static bool FromCompressedHex(const String & text, std::vector<unsigned char> & data);

    template<typename T>
    static String ToFloatingString(void* buffer)
    {
        auto value = *(T*)buffer;
        std::stringstream wFloatingStr;
        wFloatingStr << std::setprecision(std::numeric_limits<T>::digits10) << value;
        return wFloatingStr.str();
    }

    template<typename T>
    static String ToIntegralString(void* buffer)
    {
        auto value = *(T*)buffer;
        return ToHex(value);
    }

private:
    static const String WHITESPACE;
};

#endif //_STRINGUTILS_H