#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

void lookupIP(int);
void lookupHost(int);

int main(int argc, char **argv)
{
	struct hostent *hp;
    	long    addr;
	int c;

 	if (argc != 3) {
		fprintf(stderr, "usage: %s i.p.addres\n", argv[0]);
		exit(1);
    	}

	while (--argc > 0 && (*++argv)[1] == '-')
		while (c = *++argv[1])
			(strcmp(c, "i") == 0) ?
				lookupIP(*argv[2]) : (strcmp(c, "h") == 0) ?
				lookupHost(*argv[2]) : usage();
 
}

void lookupIP(int host)
{
	long addr;
	addr = inet_addr(host);
    	if (hp = gethostbyaddr((char *) &addr, sizeof(addr), AF_INET)) {
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
    	}
	fprintf(stderr, "host %s not found\n", argv[1]);
	exit(1);
}

void lookupHost(args)
{

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
