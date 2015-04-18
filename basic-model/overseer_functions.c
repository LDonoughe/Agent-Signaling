#include "header.h"
#include "overseer_agent_header.h"
#include "mt19937arB.h"

/*
 * \fn: int receive_messages()
 * \brief: Read and write to memory.
 */
int o_receive_messages() {
	int i = 0;
	int firm = 0;
	int quality = 0;
	int RevenuePerUnit = 0;

	for (i = 0; i < 10; i++) {
		FIRM_REVENUES[i] = 0;
		printf("Firm %d revenue now %d \n",i + 1,FIRM_REVENUES[i]);
	}

	i = 0;
	while (1 == 1) {

		START_PURCHASEQUALITY_MESSAGE_LOOP
			firm = PurchaseQuality_message->seller;
			quality = PurchaseQuality_message->qual;
			i = firm - 101; //firm ids are all plus 100
			// printf("%d purchased from %d \n", STORED_ID, MY_ID);
			if (quality == 1) {
				RevenuePerUnit = 1;
			} else {
				RevenuePerUnit = 5;
			}
			FIRM_STRATEGIES[i] = PurchaseQuality_message->strategy;
			FIRM_REVENUES[i] = FIRM_REVENUES[i] + RevenuePerUnit;
		FINISH_PURCHASEQUALITY_MESSAGE_LOOP
		break;
	}

	// printf("The sum of ids received is: %d\n", SUM_OF_IDS);

	return 0; /* Returning zero means the agent is not removed */
}

//Tell firms new strategy <- the crucial function
int o_send_message() {
	int i;
	int low, lower, lowest;
	int fLow, fLower, fLowest;
	float change;
	int anchor;

	low = 2147483647;
	lower = 2147483647;
	lowest = 2147483647;

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

	// printf("low: %d, lower: %d, lowest: %d \n", fLow, fLower, fLowest);
	// The higher High quality Probability is, the more unlikely it is to produce low quality goods.
	for (i = 0; i < 3; i++) {
		while (1 == 1) {
			change = genrand_real1B();
			if (change <= 0.1) {
				if (change >= -0.1) {
					break;
				}
			}
		}
		while (1 == 1) {
			//anchor to random success
			anchor = genrand_int32B()*(10.0/4294967295.0);
			if (anchor != fLow) {
				if (anchor != fLower) {
					if (anchor != fLowest) {
						if (FIRM_STRATEGIES[anchor] + change <= 1.0) {
							if (FIRM_STRATEGIES[anchor] + change >= 0.0) {
								break;
							}
						}
					}
				}
			}
		}

		if (i == 0) {
			add_StrategyAdjustment_message(fLowest + 101, FIRM_STRATEGIES[anchor] + change);
			printf("Firm %d adopted a new strategy from %d which is %f + %f \n", fLowest + 101, anchor + 101, FIRM_STRATEGIES[anchor], change);
		}
		if (i == 1) {
			add_StrategyAdjustment_message(fLower + 101, FIRM_STRATEGIES[anchor] + change);
			printf("Firm %d adopted a new strategy from %d which is %f + %f \n", fLower + 101, anchor + 101, FIRM_STRATEGIES[anchor], change);
		}
		if (i == 2) {
			add_StrategyAdjustment_message(fLow + 101, FIRM_STRATEGIES[anchor] + change);
			printf("Firm %d adopted a new strategy from %d which is %f + %f \n", fLow + 101, anchor + 101, FIRM_STRATEGIES[anchor], change);
		}
	}

	return 0;
}
