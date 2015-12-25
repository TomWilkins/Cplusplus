/*
** showip.c -- show IP addresses for a host given on the command line
*/
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){

    // hints - actual variable that currently has empty value and an assigned memory address
    // *res - empty pointer with address
    // *p - empty pointer with address
    struct addrinfo hints, *res, *p;

    int status;
    char ipstr[INET6_ADDRSTRLEN];

    // requires hostname to be passed in
    if (argc != 2) {
        fprintf(stderr,"usage: showip hostname\n");
        return 1;
    }

    // memset fills a block of memory with 0s up to the size of hints,
    // effectively zero initialises
    memset(&hints, 0, sizeof hints);

    // gives hints to what it should expect
    hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
    hints.ai_socktype = SOCK_STREAM;

    // gets the address info of the host
    // passes the address of hints and address of res.
    // when ran the results are saved to memory and the pointer res holds that address
    if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP addresses for %s:\n\n", argv[1]);

    // loops over the results
    // use p as a temp pointer that points to the current result
    for(p = res;p != NULL; p = p->ai_next) {

        void *addr; // empty pointers
        char *ipver;


        // get the pointer to the address itself,
        // different fields in IPv4 and IPv6:
        if (p->ai_family == AF_INET) { // IPv4

            // points to the current result address struct
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;

            // points to the actual address value
            addr = &(ipv4->sin_addr);

            // assign value of pointer - could this not just be a variable?
            ipver = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        // convert the IP to a string and print it:
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);

        printf("  %s: %s\n", ipver, ipstr);
    }
    freeaddrinfo(res); // free the linked list
    return 0;
}