
# Russian Word Syllabification Library

This C++ library provides functions to transform Russian words (in `std::wstring` and `wchar_t*` formats) into syllable-separated words. Additionally, the library includes a function to verify if a word contains only Russian letters.

## Features

- **Syllabification**: Split Russian words into their syllabic components, supporting both `std::wstring` and `wchar_t*` input formats.
- **Russian Character Validation**: Check whether a word contains only valid Russian letters.

## Usage

1. Include the header files in your project:
   ```cpp
   #include "syllable.h"
   ```

2. Use the syllabification and validation functions as needed. For example:
   ```cpp
   std::wstring word = L"пример";
   std::wstring syllabified = split_into_syllables(word);
   bool is_russian = is_russian_word(word);
   ```

## Installation

To use this library in your project, simply include the `syllable.cpp` and `syllable.h` files and compile them with your project.

## License

This project is licensed under the GNU General Public License - see the [LICENSE](LICENSE) file for details.
