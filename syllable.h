#ifndef SYLLABLE_H_
#define SYLLABLE_H_
#include <cstddef>
#include <deque>
#include <stdexcept>
#include <cstring>

namespace syllable {
   

    wchar_t* copy_wstring_to_buffer(const std::wstring& input);




    std::wstring syllable_word(const std::wstring& word);
    void russianletters(const std::wstring& word);

    inline const wchar_t* syllable_word(const wchar_t* ptr) {
        return copy_wstring_to_buffer(syllable_word(std::wstring(ptr)));
    }
}
#endif