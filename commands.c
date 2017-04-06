#include<string.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<math.h>
#define MAXPS 5012
#include "AntiQubick.h"
unsigned long long FORFUCKOFF=0;
unsigned long long NEEDFORFUCKOFF;
unsigned int TIMETROLL;//Timer for troll function
unsigned int TIMEDW;// timer for disable disable bot(turn troll)

void
_disableForWhile(int socket);
void deleteNewLine(char*array)
{
while(*array)
{
if(*array =='\n') *array='\0';
*array++;
}
}
void getProccess(int socket)//SHITCODE
{
char ps[MAXPS];
char tmp[MAXPS*2];
system("ps aux > /tmp/bot.txt");
FILE*tmpFile=fopen("/tmp/bot.txt","r");
//dup2(0,tmp);
char ch;
unsigned long long count=0;
while((ch=fgetc(tmpFile)) !=EOF)
{//SHITCODE
ps[count]=ch;
count++;
if(count > MAXPS) break;
if(ch=='\n')
{
sleep(5);
deleteNewLine(ps);
sprintf(tmp,"PRIVMSG %s %s",OWNER_NICK,ps);
//printf("%s\n",tmp);
writeTo(socket, tmp);
count = 0;
bzero(ps,MAXPS);
}//IF
}//WHILE
close(tmpFile);
}//END

void getUser(char*buffer,char*user)
{
while(*buffer!=' ' && *buffer)
 *user++=*buffer++;
}

//shit code 80 lvl
void getMessageAndChannel(char*buffer,char*message,char*channel)
{
if(strstr(buffer, "PRIVMSG") != NULL )
{
printf("%s CHANNEL\n",buffer);
while(*buffer !='P' || *(buffer+1) !='R' || *(buffer+2) !='I' || *(buffer+3) !='V' || *(buffer+4) !='M' || *(buffer+5) !='S' || *(buffer+6) !='G' && *buffer)*buffer++;
buffer=buffer+8;
if(*buffer=='#')
while(*buffer!=' ' && *buffer)
 *channel++=*buffer++;
else
 *channel='\0';
while(*buffer!=':' && *buffer)*buffer++;
while(*buffer!='\n' && *buffer)
*message++=*buffer++;
}///
}
void 
_Message(char*buffer,char*dest)
{
while(*buffer && *buffer!=' ')
 *buffer++;
while(*buffer)
 *dest++=*buffer++;
}
void
_Channel(char*src,char*dest)
{//shitcode
while(*src !='#' && *src)*src++;
while(*src!=' ' && *src)
 *dest++=*src++;
 *dest++='\0';
}
void
_DeleteChannelFromMsg(char *dest,char*src)
{
/*
printf("->->-> %s\n",src);// <-for debug
in simple normalMsg have channel!
and space in start
*/
while(*src && *src!='#') *src++;
while(*src && *src!=' ') *src++;
while(*src)*dest++=*src++;
}
/*
void
answer(char * channel, char * c, char * s) //channel command string
{
printf("Owner write in channel %s  this command %s with atribute %s\n",channel,c,s);
}
THIS DEBUG FUNCTION
*/
long long 
ToMeasures(long long number, measures what)
{
switch(what)
{
case qubinoid:
number=number*number*number;
break;
case square:
number=number*number*number*number;
break;
case penta:
number=number*number*number*number*number;
break;
default:
break;
}
return number;
}
/*
SHIT CODE one love
..................
*/
long long _atoi(char*buff)
{
if(*buff == '+' 
|| *buff == '-'
|| *buff == '/'
|| *buff == '*'
|| *buff == '%'
|| *buff == '^'
|| *buff == ' '
) *buff++;
long long result=0;
while(*buff)
{
if(
(int)*buff < 48 
|| 
(int)*buff > 57
) break;
result*=10;
result += (int)*buff-'0';
if(result > MAXNUM) return -1;
*buff='0';
*buff++;
}//while
return result;
}
/*
SHIT CODE one love
^^^^^^^^^^^^^^^^^
*/
int 
BotFunction(char * msg, char*channel,char*user,int socket)
{
srand ( time(NULL) );
///
pthread_t _forCommands;
///
if(strstr(msg, "FUCKOFF") != NULL || strstr(msg, "SHUTUP") != NULL || strstr(msg, "shutup") != NULL || strstr(msg, "завали") != NULL  || strstr(msg, "завали варюжку") != NULL  || strstr(msg, "ебалозаткни") != NULL )
  if(pthread_create(&_forCommands,NULL,&_disableForWhile,socket) ==-1)error("No can create thread:(");
///
if(strstr(msg,"!JOINMAFIA") != NULL)
{
char tmp[SIZEBUFFER];
if(PLAYERSINMAFIA>=MAXPLAYERSINMAFIA)
{
sprintf(tmp,"PRIVMSG %s %s, wait other game",channel,user);
return writeTo(socket,tmp);
}
if(PLAYERSINMAFIA >= 0)
 for(int i = PLAYERSINMAFIA-1;i>=0;i--)
 {
  if( strcmp(players[i].usr,user) == 0) 
   {
    sprintf(tmp,"PRIVMSG %s %s, you already in game",channel,user);
    return writeTo(socket,tmp);
   }
 }
char buffer[SIZEBUFFER];
bzero(buffer,SIZEBUFFER);
bzero(tmp,SIZEBUFFER);
players[PLAYERSINMAFIA].type = rand() % 2;
players[PLAYERSINMAFIA].usr = user;
sprintf(tmp,"PRIVMSG %s %s Welcome to game, you type %d",channel,players[PLAYERSINMAFIA].usr,players[PLAYERSINMAFIA].type);
writeTo(socket,tmp);
PLAYERSINMAFIA++;
}
if(strstr(msg, "INQUBINOID") != NULL 
|| strstr(msg, "INSQUARE") != NULL 
||  strstr(msg, "INPENTA") != NULL 
||  strstr(msg, "*") != NULL 
||  strstr(msg, "/") != NULL 
||  strstr(msg, "+") != NULL 
||  strstr(msg, "-") != NULL
||  strstr(msg, "%") != NULL 
||  strstr(msg, "^") != NULL 
&&  !strstr(msg,"HTTP")
)
{
unsigned long long a,b = 0;
long long answer=0;
char c;
char tmp[SIZEBUFFER];
char normalMsg[SIZEBUFFER];
///...
bzero(tmp,SIZEBUFFER);
bzero(normalMsg,SIZEBUFFER);
///...
_Message(msg,normalMsg);
if(atoi(normalMsg) > MAXPOWN) return -1;
else if(strstr(msg, "INQUBINOID") != NULL)
 answer = ToMeasures(atoi(normalMsg),qubinoid);
else if(strstr(msg, "INSQUARE") != NULL)
 answer = ToMeasures(atoi(normalMsg),square);
else if(strstr(msg, "INPENTA") != NULL)
 answer = ToMeasures(atoi(normalMsg),penta);
/*
SHIT CODE one love
..................
*/
else if(strstr(msg, "*") != NULL 
||  strstr(msg, "/") != NULL 
||  strstr(msg, "+") != NULL 
||  strstr(msg, "-") != NULL
||  strstr(msg, "%") != NULL 
||  strstr(msg, "^") != NULL 
)
{
long long tmp_num=0;
long long shitcode_num=0;
long long tmp_num_two=0;
while(*msg)
{
if(
*msg == '0' ||
*msg == '1' ||
*msg == '2' ||
*msg == '3' ||
*msg == '4' ||
*msg == '5' ||
*msg == '6' ||
*msg == '7' ||
*msg == '8' ||
*msg == '9'
)
{
if( (shitcode_num = _atoi(msg)) != 0)
 tmp_num=shitcode_num;
}
else
{
if( (shitcode_num = _atoi(msg)) != 0)
 tmp_num_two=shitcode_num;
switch(*msg)
{
case '+':
 answer += tmp_num+tmp_num_two;
 tmp_num_two=0;
 tmp_num=0;
 shitcode_num=0;
 break;
case '-':
 answer += tmp_num-tmp_num_two;
 tmp_num_two=0;
 tmp_num=0;
 shitcode_num=0;
 break;
case '/':
 if(tmp_num != 0 && tmp_num_two !=0)
  answer += tmp_num/tmp_num_two;
 else if(tmp_num_two !=0 )
  answer = answer/tmp_num_two;
 tmp_num_two=0;
 tmp_num=0;
 shitcode_num=0;
 break;
case '*':
 if(tmp_num != 0 && tmp_num_two !=0)
 answer += tmp_num*tmp_num_two;
 else if(tmp_num_two != 0)
 answer = answer*tmp_num_two;
 tmp_num_two=0;
 tmp_num=0;
 shitcode_num=0;
 break;
case '%':
 if(tmp_num != 0 && tmp_num_two !=0)
 answer += tmp_num%tmp_num_two;
 else if(tmp_num_two !=0)
 answer = answer%tmp_num_two;
 tmp_num_two=0;
 tmp_num=0;
 shitcode_num=0;
 break;
case '^':
 if(tmp_num_two < MAXPOWN && tmp_num < MAXPOWN)
 answer += pow(tmp_num,tmp_num_two);
 tmp_num_two=0;
 tmp_num=0;
 shitcode_num=0;
 break;
default:
 break;
}//switch
}//else
if(tmp_num_two == -1 || tmp_num== -1 || answer > MAXNUM)
{
 writeTo(socket,"Which you get this fucking mathematic? Fuck this. NOPE. no-no");
 return -1;
}
*msg++;
}//while



}
/*
^^^^^^^^^^^^^^^^^^
SHIT CODE one love
*/
printf("%d\n",answer);
if(answer != 0)
 {
  sprintf(tmp,"PRIVMSG %s %s %d",channel,"I know the answer",answer);  
  writeTo(socket, tmp);
 }
}//MATH
///
}

void
_disableForWhile(int socket)
{
char tmp[SIZEBUFFER];
FORFUCKOFF++;
if(FORFUCKOFF < NEEDFORFUCKOFF)
 sprintf(tmp,"PRIVMSG %s %s %d",DEFAULT_CHANNEL,"For fuck off you have off points",FORFUCKOFF);
else
 sprintf(tmp,"PRIVMSG %s OK",DEFAULT_CHANNEL);
writeTo(socket, tmp);
}

void 
_command(char * msg, char*channel,int socket)
{
pthread_t _forCommands;
//shit code
if(strstr(msg, "SAYTHIS") != NULL )
{
char tmp[SIZEBUFFER];
char normalMsg[SIZEBUFFER];
char normalChannel[SIZEPING*2];
///...
bzero(tmp,SIZEBUFFER);
bzero(normalMsg,SIZEBUFFER);
bzero(normalChannel,SIZEPING*2);
///...
_Message(msg,normalMsg);
if(strstr(normalMsg, "#") != NULL )
{
 _Channel(normalMsg,normalChannel);
 _DeleteChannelFromMsg(tmp,normalMsg);
 ///
 bzero(normalMsg,SIZEBUFFER);//delete
 ///
 strcpy (normalMsg, tmp);
 printf("CHANNEL (%s)\n",normalChannel);
 sprintf(tmp,"PRIVMSG %s %s",normalChannel,normalMsg);
}
else //if not channel
 sprintf(tmp,"PRIVMSG %s %s",channel,normalMsg);
writeTo(socket, tmp);
}//SAYTHIS
if(strstr(msg, "CLEAROFFPOINTS") != NULL )
{
FORFUCKOFF=0;
}
if(strstr(msg, "JOINTO") != NULL )
{
char tmp[SIZEBUFFER];
char normalMsg[SIZEBUFFER];
char normalChannel[SIZEPING*2];
///...
bzero(tmp,SIZEBUFFER);
bzero(normalMsg,SIZEBUFFER);
bzero(normalChannel,SIZEPING*2);
///...
_Message(msg,normalMsg);
if(strstr(normalMsg, "#") != NULL )
{
 _Channel(normalMsg,normalChannel);
 sprintf(tmp,"JOIN %s %s",normalChannel,normalMsg);
 printf("%s\n",tmp);
 writeTo(socket, tmp);
}//IF NOT CHANNEL
else
{
 sprintf(tmp,"PRIVMSG %s WHERE THIS CHANNEL?!",channel);
 writeTo(socket, tmp);
}//ELSE
}//END if(strstr(msg, "JOINTO") != NULL )
///

if(strstr(msg, "NICKSET") != NULL ) 
{
char tmp[SIZEBUFFER];
char normalMsg[SIZEBUFFER];
char nick[30];
///...
bzero(nick,30);
bzero(tmp,SIZEBUFFER);
bzero(normalMsg,SIZEBUFFER);
///...
_Message(msg,normalMsg);
 sprintf(tmp,"NICK %s",normalMsg);
 writeTo(socket, tmp);
}

if(strstr(msg, "HTTP") != NULL ) 
{
char tmp[SIZEBUFFER];
char normalMsg[SIZEBUFFER];
//...
char url[SIZEBUFFER];
char cookie[SIZEBUFFER];
char postfield[SIZEBUFFER];
///...
bzero(tmp,SIZEBUFFER);
bzero(normalMsg,SIZEBUFFER);
bzero(url,SIZEBUFFER);
bzero(cookie,SIZEBUFFER);
bzero(postfield,SIZEBUFFER);
///...
_Message(msg,normalMsg);
sscanf(normalMsg,"%s %s %s",url,cookie,postfield);
printf("URL=%s COOKIE=%s POSTFIELD=%s\n",url,cookie,postfield);
SendHTTPPOST(url,cookie,postfield,socket,channel);
}

if(strstr(msg, "WRITETOSERVER") != NULL ) 
{
char tmp[SIZEBUFFER];
char normalMsg[SIZEBUFFER];
///...
bzero(tmp,SIZEBUFFER);
bzero(normalMsg,SIZEBUFFER);
///...
_Message(msg,normalMsg);
 sprintf(tmp,"%s",normalMsg);
 writeTo(socket, tmp);
}
///

if(strstr(msg, "SETTOPIC") != NULL )
{
char tmp[SIZEBUFFER];
char normalMsg[SIZEBUFFER];
char normalChannel[SIZEPING*2];
///...
bzero(tmp,SIZEBUFFER);
bzero(normalMsg,SIZEBUFFER);
bzero(normalChannel,SIZEPING*2);
///...
_Message(msg,normalMsg);
if(strstr(normalMsg, "#") != NULL )
{
 _Channel(normalMsg,normalChannel);
 _DeleteChannelFromMsg(tmp,normalMsg);
 ///
 bzero(normalMsg,SIZEBUFFER/2);//delete
 ///
 strcpy (normalMsg, tmp);
 sprintf(tmp,"TOPIC %s %s",normalChannel,normalMsg);
}
else //if not channel
 sprintf(tmp,"TOPIC %s %s",channel,normalMsg);
writeTo(socket, tmp);
}//SETTOPIC
///

if(strstr(msg, "LEAVE") != NULL )
{
char tmp[SIZEBUFFER];
char normalMsg[SIZEBUFFER];
char normalChannel[SIZEPING*2];
///...
bzero(tmp,SIZEBUFFER);
bzero(normalMsg,SIZEBUFFER);
bzero(normalChannel,SIZEPING*2);
///...
_Message(msg,normalMsg);
if(strstr(normalMsg, "#") != NULL )
{
 _Channel(normalMsg,normalChannel);
 sprintf(tmp,"PART %s %s",normalChannel,normalMsg);
 printf("%s\n",tmp);
 writeTo(socket, tmp);
}//IF NOT CHANNEL
else
{
 sprintf(tmp,"PRIVMSG %s if you want that i am die, write QUIT, or if you want that i am quit from channel write this channel",channel);
 writeTo(socket, tmp);
}//ELSE
}//END if(strstr(msg, "JOINTO") != NULL )
///
if(strstr(msg, "HELP") != NULL )
{
 char tmp[SIZEBUFFER];
 sprintf(tmp,"PRIVMSG %s SAYTHIS (#channel optional) message;LEAVE #channel;JOINTO #channel;SETTOPIC topic;PSAUX;QUIT;WRITETOSERVER message;NICKSET nick;CLEAROFFPOINTS;HTTP url cookie postfield;It seems everything, the boss",channel);
 writeTo(socket, tmp);
}

///
if(strstr(msg, "PSAUX") != NULL ) 
 if(pthread_create(&_forCommands,NULL,&getProccess,socket) ==-1)error("No can create thread:(");
if(strstr(msg, "QUIT") != NULL )
 QUIT(socket);
}

void
getChannel(char*buffer,char*channel)
{
bzero(channel,SMALLBUFFER);
while(*buffer !='#' && *buffer)*buffer++;
if(*buffer == '#')
 while(*buffer!=' ' && *buffer)
  *channel++=*buffer++;
else
 *channel='\0';
}
void
getNickFromUser(char*user,char*channel)
{
if(*user) *user++;
while(*user)
{
if(*user=='!') break;
*channel++=*user++;
}
}
void
commands(int socket,char*buffer)
{
if(*buffer)
{
 char user[SMALLBUFFER];
 char channel[SMALLBUFFER];
 char message[SIZEBUFFER];
 if(strstr(buffer,"KICK") !=NULL && strstr(buffer,"PRIVMSG") ==NULL )
 {
  printf("FULL MESSAGE: %s\n",buffer);
  getChannel(buffer,channel);
  if(channel !='\0')
  {
   printf("CHANNEL: %s\n",channel);
   sprintf(buffer,"JOIN %s",channel);
   writeTo(socket,buffer);
  }
 }
 bzero(user,SMALLBUFFER);
 bzero(channel,SMALLBUFFER);
 bzero(message,SIZEBUFFER);
 getUser(buffer,user);
 getMessageAndChannel(buffer,message,channel);
 if(channel[0] =='\0')
  getNickFromUser(user,channel);
 if(*user && *message && *channel)
  {
   printf("HUMAN WITH MONIKER %s WRITE IN CHANNEL/TO PM %s -> %s\n",user,channel,message );
   if(WAITMESSAGE == true)
    WRITETHIS++;

   if(strcmp(user,OWNER) == 0 && *channel && *user && *message)
    _command(message,channel,socket);

   if(*channel && *user && *message)
    BotFunction(message,channel,user,socket);
  }//if 
 }// if *buffer
}

