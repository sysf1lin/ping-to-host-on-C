#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Only Linux

void startPing(char goPing[], char *hostname);

void startWhois(char *hostname);

int main()
{
	char *hostname;
	printf("Please input IP address or Domain:\n");
	scanf("%s", hostname);

	char *goPing;
	startPing(goPing, hostname);
		
	printf("Do you see more info on the Host? y/n \n");
	getchar();
		char literalCase = getchar();
			switch(literalCase){
				case 'y' : startWhois(hostname); break;
				case 'n' : printf("\nSee you :)\n"); break;
				default: printf("Don`t current data! Please repeat!\n");
			}

	return 0;
}

void startPing(char goPing[], char *hostname){
		
	char command[50] = "/bin/ping -c ";

	// printf("Please input IP address or Domain:\n");
	// scanf("%s", hostname);

	char sendPackets[3];
	printf("Please enter how many packets to send?\n");
	scanf("%s", sendPackets);

	strcat(sendPackets, " ");
	strcat(command, sendPackets);

	strcat(command, hostname);
	
	system(command);
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}


void startWhois(char *hostname){

	char whois[30] = "whois ";
	strcat(whois, hostname);

	system(whois);

	char result_console[]=" > whois_result.txt";
	strcat(whois, result_console);
	
	system(whois);
	printf("\nGoodbye! \n");
}
