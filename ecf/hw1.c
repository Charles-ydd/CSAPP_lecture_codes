#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int s)
{
    for(int j = 0;j < 10;j++)
	{
		for(int i = 0 ; i<5 ; i++)
		{
			write(1,"*",1);
			sleep(1);
		}	
		write(1,"\n",1);
	}
	exit(0);
}

int main()
{
	
	signal(SIGINT,sig_handler);
	while(1);
}
