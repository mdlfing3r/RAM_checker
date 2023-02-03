	#pragma once
	#include <bitset>

	int bit_state = 0b00000000;
	int true_bit_state = bit_state;
	int* bit_pntr = &bit_state;
	int max_bit_state = 0b11111111;


	int bit_direction = 0b00000000;
	int* bit_direction_pntr = &bit_direction;
	

	int bit_mask  = 0b00000001;
	
	bool power_state = 0;
	bool *power_state_pntr = &power_state;  //
	bool direction; //0 - read, 1 - write


	void set_pin_dir(bool dir, int &chan, int &bit_drctn) { // dir - направлени (0/1)  &chan - адрес переменной содержащей указатель на бит, 
															//&bit_drtcn - адрес переменной содержащей указатель на направление битов
		dir ? bit_drctn = bit_drctn | (1 << chan) : bit_drctn = bit_drctn | (0 << chan);
		std::cout <</*"\'" << dir << "\'" << " set at dirrection of " << chan << " bit, " <<*/ "total direction state is " << std::bitset<8>(bit_drctn) << std::endl;
	}; 

	void write_pin(int val, int &chan) {   //записать val в chan-ный бит bit_state
		bit_mask = val;
		*bit_pntr = *bit_pntr | bit_mask << chan;
		std::cout << "Total bit_state is " << std::bitset<8>(*bit_pntr) << std::endl;// << byte_state;
		
	}

	int read_pin(int chan) { //прочитать chan-ный бит у bit_state
		//std::cout << "reading now..." << std::endl;
		//std::cout << "It`s OK ? (1 - YES, 0 - NO): ";
		//std::cout << ((bit_state << (8 - chan)) ? 1 : 0);
		//std::cout << std::bitset <8>(bit_state & (bit_mask << chan));
		std::cout << "Total bit_state at read_pin is " << std::bitset<8>(*bit_pntr) << std::endl;// << byte_state;
		std::cout << std::bitset <1>(*bit_pntr << (3 - chan) ? 1 : 0);
		return (*bit_pntr << (3 - chan)) ? 1 : 0;
	}

	void power_on(bool &p_state){ //НО В РЕЛИЗЕ В АРГУМЕНТЕ VOID
		p_state = 1;
		std::cout << "is switching on now" << std::endl;
		std::cout << "power state is " << power_state << std::endl;
	}
	
	void power_off(bool& p_state) {//НО В РЕЛИЗЕ В АРГУМЕНТЕ VOID
		p_state = 0;
		std::cout << std::endl << "is switching off now" << std::endl;
		std::cout << "power state is " << power_state << std::endl;
	}

	 