#include "header.h"

int main(int argc, char **argv)
{
	t_list list;

	bzero(&list, sizeof(t_list));
	if (argc != 2)
		return (dprintf(2, "Not enough arguments!\n"), 1);
	if (get_addr_info(&list, argv[1]))
		return(2);
	if (create_socket(&list))
		return (3);
	return (0);
}