#define SIZEBUFFER 1024
#define SMALLBUFFER 256
#define SIZEPING 15
#ifdef WIN32
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)  
#define bcopy(b1,b2,len) (memmove((b2), (b1), (len)), (void) 0)
#endif
typedef __SIZE_TYPE__ size_t;
typedef enum bool
{
false,true
}bool;
typedef enum measures
{
qubinoid,square,penta
}measures;
void _botRead(int * socket);
void _botTroll(int * socket);
void _botPing(int * socket);
void _deleteDisableForWhile();
char OWNER[256];// = ":WEREWOLF!WEREWOLF@lfshvsjjph2aqemhdrvaccgxc5ss54kodbn3vjftxosqje6ak6kq.b32.i2p";
char OWNER_NICK[256];// = "WEREWOLF";
char DEFAULT_CHANNEL[256];// = "#ru";
unsigned long long FORFUCKOFF;
unsigned long long NEEDFORFUCKOFF;
unsigned int TIMETROLL;//Timer for troll function
unsigned int TIMEDW;// timer for disable disable bot(turn troll)
unsigned long long MAXPOWN; // Max to power/qub/square etc
unsigned long long MAXNUM; // MAX NUM for simply math
unsigned long long PINGTIME; // ping time
///
bool WAITMESSAGE; // FOR R4SAS :O
unsigned long long WRITETHIS; // I write this shit ^_^

unsigned int MAXPLAYERSINMAFIA;
unsigned int PLAYERSINMAFIA;
unsigned int NEEDPLAYERSINMAFIA;

///
typedef enum typePlayer
{
citizen,mafia
}typePlayer;

typedef struct playersMafia
{
char*usr;
typePlayer type;
}playersMafia;
///
playersMafia * players;

void _FgetMessage(int * s);
void InitConfig( char*ConfigFile );
void PingPong(char*buffer,int * socket);
void SendHTTPPOST(char*url,char*cookie,char*postField,int socket,char*channel);
int InitClient(char*host,int portno);
void error(const char *msg);
void writeTo(int socket,char*msg);
void readFrom(int socket,char*buffer);
void stopClient(int * socket);
void QUIT(int socket);
void commands(int socket,char*buffer);
void Troll(int socket);
//
void bzero(void *s, size_t n);
char *strcpy(char *dest, const char *src);
int strcmp(const char *s1, const char *s2);
int atoi(const char *nptr);
int system(const char *command);
void srand(unsigned int seed);
int raise(int sig);
char *strstr(const char *haystack, const char *needle);
int close(int fd);
extern unsigned int sleep (unsigned int __seconds);
