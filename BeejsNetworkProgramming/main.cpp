#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MYPORT "3490"  // the port users will be connecting to
#define BACKLOG 10     // how many pending connections queue will hold

using namespace std;

int main() {

    /* Correct order of system calls to bind a socket and listen for incoming
     * requests/ accept them
     *
     * getaddrinfo();
     * socket();
     * bind();
     * listen();
     * accept();
     */

    return 0;
}

void socketListen(){
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints, *res;
    int sockfd, new_fd;
// !! don't forget your error checking for these calls !

    // first, load up address structs with getaddrinfo():
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me
    getaddrinfo(NULL, MYPORT, &hints, &res);
// make a socket, bind it, and listen on it:
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    bind(sockfd, res->ai_addr, res->ai_addrlen);
    listen(sockfd, BACKLOG);
// now accept an incoming connection:
    addr_size = sizeof their_addr;
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
// ready to communicate on socket descriptor new_fd!
}

void makeSocketConnection(){
    struct addrinfo hints, *res;
    int sockfd;

    // first, load up address structs with getaddrinfo():
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("www.example.com", "3490", &hints, &res);

    // make a socket:
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // connect!
    connect(sockfd, res->ai_addr, res->ai_addrlen);
}

/**
 * This shows the most uptodate way to bind a socket
 */
void bindSocket(){

    struct addrinfo hints, *res;
    int sockfd;

    // first, load up address structs with getaddrinfo():
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;

    // Using this flag means it binds the socket to the current machines IP address
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

    getaddrinfo(NULL, "3490", &hints, &res);

    // make a socket:
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // bind it to the port we passed in to getaddrinfo():
    bind(sockfd, res->ai_addr, res->ai_addrlen);
}

/**
 * This is the old way to bind a port
 */
void bindSocketOld(){
    // !!! THIS IS THE OLD WAY !!!

    int port = 1500;
    int sockfd;
    struct sockaddr_in my_addr;
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);     // short, network byte order
    my_addr.sin_addr.s_addr = inet_addr("10.12.110.57");
    memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);
    bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr);
}

/**
 * An example call to get the address info
 */
void exampleOfGetaddrinfo(){
    int status;
    struct addrinfo hints;
    struct addrinfo *servinfo;  // will point to the results
    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

    if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }
    // servinfo now points to a linked list of 1 or more struct addrinfos
    // ... do everything until you don't need servinfo anymore ....
    freeaddrinfo(servinfo); // free the linked-list
}

/**
 * The common data-structures used in network connections that are found in
 * other libraries.
 */
void datastructures(){
    // holds the socket address information
    struct sockaddr {
        unsigned short    sa_family;    // address family, AF_xxx
        char              sa_data[14];  // 14 bytes of protocol address
    };

    // (IPv4 only--see struct in6_addr for IPv6)
    // Internet address (a structure for historical reasons)
    struct in_addr {
        uint32_t s_addr; // that's a 32-bit int (4 bytes)
    };

    // This structure makes it easy to reference elements of the socket address.
    struct sockaddr_in {
        short int          sin_family;  // Address family, AF_INET
        unsigned short int sin_port;    // Port number
        struct in_addr     sin_addr;    // Internet address
        unsigned char      sin_zero[8]; // Same size as struct sockaddr
    };

    struct in6_addr {
        unsigned char   s6_addr[16];   // IPv6 address
    };

    // (IPv6 only--see struct sockaddr_in and struct in_addr for IPv4)
    struct sockaddr_in6 {
        u_int16_t sin6_family;   // address family, AF_INET6
        u_int16_t sin6_port;     // port number, Network Byte Order
        u_int32_t sin6_flowinfo; // IPv6 flow information
        struct in6_addr sin6_addr;     // IPv6 address
        u_int32_t       sin6_scope_id; // Scope ID

    };

    // socket connection details
    struct addrinfo {
        int              ai_flags;     // AI_PASSIVE, AI_CANONNAME, etc.
        int              ai_family;    // AF_INET, AF_INET6, AF_UNSPEC
        int              ai_socktype;  // SOCK_STREAM, SOCK_DGRAM
        int              ai_protocol;  // use 0 for "any"
        size_t           ai_addrlen;   // size of ai_addr in bytes
        struct sockaddr *ai_addr;      // struct sockaddr_in or _in6
        char            *ai_canonname; // full canonical hostname
        struct addrinfo *ai_next;      // linked list, next node
    };

    struct sockaddr_storage {
        sa_family_t  ss_family;     // address family
        // all this is padding, implementation specific, ignore it:
        char      __ss_pad1[_SS_PAD1SIZE];
        int64_t   __ss_align;
        char      __ss_pad2[_SS_PAD2SIZE];
    };

}