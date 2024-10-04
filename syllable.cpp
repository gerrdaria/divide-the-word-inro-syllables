#include "syllable.h"
#include <cstddef>
#include <deque>
#include <stdexcept>
#include <unordered_set>
namespace syllable {


	wchar_t* copy_wstring_to_buffer(const std::wstring& input) {
		// Определяем размер буфера (60 элементов)
		const size_t buffer_size = 60;

		// Выделяем память для буфера (размер буфера + 1 для символа '\0')
		wchar_t* buffer = new wchar_t[buffer_size];

		// Проверяем, что длина входной строки не превышает размер буфера
		size_t input_length = input.size();
		if (input_length >= buffer_size) {
			input_length = buffer_size - 1; // Оставляем место для нуль-терминатора
		}

		// Копируем символы посимвольно из std::wstring в буфер
		for (size_t i = 0; i < input_length; ++i) {
			buffer[i] = input[i];
		}

		// Добавляем символ конца строки
		buffer[input_length] = L'\0';

		// Возвращаем указатель на буфер
		return buffer;
	}

	std::wstring syllable_word(const std::wstring& word) {
		const std::unordered_set<wchar_t> volwes_set = { L'а', L'е' ,L'ё' , L'и', L'о' , L'у', L'ы' , L'э' , L'ю' , L'я' ,
		 L'А' , L'Е' , L'Ё' , L'И' , L'О' , L'У' , L'Ы' , L'Э' , L'Ю' , L'Я' };
		const std::unordered_set<wchar_t> special_set = { L'Ь', L'ь', L'Ъ', L'ъ', L'Й', L'й' };
		size_t  prev_vowel = word.length();
		//find first vowel
		for (size_t i = 0; i < word.length(); i++) {
			if (volwes_set.find(word[i]) != volwes_set.end()) {
				prev_vowel = i;
				break;
			}

		}

		std::deque<size_t>hyphens;
		for (size_t i = prev_vowel + 1; i < word.length(); ++i)
		{
			auto iter = volwes_set.find(word[i]);
			if (iter != volwes_set.end()) {
				size_t a = prev_vowel;
				size_t b = i; // a, b - first, second vowel 
				if (b - a == 1) {
					if (special_set.find(word[b - 1]) != special_set.end()) hyphens.push_back(b + 1);
					else hyphens.push_back(b);
				}
				else if (b - a == 2) {
					if (special_set.find(word[b - 1]) != special_set.end()) hyphens.push_back(b);
					else hyphens.push_back(b - 1);
				}
				else
				{
					if (special_set.find(word[b - 1]) != special_set.end()) hyphens.push_back(a + 3);
					else hyphens.push_back(a + 2);
				}
				prev_vowel = i;
			}
		}

		std::wstring res_word(word);
		size_t counter = 0;
		for (size_t& i : hyphens)
		{
			res_word.insert(i + counter, L"-");
			counter++;
		}
		return res_word;
	}

	void russianletters(const std::wstring& word) {
		for (size_t i = 0; i < word.length(); ++i) {
			if (!(word[i] >= 1040 && word[i] <= 1103)) { //Русский алфавит в юникод в этом диапозоне
				throw std::invalid_argument("only rus letters!"); //исключение

			}
		}
	}

}