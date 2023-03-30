#include "header.h"

int	create_socket(t_list *list)
{
	list->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	//Creating socket
	if (list->sockfd < 0)
		return (dprintf(2, "Couldn't create socket!\n"), 1);
	//setting destination information for later
	if (inet_pton(AF_INET, list->address, &list->dest) != 1)
		return (dprintf(2, "inet_pton failed!\n"), 1);

	return (0);
}
