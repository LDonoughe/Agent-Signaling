#include "header.h"
#include "firm_agent_header.h"
#include "mt19937arA.h"

/*
 * \fn: int receive_messages()
 * \brief: Read and write to memory.
 */
int f_receive_messages() {
	int i = 0;
	STORED_ID = 0;


	// Read messages of type message_z
	while (1 == 1) {

		START_PURCHASE_MESSAGE_LOOP
			STORED_ID = Purchase_message->an_id;
			// printf("%d purchased from %d \n", STORED_ID, MY_ID);
			BUYER_IDS[i] = STORED_ID;
			i++;
		FINISH_PURCHASE_MESSAGE_LOOP
		break;
	}

	for (i = i; i < 100; i++) {
		BUYER_IDS[i] = 0;
	}
	printf("run firm \n");

	// printf("The sum of ids received is: %d\n", SUM_OF_IDS);

	return 0; /* Returning zero means the agent is not removed */
}

int f_send_message() {
	int i;
	int qual;

	// The higher High Quality Probability is, the more unlikely it is to produce low quality goods.
	if (genrand_real1A() > QUALITY) {
		qual = 0;
	} else {
		qual = 1;
	}
	for (i = 0; i < 100; i++) {
		if (BUYER_IDS[i] == 0) {
			break;
		}
		add_PurchaseQuality_message(qual, BUYER_IDS[i], MY_ID);
	}
	return 0;
}

int f_idle() {

	
	// add_buyer_agent(1, 101, 1);

	return 0;
}