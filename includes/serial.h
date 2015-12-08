
#ifndef __H_FIRMATAC_SERIAL_
#define __H_FIRMATAC_SERIAL_

#include <stdint.h>

#include <termios.h>

typedef struct		s_serial
{
  int			port_is_open;
  char			*port_name;
  int			baud_rate;
  char			*error_msg;

  int			port_fd;
  struct termios	settings_orig;
  struct termios	settings;
  int			tx;
  int			rx;
}			serial_t;

serial_t *serial_new();
int serial_open(serial_t *serial, char *name);
int	serial_setBaud(serial_t *serial, int baud);
int	serial_read(serial_t *serial, void *ptr, int count);
int	serial_write(serial_t *serial, void *ptr, int len);
int	serial_waitInput(serial_t *serial, int msec);
void serial_discardInput(serial_t *serial);
void serial_flushOutput(serial_t *serial);
int serial_setControl(serial_t *serial, int dtr, int rts);

#endif
