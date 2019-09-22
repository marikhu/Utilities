// http://www.drk.com.ar/code/get-mac-address-in-linux.php

#include <netdb.h>
#include <net/if.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/errno.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <stdio.h>

  
int main(int argc, char ** argv) {
  printf("A\n");

  struct ifreq ifr;
  int s;
  if ((s = socket(AF_INET, SOCK_STREAM,0)) < 0) {
    perror("socket");
    return -1;
  }
  printf("B\n");
  
  strcpy(ifr.ifr_name, argv[1]);
  if (ioctl(s, SIOCGIFHWADDR, &ifr) < 0) {
    perror("ioctl");
    return -1;
  }

  printf("C\n");
  
  unsigned char *hwaddr = (unsigned char *)ifr.ifr_hwaddr.sa_data;
  printf("%02X:%02X:%02X:%02X:%02X:%02X\n", hwaddr[0], hwaddr[1], hwaddr[2],
                                          hwaddr[3], hwaddr[4], hwaddr[5]);
  close(s);

struct if_nameindex *if_nidxs, *intf;

    if_nidxs = if_nameindex();
    if ( if_nidxs != NULL )
    {
        for (intf = if_nidxs; intf->if_index != 0 || intf->if_name != NULL; intf++)
        {
            printf("%s\n", intf->if_name);
        }

        if_freenameindex(if_nidxs);
    }


  return 0;
}
