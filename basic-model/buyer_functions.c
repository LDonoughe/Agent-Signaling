#include "header.h"
#include "buyer_agent_header.h"
#include "mt19937ar.h"

/*
 * \fn: int send_message()
 * \brief: Send message.
 */

double randInRange(int min, int max)
{
  return min + (int) (rand() / (double) (RAND_MAX + 1) * (max - min + 1));
}

int b_send_message()
{
	// Send a message of type message_z containing the id of the agent
	add_Purchase_message(MY_ID, FIRM_ID);

	return 0; /* Returning zero means the agent is not removed */
}

int b_receive_messages() {
	int SELLER;
	int new_seller;
	int num_firms = 10;
	MY_QUAL = 0;

	// Read messages of type message_z
	START_PURCHASEQUALITY_MESSAGE_LOOP
		MY_QUAL = PurchaseQuality_message->qual;
		SELLER = PurchaseQuality_message->seller;
		printf("%d recieved quality %d from %d \n", MY_ID, MY_QUAL, SELLER);
		if (MY_QUAL == 1) { //Quality Level A
			if (genrand_real1() > 0.9) {
				while (1 == 1) {
					new_seller = 100 + genrand_int32()*(10.0/4294967295.0) + 1;
					if (new_seller != SELLER) {
						break;
					}
				}
				printf("%d switched from Firm %d to Firm %d because a product of quality %d failed \n", MY_ID, SELLER, new_seller, MY_QUAL);
				SELLER = new_seller;
			} else {
				//stay
			}
		} else { //Quality level B
			if (genrand_real1() > 0.5) {
				while (1 == 1) {
					new_seller = 100 + genrand_int32()*(10.0/4294967295.0) + 1;
					if (new_seller != SELLER) {
						break;
					}
				}
				printf("%d switched from Firm %d to Firm %d because a product of quality %d failed \n", MY_ID, SELLER, new_seller, MY_QUAL);
				SELLER = new_seller;
			} else {
				//stay
			}
		}
	FINISH_PURCHASEQUALITY_MESSAGE_LOOP

	return 0;
}
