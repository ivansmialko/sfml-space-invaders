#include "CONSTANTS.h"

int mainOld() {

	srand(time_t(time(0)));

	int res = 1;

	while (res != 0)
	{
		if (res == 1) {
			res = menu();
		}

		else if (res == 2) {
			if (game() == 8373) {
				end();
			}
			else {
				res = game();
			}
		}
		else if (res == 3) {
			res = settin();
		}
		else if (res == 4) {
			res = 0;
		}
	}

	system("exit");

	return 0;

}