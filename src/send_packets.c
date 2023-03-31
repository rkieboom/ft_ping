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

static void	setup_packet(t_list *list, struct iovec *iov, char *recv_buffer)
{
	strcpy(list->packet.msg, "Dit is een hele mooie line4343!");
	list->packet.header.icmp_type = ICMP_ECHO;
	list->packet.header.icmp_hun.ih_idseq.icd_id = getuid();
	list->packet.header.icmp_hun.ih_idseq.icd_seq = 0;
	list->packet.header.icmp_cksum = icmp_checksum(&list->packet, sizeof(list->packet));

	iov->iov_base = recv_buffer;
	iov->iov_len = 1024;

	list->rply_hdr.msg_name = &list->dest;
	list->rply_hdr.msg_namelen = sizeof(list->dest);
	list->rply_hdr.msg_iov = iov;

	//1 because its an array of 1
	list->rply_hdr.msg_iovlen = 1;
}



int sending_packets(t_list *list)
{
	int bytes = 0;
	struct iovec iov[1];
	char recv_buffer[1024];

	setup_packet(list, iov, recv_buffer);


	if (sendto(list->sockfd, &list->packet, sizeof(list->packet), MSG_DONTWAIT, (struct sockaddr *)&list->dest, sizeof(list->dest)) < 0)
		return (dprintf(2, "Error sending packet!\n"), 1);

	if ((bytes = recvmsg(list->sockfd, &list->rply_hdr, 0)) < 0)
		return (dprintf(2, "Error receiving packet!\n"), 1);
	printf("Received %i bytes.\n", bytes);
	return (0);
}
