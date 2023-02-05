#include "tester_contro.h"

int main() {
	int error_counter = 0; // ������� ������ ������

	power_on();
	set_pin_dir(1, 0);
	for (int row_b = 0; row_b < 1024; row_b++){
		for (int column_b = 0; column_b < 128; column_b++){
			set_adress(row_b, column_b);
			int temp_bit_mask = bit_mask;
			column_b % 2 == 0 ? bit_state_w = temp_bit_mask : bit_state_w = (temp_bit_mask << 1); // ��������� ��������, ������ � bit_state_w ��������� ������� �����
			for (int bit_num = 0; bit_num < 8; bit_num++)
			{	
				write_pin(getbit(bit_state_w, bit_num), bit_num);
				for (int delay_time = 0; delay_time < 300 * 1u; delay_time++);//��� ������ ���� �����, �� ����� 55 �� (����� ����� ������ ����������)
																			  //������������ �������� ��� delay_time ���������� ����������� ��� ������������� ��, ����� ��� ����� 300 
				
			}	
		}
	}

	for (int delay_time = 0; delay_time < 500 * 1u; delay_time++);//��� ������ ���� �����
																  //������������ �������� ��� delay_time ���������� ����������� ��� ������������� ��, ����� ��� ����� 500 
	//��������� ������															
	set_pin_dir(0, 0);
	for (int row_b = 0; row_b < 1024; row_b++) {
		for (int column_b = 0; column_b < 128; column_b++) {
			set_adress(row_b, column_b);
			int temp_bit_mask = bit_mask;
			column_b % 2 == 0 ? bit_state_w = temp_bit_mask : bit_state_w = (temp_bit_mask << 1); // ��������� ��������, ������ � bit_state_w ��������� ������� �����
			for (int bit_num = 0; bit_num < 8; bit_num++)
			{
				(read_pin(bit_num) != getbit(bit_state_w, bit_num)) ? error_counter++ : 0;
				for (int delay_time = 0; delay_time < 300 * 1u; delay_time++);//��� ������ ���� �����, �� ����� 55 �� (����� ����� ������ ����������)
																			  //������������ �������� ��� delay_time ���������� ����������� ��� ������������� ��, ����� ��� ����� 300 
			}
		}
	}
	power_off();

	return 0;
}