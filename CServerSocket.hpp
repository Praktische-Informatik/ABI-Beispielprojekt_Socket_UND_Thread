#include "CSocket.hpp"

class CServerSocket
{
private:
  int			port;
  SOCKET		serverSocket;

public:
				CServerSocket	(int port);
				CSocket* accept	(void);
  void			close			(void);
};