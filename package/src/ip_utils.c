#include <ifaddrs.h>
#include <stdio.h>
#include <string.h>

void netDetails();

int main(int argc, char* argv[]){

    netDetails();
    
    return 0;
}


void netDetails(){
    struct ifaddrs* id;
    int val = getifaddrs(&id);

    printf("Network Interface Name: %s\n", id->ifa_name);
    printf("Network Address of %s: %d\n", id->ifa_name, id->ifa_addr);
    printf("Network data: %d\n", id->ifa_data);
    printf("Socket data: %c\n", id->ifa_addr->sa_data);
}