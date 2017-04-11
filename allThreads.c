#include "AntiQubick.h"
#include<stdio.h>

void 
_botPing(int * socket)
{
while(1)
{
sleep(PINGTIME);
writeTo(*socket,"PING");
}
}
void
_botRead(int * socket)
{
char buffer[SIZEBUFFER];
//read
while(1)
{
 readFrom(*socket,buffer);
 commands(*socket,buffer);
}
}
void 
_botTroll(int * socket)
{
if(WAITMESSAGE == true)
 while(1)
 {
 sleep(TIMETROLL);
 if(WRITETHIS !=0)
 {
  Troll(*socket);
  WRITETHIS--;
 }
 
 }//while
else
 while(1)
 {
 sleep(TIMETROLL);
 Troll(*socket);
 }//while

}//_botTroll

void
_deleteDisableForWhile()
{

while(1)
 {
  sleep(TIMEDW);
  if(FORFUCKOFF !=0)
   FORFUCKOFF--;
 }
}

void
_FgetMessage(int * s)
{
char ch;
char * buffer;
int tmp;
while (1)
{
printf("Message for server(wait): ");
 buffer = (char*)malloc(sizeof(char)*SIZEBUFFER);
 while( ( ch = (char)getchar() ) != '\n' && ch != EOF && tmp <= SIZEBUFFER)
 {
  buffer[tmp++]=ch;
 }
if(tmp <= SIZEBUFFER) buffer[tmp++]='\0';
else buffer[tmp]='\0';
if(tmp > 1 )
{
 printf("Write this to server -> %s\n",buffer);
 writeTo(*s,buffer);
}
else
 printf("Write much message\n");
tmp=0;
free(buffer);
}


}
