#include "header.h"

int		get_addr_info(t_list *list, char *address)
{
	struct addrinfo hints, *res, *rp;

	bzero(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	if (getaddrinfo(address, NULL, &hints, &res) != 0)
		return (dprintf(2, "getaddrinfo failed!\n"), 1);
	
	for (rp = res; rp != NULL; rp = rp->ai_next) {
		struct sockaddr_in *temp = (struct sockaddr_in *)rp->ai_addr;
		char buf[1024];

		bzero(buf, sizeof(buf));
		inet_ntop(AF_INET, &temp->sin_addr, buf, 1024);
		printf("address=[%s]\n", buf);
		if (list->address)
			free(list->address);
		list->address = strdup(buf);
		if (!list->address)
			return (dprintf(2, "Malloc failed!\n"), 1);
	}
	return (freeaddrinfo(res), 0);
}
