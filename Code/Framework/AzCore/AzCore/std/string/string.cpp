#include <AzCore/std/string/string.h>

namespace AZStd
{

static std::string format_arg(const char* formatStr, va_list argList)
{
    std::string result;
    // On Windows, AZ_TRAIT_USE_SECURE_CRT_FUNCTIONS is set, so azvsnprintf calls _vsnprintf_s.
    // _vsnprintf_s, unlike vsnprintf, will fail and return -1 when the size argument is 0.
    // azvscprintf uses the proper function(_vscprintf or vsnprintf) on the given platform
    va_list argListCopy; //<- Depending on vprintf implementation va_list may be consumed, so send a copy
    va_copy(argListCopy, argList);
    const int len = azvscprintf(formatStr, argListCopy);
    va_end(argListCopy);
    if (len > 0)
    {
        result.resize(len);
        va_copy(argListCopy, argList);
        const int bytesPrinted = azvsnprintf(result.data(), result.size() + 1, formatStr, argListCopy);
        va_end(argListCopy);
        AZ_UNUSED(bytesPrinted);
        AZ_Assert(bytesPrinted >= 0, "azvsnprintf error! Format string: \"%s\"", formatStr);
        AZ_Assert(static_cast<size_t>(bytesPrinted) == result.size(), "azvsnprintf failed to print all bytes! Format string: \"%s\", bytesPrinted=%i/%i",
            formatStr, bytesPrinted, len);
    }
    return result;
}

std::string format_string(const char* formatStr, ...)
{
    va_list args;
    va_start(args, formatStr);
    std::string result = format_arg(formatStr, args);
    va_end(args);
    return result;
}

}
