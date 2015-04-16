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
		START_PURCHASE_MESSAGE_LOOP
			STORED_ID = Purchase_message->an_id;
			// printf("%d purchased from %d \n", STORED_ID, MY_ID);
			BUYER_IDS[i] = STORED_ID;
			i++;
		FINISH_PURCHASE_MESSAGE_LOOP

	for (i = i; i < 100; i++) {
		BUYER_IDS[i] = 0;
	}

	// printf("The sum of ids received is: %d\n", SUM_OF_IDS);

	return 0; /* Returning zero means the agent is not removed */
}

int f_send_message() {
	int i;
	int qual;

	// The higher High Quality Probability is i.e., alpha, the more likely the firm is to produce high quality goods.
	if (genrand_real1A() > QUALITY) {
		qual = 0;
	} else {
		qual = 1;
	}
	for (i = 0; i < 100; i++) {
		if (BUYER_IDS[i] == 0) {
			break;
		}
		add_PurchaseQuality_message(qual, BUYER_IDS[i], MY_ID, QUALITY);
	}
	return 0;
}

int f_receive_strategy() {
	START_STRATEGYADJUSTMENT_MESSAGE_LOOP
		QUALITY = StrategyAdjustment_message->new_strategy;
	FINISH_STRATEGYADJUSTMENT_MESSAGE_LOOP
	return 0;
}

int f_idle() {

	
	// add_buyer_agent(1, 101, 1);

	return 0;
}