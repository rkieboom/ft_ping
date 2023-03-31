#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <strings.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <unistd.h>

// Define the Packet Constants
// ping packet size
#define PING_PKT_S 64

// ping packet structure
typedef struct s_ping_pkt
{
	struct icmp header;
	char msg[PING_PKT_S-sizeof(struct icmp)];
}				t_ping_pkt;

typedef struct	s_list
{
	int		sockfd;
	char	*address;


	struct sockaddr_in		dest;
	t_ping_pkt				packet;
	struct msghdr			rply_hdr;
}				t_list;


//Getting the address ip
int		get_addr_info(t_list *list, char *address);

//Creating socket
int	create_socket(t_list *list);

//Sending packets
int sending_packets(t_list *list);

#endif
