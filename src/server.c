#include <stdio.h>
#include <stdlib.h>
#include <modbus.h>

int main(void) 
{
	modbus_t *mb;
	modbus_mapping_t *mb_mapping;
	int s;
	uint8_t *query;

	mb = modbus_new_tcp("127.0.0.1", 1502);

	query = malloc(MODBUS_TCP_MAX_ADU_LENGTH);
	modbus_set_debug(mb, TRUE);

	mb_mapping = modbus_mapping_new_start_address(
				0, 10,
				0, 20,
				0, 30,
				0, 40);

	s = modbus_tcp_listen(mb, 1);
	modbus_tcp_accept(mb, &s);
	modbus_connect(mb);

	do{
		s = modbus_receive(mb, query);
	} while(s == 0);
	printf("Request recieved s=%d\n", s);
	s = modbus_reply(mb, query, s, mb_mapping);

	modbus_mapping_free(mb_mapping);
	modbus_close(mb);
	modbus_free(mb);
	free(query);

	return 0;
}
