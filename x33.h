#pragma once

#include<iostream>
#include<vector>
#include<string>

int null = NULL;

//a->b
//b->c
//c->d
//d->a

void cycle_4_clockwise(int& a, int& b, int& c, int& d) {
	int aux = b;
	int aux2 = c;
	int aux3 = d;
	int aux4 = a;
	b = aux4;
	c = aux;
	d = aux2;
	a = aux3;


}

//a->d
//d->c
//c->b
//b->a

void cycle_4_counterclockwise(int& a, int& b, int& c, int& d) {
	int aux = b;
	int aux2 = c;
	int aux3 = d;
	int aux4 = a;
	d = aux4;
	c = aux3;
	b = aux2;
	a = aux;
}

class x33
{
	int Peices_array[26];

public:

	x33() {
		//Creates a solved cube
		for (int i = 1; i < 26; i++) {
			Peices_array[i] = i;

		}
	}

	void turn(char direction) {
		switch (direction) {
		case 'R':
			cycle_4_clockwise(Peices_array[9], Peices_array[3], Peices_array[23], Peices_array[15]);
			cycle_4_clockwise(Peices_array[6], Peices_array[21], Peices_array[22], Peices_array[12]);
			break;
		case 'U':
			cycle_4_clockwise(Peices_array[1], Peices_array[3], Peices_array[9], Peices_array[7]);
			cycle_4_clockwise(Peices_array[2], Peices_array[6], Peices_array[8], Peices_array[4]);
			break;
		case 'r':
			cycle_4_counterclockwise(Peices_array[9], Peices_array[3], Peices_array[23], Peices_array[15]);
			cycle_4_counterclockwise(Peices_array[6], Peices_array[21], Peices_array[22], Peices_array[12]);
			break;
		case 'u':
			cycle_4_counterclockwise(Peices_array[1], Peices_array[3], Peices_array[9], Peices_array[7]);
			cycle_4_counterclockwise(Peices_array[2], Peices_array[6], Peices_array[8], Peices_array[4]);
			break;
		case 'F':
			cycle_4_clockwise(Peices_array[7], Peices_array[9], Peices_array[15], Peices_array[13]);
			cycle_4_clockwise(Peices_array[10], Peices_array[8], Peices_array[12], Peices_array[14]);
			break;
		case 'f':
			cycle_4_counterclockwise(Peices_array[7], Peices_array[9], Peices_array[15], Peices_array[13]);
			cycle_4_counterclockwise(Peices_array[10], Peices_array[8], Peices_array[12], Peices_array[14]);
			break;
		case 'L':
			cycle_4_clockwise(Peices_array[7], Peices_array[13], Peices_array[18], Peices_array[1]);
			cycle_4_clockwise(Peices_array[4], Peices_array[10], Peices_array[19], Peices_array[16]);
			break;
		case 'l':
			cycle_4_counterclockwise(Peices_array[7], Peices_array[13], Peices_array[18], Peices_array[1]);
			cycle_4_counterclockwise(Peices_array[4], Peices_array[10], Peices_array[19], Peices_array[16]);
			break;
		case 'D':
			cycle_4_clockwise(Peices_array[14], Peices_array[22], Peices_array[25], Peices_array[19]);
			cycle_4_clockwise(Peices_array[13], Peices_array[15], Peices_array[23], Peices_array[18]);
			break;
		case 'd':
			cycle_4_counterclockwise(Peices_array[14], Peices_array[22], Peices_array[25], Peices_array[19]);
			cycle_4_counterclockwise(Peices_array[13], Peices_array[15], Peices_array[23], Peices_array[18]);
			break;
		case 'B':
			cycle_4_clockwise(Peices_array[25], Peices_array[21], Peices_array[2], Peices_array[16]);
			cycle_4_clockwise(Peices_array[1], Peices_array[18], Peices_array[23], Peices_array[3]);
			break;
		case 'b':
			cycle_4_counterclockwise(Peices_array[25], Peices_array[21], Peices_array[2], Peices_array[16]);
			cycle_4_counterclockwise(Peices_array[1], Peices_array[18], Peices_array[23], Peices_array[3]);
			break;
		case 'M':
			cycle_4_counterclockwise(Peices_array[2], Peices_array[25], Peices_array[14], Peices_array[8]);
			cycle_4_counterclockwise(Peices_array[5], Peices_array[24], null/*Yellow Center*/, Peices_array[11]);
			break;
		case 'm':
			cycle_4_clockwise(Peices_array[2], Peices_array[25], Peices_array[14], Peices_array[8]);
			cycle_4_clockwise(Peices_array[5], Peices_array[24], null/*Yellow Center*/, Peices_array[11]);
			break;
		case 'E':
			cycle_4_clockwise(Peices_array[12], Peices_array[21], Peices_array[16], Peices_array[10]);
			cycle_4_clockwise(Peices_array[11], Peices_array[20], Peices_array[24], Peices_array[17]);
			break;
		case 'e':
			cycle_4_counterclockwise(Peices_array[12], Peices_array[21], Peices_array[16], Peices_array[10]);
			cycle_4_counterclockwise(Peices_array[11], Peices_array[20], Peices_array[24], Peices_array[17]);
			break;
		case 's':
			cycle_4_clockwise(Peices_array[4], Peices_array[6], Peices_array[22], Peices_array[19]);
			cycle_4_clockwise(Peices_array[5], Peices_array[20], null, Peices_array[17]);
			break;
		case 'S':
			cycle_4_counterclockwise(Peices_array[4], Peices_array[6], Peices_array[22], Peices_array[19]);
			cycle_4_counterclockwise(Peices_array[5], Peices_array[20], null, Peices_array[17]);
			break;
		case 'X':
			turn('R');
			turn('m');
			turn('l');
			break;
		case 'x':
			turn('r');
			turn('M');
			turn('L');
			break;
		case 'Y':
			turn('u');
			turn('e');
			turn('D');
			break;
		case 'y':
			turn('U');
			turn('E');
			turn('d');
			break;
		case 'z':
			turn('F');
			turn('S');
			turn('b');
			break;
		case 'Z':
			turn('f');
			turn('s');
			turn('B');
			break;
		}
	}

	void return_state() {
		for (int i = 1; i < 26; i++) {
			std::cout << Peices_array[i] << " ";
		}
		std::cout << std::endl;
	}

	bool is_solved() {
		for (int i = 1; i < 26; i++) {
			if (i != Peices_array[i])
				return false;
		}
		return true;
	}

	void scramble() {
		char input;
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
		std::cin >> input;
		turn(input);
	}

};


