//Wentao Zhu 1600012785
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN (1 << 10)
#define For(i,a,b) for(long long i=a; i<=b; i++)

char path[MAXLEN];
char buf[MAXLEN];
long long begin,end;
long long flag;

int main()
{
	pid_t pid = getpid();
	sprintf(path, "/proc/%d/maps", pid);	//Find mapping table
	FILE* fp = fopen(path, "r");		
	while(fgets(buf, MAXLEN - 1, fp) != NULL)
	{	
		sscanf(buf, "%llx-%llx", &begin, &end);
		begin >>= 12;
		end >>= 12;
		// VP = addr/4KB
		For(i,begin,end)
		if (i!=flag) 
		{
			printf("VP: 0x%llx\n", i);
			flag = i;
		} 
	}
	fclose(fp);
	return 0;
}