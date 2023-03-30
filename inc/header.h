#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <strings.h>
# include <arpa/inet.h>
# include <stdlib.h> 

typedef struct	s_list
{
	int		sockfd;
	char	*address;

	struct sockaddr	dest;
}				t_list;


//Getting the address ip
int		get_addr_info(t_list *list, char *address);

//Creating socket
int	create_socket(t_list *list);

#endif
