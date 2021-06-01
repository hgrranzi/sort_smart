/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

int	press_key(int key, t_data *data)
{
	if (key == 112)
		data->pause = 1;
	if (key == 32)
		data->pause = 0;
	if (key == 65363 || key == 32)
		data->play = 1;
	if (key == 65364)
		data->speed_delay = 1;
	else if (key == 65362)
		data->speed_delay = 0;
	if (key == 65307)
		exit(0);
	return (0);
}
