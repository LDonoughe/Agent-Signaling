#include "header.h"
#include "overseer_agent_header.h"
#include "mt19937arB.h"
#include "math.h"

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
	int i, check;
	int firmsLow[10] = {0,0,0,0,0,0,0,0,0,0};
	int firmsChecked[] = {0,0,0,0,0,0,0,0,0,0};
	float change;
	int anchor;
	float standardDev, mean, variance;
	float deviations[10];

	//calculate Standard Deviation

	//find mean
	mean = 0;
	for (i = 0; i < 10; i++) {
		mean = mean + FIRM_REVENUES[i];
	}
	mean = mean/10;
	printf("mean is %f \n", mean);
	//find deviations from mean
	printf("deviations are {");
	for (i = 0; i < 10; i ++) {
		deviations[i] = FIRM_REVENUES[i] - mean;
		printf("%f,",deviations[i]);
	}
	printf("}\n");
	//find variance
	variance = 0;
	for (i = 0; i < 10; i ++) {
		variance = variance + powf(deviations[i],2);
	}
	variance = variance/9;
	printf("Variance is %f\n", variance);
	//calculate sd
	standardDev = sqrt(variance);
	printf("Standard Deviation is %f \n", standardDev);

	for (i = 0; i < 10; i++) {
		if (abs(FIRM_REVENUES[i] - mean) > standardDev) {
			firmsLow[i] = 1;
		}
	}

	// printf("low: %d, lower: %d, lowest: %d \n", fLow, fLower, fLowest);
	// The higher High quality Probability is, the more unlikely it is to produce low quality goods.
	for (i = 0; i < 10; i++) {

		while (1 == 1) {
			//anchor to random success
			anchor = genrand_int32B()*(10.0/4294967295.0);
			if (firmsLow[anchor] != 1) {
				break;
			} else {
				firmsChecked[anchor] = 1;
			}
			//check for valid anchor
			check = 0;
			for (i = 0; i < 10; i++) {
				if (firmsChecked[i] == 0) {
					// Valid anchor available
					check = 1;
				}
			}
			if (check == 0) {
				//no valid anchor, use this one anyways
				break;
			}
		}

		while (1 == 1) {
			change = genrand_real1B();
			if (change <= 0.1) {
				if (change >= -0.1) {
					if (FIRM_STRATEGIES[anchor] + change <= 1) {
						if (FIRM_STRATEGIES[anchor] + change >= 0) {
							if (genrand_real1B() > 0.5) {
								change = (-1)*change;
							}
							break;
						}
					}
				}
			}
		}


		if (firmsLow[i] == 1) {
			add_StrategyAdjustment_message(i + 101, FIRM_STRATEGIES[anchor] + change);
			printf("Firm %d adopted a new strategy from %d which is %f + %f \n", i + 101, anchor + 101, FIRM_STRATEGIES[anchor], change);
		}
	}

	return 0;
}
