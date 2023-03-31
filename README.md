# ft_ping
**ft_ping** is a custom implementation of the classic network utility ping for the 42 School project. The goal of this project is to create a tool that sends ICMP Echo Request packets to a specified IPv4 address or hostname and listens for ICMP Echo Reply packets. This utility is used to measure the round-trip time and packet loss for packets sent to a target host, providing a simple way to test network connectivity.

## Features

Written in C, following the 42 School project guidelines
Uses a limited set of standard library functions, as per project requirements
Handles both IPv4 addresses and hostnames (without performing DNS resolution in the packet return)
Supports the -v and -h command-line options

## Usage

To compile the project, run the provided Makefile:
```
make
```

This will generate the ft_ping executable. You can use this program by providing an IPv4 address or hostname as a parameter:
```
./ft_ping <IPv4_address_or_hostname>
```

For additional options, you can use the -v (verbose) or -h (help) flags:
```
./ft_ping -v <IPv4_address_or_hostname>
./ft_ping -h
```

## Allowed functions
- getpid
- getuid
- getaddrinfo
- freeaddrinfo
- gettimeofday
- inet_ntop
- inet_pton
- exit
- signal
- alarm
- setsockopt
- recvmsg
- sendto
- socket
- printf and its family
