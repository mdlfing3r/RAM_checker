	
/*
	1645��1�� - ������ cy7c1019b � MT5C1009 (���������� ����� � ����� ��������)
	������ ������:
	� ���������� ���� 3 ���� ����������:
	- NCE(Not Chip Enable) - ��������� ���� �.�. ������� ���� ������ �� ������ ��������, � ����� ������ � �������, �������� ������� LOW
	- NWE(Not Write Enable) - ���������� ������, �������� ������� LOW
	- NOE(Not Output Enable) - ���������� ������ ������ � ����������, �������� ������� LOW

	������� ������� ������:

	|NCE|NWE|NOE|     Mode     |      D0-D7     |
	| H | X | X | Data storage | High Impedance |
	| L | H | L | Reading data |   Output data  |
	| L | H | H |   No output  | High Impedance |
	| L | L | H |  Write data  |   Input data   |
	| L | L | L |  Write data  |   Input data   |

	�.�. ��� ���������� ����������� ����� 3 ���� �����������

	������ �� ������ ��������� �����/������ (�� I/O0 �� I/O7)
	������������ � ���� / ����������� � �����, ���������  �� ��������� ������ (A0 - �16).
*/

	//  GPIOA_PIN_0 - !Power_pin (NCE) (out) (GPIO_out)
	//  GPIOA_PIN_1 - !Write_enable_pin (NWE) (GPIO_out)
	//  GPIOA_PIN_2 - !Output_enable_pin (NOE) (GPIO_out)
	// 
	//	GPIOA_PIN_3...GPIOA_PIN_10 - ���� ��� ������ ������ (GPIO_out)
	//  GPIOB_PIN_0...GPIOB_PIN_7 - ���� ��� ���������� ������ � ��� (GPIO_in)
	//  GPIOC & GPIOD - �������� ���� (GPIO_out)

	// Adrdess row = A0 - A9 (A0 pin connect to GPIOC_0 ... A9 pin connect to GPIOC_9)
	// Address column = A10 - A16 pins (A10 pin connect to GPIOD_0 ... A16 pin connect to GPIOD_6)	

#pragma once

	int bit_state_w = 0b00000000; //���������� ��������� �����
	int* bit_pntr_w = &bit_state_w; //��������� �� ���������� ��������� �����
	int bit_mask  = 0b10101010;

	//��������� ������ �� ����� ���
	void set_adress(int row, int column) { 					     
			switch (row)    
			{
			case 0: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET)
				break;
			}

			case 1: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
				break;
			}

			case 2: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
				break;
			}

			case 3: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
				break;
			}

			case 4: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
				break;
			}

			case 5: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
				break;
			}

			case 6: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
				break;
			}

			case 7: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
				break;
			}

			case 8: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
				break;
			}

			case 9: {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
				break;
			}
			}
			switch (column)
			{
			case 0: {
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
				break;
			}

			case 1: {
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
				break;
			}

			case 2: {
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
				break;
			}

			case 3: {
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
				break;
			}

			case 4: {
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
				break;
			}

			case 5: {
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
				break;
			}

			case 6: {
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
				break;
			}

			}
		}

	//���������� ����� ������ IO ������ ��� ||| set_pin_dir(0, 0) - ������;   set_pin_dir(1, 0) - ������
	void set_pin_dir(int dir, int chan ) { //�� ����� ��� �� ������ ������������ ����� ������ � ����� ������ ��� ��� ����� � ���������� ������� ������ ���
	 dir ? HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET), HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET), HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET;     
	}; 

	//�������� val � chan-��� ��� bit_state � �������� � chan-��� ��� ��� �������� val
	void write_pin(int val, int &chan) {   
	*bit_pntr_w = *bit_pntr_w | val << chan;
		switch (chan){
			case 0: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
				break;
			}

			case 1: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
				break;
			}

			case 2: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
				break;
			}

			case 3: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
				break;
			}

			case 4: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
				break;
			}

			case 5: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
				break;
			}

			case 6: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
				break;
			}

			case 7: {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
				break;
			}
		}
	}

	//��������� chan-��� ��� ���
	int read_pin(int chan) { 
			switch (chan)
			{
			case 0: {
				return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) ? 1 : 0;
				break;
			}

			case 1: {
				return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) ? 1 : 0;
				break;
			}

			case 2: {
				return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2) ? 1 : 0;
				break;
			}

			case 3: {
				return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) ? 1 : 0;
				break;
			}

			case 4: {
				return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4) ? 1 : 0;
				break;
			}

			case 5: {
				return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) ? 1 : 0;
				break;
			}

			case 6: {
				return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) ? 1 : 0;
				break;
			}

			case 7: {
				return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) ? 1 : 0;
				break;
			}
		}
	} 

	//��������� ���
	void power_on(){ 
		//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		std::cout << "is switching on now" << std::endl;
		std::cout << "power state is " << 1 << std::endl;
	}

	//���������� ���
	void power_off() {
		//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
		std::cout << "is switching off now" << std::endl;
		std::cout << "power state is " << 0 << std::endl;
	}

	//��������� ���� �� ������� pos �� ����� byte
	int getbit(int byte, int pos){
		return ((byte >> pos) & 1u);
	}
