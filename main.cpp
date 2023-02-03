/*
1645РУ1АУ - аналог cy7c1009b
Логика работы:
У микросхемы есть 3 пина управления:
	- NWE(Not Write Enable) - разрешение записи, активный уровень LOW
	- NCE(Not Chip Enable) - включение чипа т.е. перевод чипа памяти из режима хранения, в режим работы с памятью, активный уровень LOW
	- NOE(Not Output Enable) - разрешение вывода данных с микросхемы, активный уровень LOW

	Таблица режимов работы:

	|NCE|NWE|NOE|     Mode     |      D0-D7     |
	| H | X | X | Data storage | High Impedance |
	| L | H | L | Reading data |   Output data  |
	| L | H | H |   No output  | High Impedance |
	| L | L | H |  Write data  |   Input data   |
	| L | L | L |  Write data  |   Input data   |

	Т.е. для управления микросхемой нужны 3 пина контроллера

	Затем данные на восьми контактах ввода/вывода (от I/O0 до I/O7)
	записывается в место, указанное на контактах адреса (A0 - А16).







*/
#include <iostream>
#include "tester_contro.h"

int main() {
	int current_bit;
	int current_bit_state;
	int* current_bit_pntr = &current_bit;

	int current_dir_bit_state = 0;

	power_on(*power_state_pntr);
	
	for (int i = 0; i < 3; i++) {
		getchar();

		system("CLS");
		std::cout << "enter the direction of " << i << " bit" << std::endl;
		std::cin >> current_dir_bit_state;
		set_pin_dir(current_dir_bit_state, i, *bit_direction_pntr);

		std::cout << std::endl << "enter the " << i << " bit state" << std::endl;
		std::cin >> current_bit_state;
		write_pin(current_bit_state, i);

		getchar();

	}
	getchar();

	std::cout << " Press any key to start a error finding process " << std::endl;
	
	for (int i = 0; i < 3; i++) {
		read_pin(i);
	}
		//read_pin(*current_bit_pntr);
	//	current_bit_state = i % 2;
		//(*current_bit_pntr = (*current_bit_pntr) +1);
		//std::cout << std::endl;
	//}

	//std::cout << " Total bit state is " << std::bitset<8>(bit_state);


	getchar();
	getchar();

	power_off(*power_state_pntr);



	getchar();

	getchar();
	return 0;
}