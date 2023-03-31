#include "header.h"

static uint16_t icmp_checksum(void *data, int len) {
	uint16_t *ptr = data;
	uint32_t sum = 0;

	while (len > 1) {
		sum += *ptr++;
		len -= 2;
	}

	if (len == 1) {
		sum += *(uint8_t *)ptr;
	}

	while (sum >> 16) {
		sum = (sum & 0xFFFF) + (sum >> 16);
	}

	return (uint16_t)(~sum);
}

static void	setup_packet(t_list *list)
{
	bzero(&list->packet, sizeof(list->packet));

	list->packet.header.icmp_type = ICMP_ECHO;
	list->packet.header.icmp_hun.ih_idseq.icd_id = getuid();
	list->packet.header.icmp_hun.ih_idseq.icd_seq = 0;
	list->packet.header.icmp_cksum = icmp_checksum(&list->packet, sizeof(list->packet));
}



int sending_packets(t_list *list)
{
	setup_packet(list);



	if (sendto(list->sockfd, &list->packet, sizeof(list->packet), 0, (struct sockaddr *)&list->dest, sizeof(list->dest)) < 0)
		return (dprintf(2, "Error sending packet!\n"), 1);


	return (0);
}
