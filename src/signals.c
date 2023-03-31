#include "header.h"

static void sigint()
{

}

static void sigabrt()
{

}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
		sigint();
	else if (signum == SIGABRT)
		sigabrt();
	exit(128 + signum);
}
