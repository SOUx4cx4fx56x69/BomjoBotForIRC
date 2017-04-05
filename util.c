#include "AntiQubick.h"
#include "util.h"
#include "time.h"
#include <stdio.h>
#include <stdarg.h>
void 
error(const char *msg)
{
    fprintf(stderr,msg);
    puts("");
    exit(-1);
}
void
noSpoof(char*buffer,char*ping)
{
while(*buffer != ':' && *buffer) buffer++;
if(*buffer == ':')
 while(*buffer)
  *ping++=*buffer++;
else
 *ping='\0';
}
void 
grepPing(char * buffer,char*ping)
{
while(*buffer != 'P' 
|| *(buffer+1) != 'I'
|| *(buffer+2) != 'N'
|| *(buffer+3) != 'G'
&& *buffer) //shitcode :o
{
printf("%c",*buffer);
 *buffer++;
}
buffer=buffer+5;
if(*buffer == ':')
 while(*buffer!='\n')
  *ping++=*buffer++;
 else 
  *ping='\0';
}//end

unsigned int 
CountString(FILE*file)
{
unsigned int count=0;
char ch;
if(file == NULL) error("CRITICAL_ERROR: Not readable file");
while( (ch=fgetc(file)) != EOF)
 if(ch=='\n') count++;
return count;
}

void
getRandomStringFromFie(char*file,char*buffer)
{
FILE*trollFile=fopen(file,"r");
if(trollFile == NULL) error("CRITICAL_ERROR: No can find this file troll.txt in the directory");
srand ( time(NULL) );
unsigned auto strings = CountString(trollFile);
unsigned auto randomString = rand() % strings;
unsigned auto count=0;
char ch;
rewind(trollFile);
while((ch=fgetc(trollFile)) !=EOF)
{
if(ch=='\n')count++;
if(count == randomString)
{
while((ch=fgetc(trollFile)) !='\n')*buffer++=ch;
*buffer++='\0';
break;
} 
}
close(trollFile);
}

void 
Troll(int socket)
{
if(FORFUCKOFF < NEEDFORFUCKOFF)
{
char tmp[SIZEBUFFER];
char buffer[SIZEBUFFER/2];
bzero(tmp,SIZEBUFFER);
bzero(buffer,SIZEBUFFER/2);
getRandomStringFromFie("troll.txt",buffer);
sprintf(tmp,"PRIVMSG %s %s", DEFAULT_CHANNEL,buffer );
writeTo(socket,tmp);
}
}

void
QUIT(int socket)
{
writeTo(socket, "QUIT leaving");
raise(9);
}
void
_setSetting(char*setting,char*set)
{
if(strcmp(setting,"CHANNEL") == 0)
 strcpy(DEFAULT_CHANNEL,set);
if(strcmp(setting,"owner") == 0)
 strcpy(OWNER,set);
if(strcmp(setting,"OWNER_NICK") == 0)
 strcpy(OWNER_NICK,set);
if(strcmp(setting,"NEEDFORDISABLE") == 0)
 NEEDFORFUCKOFF=(unsigned long long)atoi(set);
if(strcmp(setting,"TIMETROLL") == 0)
 TIMETROLL=(unsigned int)atoi(set);
if(strcmp(setting,"TIMEDW") == 0)
 TIMEDW=(unsigned int)atoi(set);
if(strcmp(setting,"MAXPOWN") == 0)
 MAXPOWN=(unsigned long long)atoi(set);
if(strcmp(setting,"MAXNUM") == 0)
 MAXNUM=(unsigned long long)atoi(set);
if(strcmp(setting,"PINGTIME") == 0)
 PINGTIME=(unsigned long long)atoi(set);
bzero(setting,SIZEBUFFER);
bzero(set,SIZEBUFFER);
}

void
InitConfig( char*ConfigFile )
{
FILE * config = fopen(ConfigFile,"r");;
if(config == NULL) error("CRITICAL_ERROR: No can read config.ini");
unsigned int counter=0;
char setting[SIZEBUFFER];
char set[SIZEBUFFER];
char ch;
bool _thisSet=false;
while ( (ch = fgetc( config )) != EOF)
{
if(ch=='='){_thisSet=true;setting[counter++]='\0';counter=0;}
if(ch=='\n'){_thisSet=false;set[counter++]='\0';counter=0;_setSetting(setting,set);}
if(_thisSet==false && ch != '\n' && ch != '=') setting[ counter++ ]=ch;
if(_thisSet==true && ch != '\n' && ch != '=') set[ counter++ ]=ch;
}
fclose(config);
}
void PingPong(char*buffer,int * socket)
{

    char ping[SMALLBUFFER];
    bzero(ping,SMALLBUFFER);
    if(strstr(buffer,"PING") != NULL)
    {
     printf("INFO: Try get Ping-Pong\n");
     grepPing(buffer,ping);
     if(!*ping)
      printf("WARNING: This IRC server?\n");
     else
     {
      printf("INFO: Okey write PONG %s\n",ping);
      sprintf(buffer,"PONG %s",ping);
      printf("INFO: Write this %s to server\n",buffer);
      writeTo(*socket,buffer);
      printf("INFO: Pong pong..\n");
     }
    }//if
    if(strstr(buffer,"nospoof") != NULL)
    {
     printf("INFO: No spoof..\n");
     noSpoof(buffer,ping);
     sprintf(buffer,"PONG %s",ping);
     if(ping != '\0') writeTo(*socket,buffer);
     else printf("ERROR: all bad?\n");
    }
}
