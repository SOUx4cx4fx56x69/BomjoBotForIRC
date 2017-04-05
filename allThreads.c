#include "AntiQubick.h"
void 
_botPing(int socket)
{
while(1)
{
sleep(PINGTIME);
writeTo(socket,"PING");
}
}
void
_botRead(int socket)
{
char buffer[SIZEBUFFER];
//read
while(1)
{
 readFrom(socket,buffer);
 commands(socket,buffer);
}
}
void 
_botTroll(int socket)
{
if(WAITMESSAGE == true)
 while(1)
 {
 sleep(TIMETROLL);
 if(WRITETHIS !=0)
 {
  Troll(socket);
  WRITETHIS--;
 }
 
 }//while
else
 while(1)
 {
 sleep(TIMETROLL);
 Troll(socket);
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
