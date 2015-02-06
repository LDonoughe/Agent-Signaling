#include "header.h"
#include "overseer_agent_header.h"
#include "mt19937arA.h"

/*
 * \fn: int receive_messages()
 * \brief: Read and write to memory.
 */
int o_receive_messages() {
	int i = 0;
	FIRM_ID = 0;
	QUALITY = 0;
	RevenuePerUnit = 0;

	while (1 == 1) {

		START_PURCHASE_MESSAGE_LOOP
			FIRM_ID = PurchaseQuality_message->seller;
			QUALITY = PurchaseQuality_message->qual;
			i = FIRM_ID - 101; //firm ids are all plus 100
			// printf("%d purchased from %d \n", STORED_ID, MY_ID);
			if (QUALITY == 1) {
				RevenuePerUnit = 1;
			} else {
				RevenuePerUnit = 5;
			}
			FIRM_REVENUES[i] = FIRM_REVENUES[i] + RevenuePerUnit;
		FINISH_PURCHASE_MESSAGE_LOOP
		break;
	}

	// printf("The sum of ids received is: %d\n", SUM_OF_IDS);

	return 0; /* Returning zero means the agent is not removed */
}

//actually change this
int o_send_message() {
	int i;
	int j;
	int low, lower, lowest;
	int fLow, fLower, fLowest;
	int change, anchor;

	low = 65,535;
	lower = 65,535;
	lowest = 65,535;

	//find lowest numbers
	for (i = 0; i < 10; i++) {
		if (FIRM_REVENUES[i] < lowest) {
			low = lower;
			lower = lowest;
			lowest = FIRM_REVENUES[i];
			fLow = fLower;
			fLower = fLowest;
			fLowest = i;
		} else if (FIRM_REVENUES[i] < lower) {
			low = lower;
			lower = FIRM_REVENUES[i];
			fLow = fLower;
			fLower = i;
		} else if (FIRM_REVENUES[i] < low) {
			low = FIRM_REVENUES[i];
			fLow = i;
		}
	}

	// The higher High Quality Probability is, the more unlikely it is to produce low quality goods.
	for (i = 0; i < 3; i++) {
		while (1 == 1) {
			change = genrand_real1A();
			if (change <= 0.1) {
				if (change >= -0.1) {
					break;
				}
			}
		}
		while (1 == 1) {
			//anchor to random success

		}
		add_StrategyAdjustment_message(i + 101, );
	}

	if (genrand_real1A() > QUALITY) {
		qual = 0;
	} else {
		qual = 1;
	}
	return 0;
}
