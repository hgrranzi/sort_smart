/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "checker.h"

int	press_key(int key, t_data *data)
{
	if (key == 35)
		data->pause = 1;
	if (key == 49)
		data->pause = 0;
	if (key == 124 || key == 49)
		data->play = 1;
	if (key == 125)
		data->speed_delay = 1;
	else if (key == 126)
		data->speed_delay = 0;
	if (key == 53)
		exit(0);
	return (0);
}
