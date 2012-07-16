/*
 * gethostbyname.c
 *
 * I think Wietse posted these to postfix-users some years ago
 * I keep them around because sometimes it's useful to know what
 * these system calls are actually returning.
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

main(argc, argv)
int     argc;
char  **argv;
{
    struct hostent *hp;

    if (argc != 2) {
	fprintf(stderr, "usage: %s hostname\n", argv[0]);
	exit(1);
    }
    if (hp = gethostbyname(argv[1])) {
	printf("Hostname:\t%s\n", hp->h_name);
	printf("Aliases:\t");
	while (hp->h_aliases[0])
	    printf("%s ", *hp->h_aliases++);
	printf("\n");
	printf("Addresses:\t");
	while (hp->h_addr_list[0])
	    printf("%s ", inet_ntoa(*(struct in_addr *) * hp->h_addr_list++));
	printf("\n");
	exit(0);
    } else {
	fprintf(stderr, "host %s not found\n", argv[1]);
	exit(1);
    }
}
