#include <stdio.h>
#include <unistd.h>
#include <modbus.h>

int main(void) 
{
	modbus_t *mb;
	uint16_t tab_reg[256];
	int rc;
	int i;

	mb = modbus_new_tcp("127.0.0.1", 1502);
	modbus_set_debug(mb, TRUE);
	modbus_set_response_timeout(mb, 10, 0);

	if (modbus_connect(mb) == -1)
	{
		printf("Connection failed\n");
		modbus_free(mb);
    		return -1;
	}

	rc = modbus_write_register(mb, 5, 0x1234);
	printf("rc = %d\n", rc);
	rc = modbus_read_registers(mb, 0, 20, tab_reg);
	printf("rc = %d\n", rc);
	printf("DATA:\n");
	for(i=0; i<rc; i++)
	{
		printf("reg[%d] = %d\n", i, tab_reg[i]);
	}

	modbus_close(mb);
  	modbus_free(mb);

	return 0;
}
