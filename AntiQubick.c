#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
/*in future*/
//#include<ncurses.h>
//#include<menu.h>
#include "AntiQubick.h"
char OWNER[256];// = ":WEREWOLF!WEREWOLF@lfshvsjjph2aqemhdrvaccgxc5ss54kodbn3vjftxosqje6ak6kq.b32.i2p";
char OWNER_NICK[256];// = "WEREWOLF";
char DEFAULT_CHANNEL[256];// = "#ru";
unsigned long long MAXPOWN;
unsigned long long MAXNUM;
unsigned long long PINGTIME;
bool WAITMESSAGE=false;
unsigned long long WRITETHIS;
unsigned int MAXPLAYERSINMAFIA=4;
unsigned int NEEDPLAYERSINMAFIA=2;
unsigned int PLAYERSINMAFIA=0;
char HostServer[126];
int PortServer;
playersMafia * players;
short LambsWork=0; //shit
int main(int argcount, char *arguments[])
{
   if(argcount < 7)
    error("./programm host port nick UserName RealName configFile");
   InitConfig(arguments[6]);
   strcpy(HostServer,arguments[1]);
   PortServer=atoi(arguments[2]);
   printf("%d debug time\n",PINGTIME);
   printf("\n%s %s %s\n",OWNER,OWNER_NICK,DEFAULT_CHANNEL); //debug
////////////////////////////////////////////////////////////
    pthread_t ForBot;
    pthread_t ForTroll;
    pthread_t ForPing;
    pthread_t ForAntiDisable;//shit name
    pthread_t ForFgets;
    char buffer[SIZEBUFFER];
    bzero(buffer,SIZEBUFFER);
////////////////////////////////////////////////////////////
    printf("Start connecting\n");
    int mainsocket=InitClient(HostServer,PortServer);
    printf("Succefully\n");
    sprintf(buffer,"NICK %s",arguments[3]);
    writeTo(mainsocket, buffer);

    do
    {
     readFrom(mainsocket,buffer);
     PingPong(buffer,&mainsocket);
     printf("%s\n",buffer);
    }while( strstr(buffer,"nospoof") != NULL || strstr(buffer,"PING") != NULL  ); //for ping-pong server

    sprintf(buffer,"USER %s 8 * : %s",arguments[4],arguments[5]);
    writeTo(mainsocket, buffer);
//////////////////////////////////////////////////////////////
    printf("INFO: Join to channel\n");
    printf("....\n");
    sprintf(buffer,"JOIN %s",DEFAULT_CHANNEL);
    writeTo(mainsocket,buffer);
    readFrom(mainsocket,buffer);
    if(strstr(buffer,"nospoof") != NULL || strstr(buffer,"PING") != NULL) //for mystic servers
    {
    PingPong(buffer,&mainsocket);
    printf("WARNING: Mystic pong-pong\n");
    printf("....\n");
    sprintf(buffer,"JOIN %s",DEFAULT_CHANNEL);
    writeTo(mainsocket,buffer);
    readFrom(mainsocket,buffer);
    }
    printf("%s\n",buffer);
    bzero(buffer,SIZEBUFFER);
//    players = calloc(sizeof(playersMafia),MAXPLAYERSINMAFIA);
    printf("start threads\n");
    if(pthread_create(&ForBot,NULL, _botRead, &mainsocket) ==-1)error("No can create thread:(");
    if(pthread_create(&ForTroll,NULL, _botTroll, &mainsocket) ==-1)error("No can create thread:(");
    if(pthread_create(&ForPing,NULL, _botPing ,&mainsocket) ==-1)error("No can create thread:(");
    if(pthread_create(&ForAntiDisable,NULL, _deleteDisableForWhile ,NULL) ==-1)error("No can create thread:(");
    if(pthread_create(&ForFgets,NULL, _FgetMessage ,&mainsocket) ==-1)error("No can create thread:(");
    pthread_join(ForBot,NULL);
    pthread_join(ForTroll,NULL);
    pthread_join(ForPing,NULL);
    //pthread_join(ForFgets,NULL); auto close with all programm
    stopClient(&mainsocket);
    main(7,arguments);
}

