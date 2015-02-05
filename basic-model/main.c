/**
 * \file  main.c
 * \brief Holds main function of the program.
 */

#include "header.h"
#define COMPACT_PRINTOUT_P_THRESHOLD 8

/** \fn int main(int argc, char * argv[])
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char * argv[])
{
	/* Timing variables */
	double start, stop, interval;
	FILE *file;
	char data[100];
	char logfilepath[1000];
	char inputpath[1000];
	char * c;
	int lastd = 0;
	int i;
	int rc;
	int iteration_number = 0;
	int iteration_total;
	int * p_iteration_number = &iteration_number;
	//xmachine_memory_buyer * temp_xmachine_buyer;
	//xmachine_memory_firm * temp_xmachine_firm;

	int FLAME_PurchaseQuality_message_board_write;
	int FLAME_PurchaseQuality_message_board_read;
	int FLAME_Purchase_message_board_write;
	int FLAME_Purchase_message_board_read;

	/* Particle cloud data */
	double cloud_data[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
	/* Count to debug function branches */
	int FLAME_debug_count;

/* For partition method. Makes geometric (-g flag) the default but may be overridden with -r for round-robin */
	int partition_method=1;



	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Set random seed */
/*	srand(time(NULL)); */

	

	rc = MB_Env_Init();
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Failed to initialise Message Board environment\n");
	   switch(rc) {
	       case MB_ERR_MPI:
	           fprintf(stderr, "\t reason: MPI library not initialised\n");
	           break;
	       case MB_ERR_MEMALLOC:
	           fprintf(stderr, "\t reason: out of memory\n");
	           break;
           default:
               fprintf(stderr, "\t MB_Env_Init returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }

	   
       exit(rc);

	}
	#endif
    
	/* For backwards compatabilty allocate current_xmachine */
	current_xmachine = (xmachine *)malloc(sizeof(xmachine));
	if(current_xmachine == NULL) {printf("**** ERROR in Memory check current_xmachine\n");exit(EXIT_FAILURE);}
	/*CHECK_POINTER(current_xmachine);*/

	/* Initialise pointers */
	initialise_pointers();


	printf("FLAME Application: model 01 \n");


	printf("Debug mode enabled \n");
FLAME_debug_count = 0;
/* Use to stop compiler warnings if not used */
if(FLAME_debug_count == 0) {}




if(argc < 2)
	{

		printf("Usage: %s <number of iterations> [<states_directory>]/<init_state> <partitions> [-f # | -f #+#]\n",argv[0]);
		printf("\t-f\tOutput frequency, 1st # is frequency, 2nd # is the offset if required\n");



		exit(0);
	}
	iteration_total = atoi(argv[1]);
printf("Iterations: %i\n", iteration_total);

	/* Read initial states of x-machines */
	if(argc < 3)
	{
		printf("Need two parameters\n");
		exit(0);
	}
	strcpy(inputpath, argv[2]);
/*printf("Initial states: %s\n", inputpath);*/

	i = 0;
	lastd = -1;
	while(inputpath[i] != '\0')
	{
		/* For windows directories */
		if(inputpath[i] == '\\') lastd=i;
		/* For unix directories */
		if(inputpath[i] == '/') lastd=i;
		i++;
	}
	strcpy(outputpath, inputpath);
	outputpath[lastd+1] = '\0';

/*printf("Ouput dir: %s\n", outputpath);*/


	/* Read number of space partitions (1 by default) */
	totalnodes = 1;
	if(argc > 3)
	{
		totalnodes = atoi(argv[3]);
	}


	i = 3;
	while(argc > i)
	{
		if(strcmp(argv[i],"-f") == 0)
		{
			if(argc > (i+1))
			{
				output_offset = 0;
				/* Find offset, separated by the char '+' */
				c = strchr(argv[(i+1)], '+');
				if(c == NULL)
				{
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d\n", output_frequency);
				}
				else
				{
					output_offset = atoi(argv[(i+1)]+(c-argv[(i+1)])+1);
					argv[(i+1)][c-argv[(i+1)]] = '\0';
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d with offset %d\n", output_frequency, output_offset);
				}

				if(output_frequency == 0)
				{
					printf("Output frequency cannot be zero\n");
					exit(0);
				}

				i++;
			}
			else
			{
				printf("Output frequency number not defined\n");
				exit(0);
			}
		}
		/* Partitioning method: -g = geometric, -r = round-robin */
		if(strcmp(argv[i],"-g") == 0) partition_method = 1;
		if(strcmp(argv[i],"-r") == 0) partition_method = 2;
		i++;
	}


	    /* Read initial data into p_xmachine  */

       //agent_list = p_xmachine;
       readinitialstates(inputpath, outputpath, p_iteration_number, cloud_data, partition_method, 0);
       /* Generate partitions */
       generate_partitions(cloud_data,totalnodes,partition_method);
       save_partition_data();





    /* Partition data */
    /* stc: no partitions in serial */
	//partition_data(totalnodes, agent_list, cloud_data, partition_method);



/* Use MB_IndexMap routines from libmboard v0.2 */
/* For each agent constant (that is used in a filter(?))
 * declare an index map handle */



		/*i = 0;
		current_node = *p_node_info;
		while(current_node)
		{
			printf("No of agents on partition %d: %d\n", current_node->node_id, current_node->agent_total);
			i += current_node->agent_total;
			current_node = current_node->next;
		}
		printf("Agent total check: %d\n", i);*/

        /* restore current_node pointer */
		//current_node = *p_node_info;



	/* Start log file (now so that xvisualiser can read straight away) */

	/* Write log file */
	sprintf(logfilepath, "%slog.xml", outputpath);
	if((file = fopen(logfilepath, "w"))==NULL)
	{
		printf("Error: cannot open file '%s' for writing\n", logfilepath);
		exit(0);
	}
	(void)fputs("<model_run>\n", file);
	(void)fputs("<codetype>", file);
	(void)fputs("serial", file);

	(void)fputs("</codetype>\n", file);
	(void)fputs("<nodes>", file);
	sprintf(data, "%i", totalnodes);
	(void)fputs(data, file);
	(void)fputs("</nodes>\n", file);

	/* print timer into */
	(void)fputs("<!-- <time> unit: milliseconds -->\n", file);

	sprintf(data, "unspecified");
	
	(void)fputs("<!-- <time> timer resolution: ", file);
	(void)fputs(data, file);
	(void)fputs(")-->\n", file);

	start = get_time();
	stop = get_time();
	sprintf(data, "%.2e ms", (stop - start) * 1000.0);
	(void)fputs("<!-- <time> timer overhead: ~", file);
	(void)fputs(data, file);
	(void)fputs(")-->\n", file);


	(void)fclose(file);


	/* For each message check if their exists agents that input/output the message */
	FLAME_PurchaseQuality_message_board_write = 0;
	FLAME_PurchaseQuality_message_board_read = 0;
	/* Sending agents */
	if(firm_start_state->agents != NULL) FLAME_PurchaseQuality_message_board_write = 1;
	
	/* Reading agents */
	if(buyer_start_state->agents != NULL) FLAME_PurchaseQuality_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_PurchaseQuality_message_board_write == 0 &&
		FLAME_PurchaseQuality_message_board_read == 0)
			rc = MB_SetAccessMode(b_PurchaseQuality, MB_MODE_IDLE);
	if(FLAME_PurchaseQuality_message_board_write == 1 &&
		FLAME_PurchaseQuality_message_board_read == 0)
			rc = MB_SetAccessMode(b_PurchaseQuality, MB_MODE_WRITEONLY);
	if(FLAME_PurchaseQuality_message_board_write == 0 &&
		FLAME_PurchaseQuality_message_board_read == 1)
			rc = MB_SetAccessMode(b_PurchaseQuality, MB_MODE_READONLY);
	if(FLAME_PurchaseQuality_message_board_write == 1 &&
		FLAME_PurchaseQuality_message_board_read == 1)
			rc = MB_SetAccessMode(b_PurchaseQuality, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'PurchaseQuality' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'PurchaseQuality' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'PurchaseQuality' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_Purchase_message_board_write = 0;
	FLAME_Purchase_message_board_read = 0;
	/* Sending agents */
	if(buyer_start_state->agents != NULL) FLAME_Purchase_message_board_write = 1;
	
	/* Reading agents */
	if(firm_start_state->agents != NULL) FLAME_Purchase_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_Purchase_message_board_write == 0 &&
		FLAME_Purchase_message_board_read == 0)
			rc = MB_SetAccessMode(b_Purchase, MB_MODE_IDLE);
	if(FLAME_Purchase_message_board_write == 1 &&
		FLAME_Purchase_message_board_read == 0)
			rc = MB_SetAccessMode(b_Purchase, MB_MODE_WRITEONLY);
	if(FLAME_Purchase_message_board_write == 0 &&
		FLAME_Purchase_message_board_read == 1)
			rc = MB_SetAccessMode(b_Purchase, MB_MODE_READONLY);
	if(FLAME_Purchase_message_board_write == 1 &&
		FLAME_Purchase_message_board_read == 1)
			rc = MB_SetAccessMode(b_Purchase, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'Purchase' board\n");
	   switch(rc) {
		   case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'Purchase' board is invalid\n");
			   break;
		   case MB_ERR_LOCKED:
			   fprintf(stderr, "\t reason: 'Purchase' board is locked\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	
	
	/* Start timing */
	start = get_time();

	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{
		interval = get_time();

		/* Print out iteration number */
		
		fprintf(stdout, "Iteration - %d\n", iteration_loop);
		(void)fflush(stdout);
        
		/* START OF ITERATION */
		
		/* Start sync message boards that don't write */
		if(FLAME_PurchaseQuality_message_board_write == 0)
		{
			/*printf("%d> PurchaseQuality message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_PurchaseQuality)\n");
			rc = MB_SyncStart(b_PurchaseQuality);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_PurchaseQuality)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'PurchaseQuality' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'PurchaseQuality' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'PurchaseQuality' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_Purchase_message_board_write == 0)
		{
			/*printf("%d> Purchase message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_Purchase)\n");
			rc = MB_SyncStart(b_Purchase);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_Purchase)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'Purchase' board\n");
			   switch(rc) {
				   case MB_ERR_INVALID:
					   fprintf(stderr, "\t reason: 'Purchase' board is invalid\n");
					   break;
				   case MB_ERR_LOCKED:
					   fprintf(stderr, "\t reason: 'Purchase' board is locked\n");
					   break;
				   case MB_ERR_MEMALLOC:
					   fprintf(stderr, "\t reason: out of memory\n");
					   break;
				   case MB_ERR_INTERNAL:
					   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
					   break;
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		

	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start b_send_message\n");
	current_xmachine_buyer_holder = buyer_start_state->agents;
	while(current_xmachine_buyer_holder)
	{
		temp_xmachine_buyer_holder = current_xmachine_buyer_holder->next;
		current_xmachine_buyer = current_xmachine_buyer_holder->agent;
		current_xmachine_buyer_next_state = buyer_01_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_buyer = NULL;
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_buyer = current_xmachine_buyer;

		

		

			i = b_send_message();

		

			if(i == 1)
			{
				free_buyer_agent(current_xmachine_buyer_holder, buyer_start_state);
			}
			else
			{
				transition_buyer_agent(current_xmachine_buyer_holder, buyer_start_state, buyer_01_state);
			}
		

		current_xmachine_buyer = NULL;

		current_xmachine_buyer_holder = temp_xmachine_buyer_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish b_send_message\n");

	if(FLAME_Purchase_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_Purchase)\n");
		rc = MB_SyncStart(b_Purchase);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_Purchase)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'Purchase' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'Purchase' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'Purchase' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start f_idle\n");
	current_xmachine_firm_holder = firm_start_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_01_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_buyer = NULL;
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = f_idle();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_start_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_start_state, firm_01_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish f_idle\n");


/* End of layer number 0 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_Purchase_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_Purchase)\n");
		rc = MB_SyncComplete(b_Purchase);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_Purchase)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'Purchase' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'Purchase' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start f_receive_messages\n");
	current_xmachine_firm_holder = firm_01_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_02_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_buyer = NULL;
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_Purchase, &i_Purchase, &FLAME_filter_firm_f_receive_messages_01_02_Purchase, current_xmachine_firm);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'Purchase'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'Purchase' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'Purchase' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = f_receive_messages();

		
		    rc = MB_Iterator_Delete(&i_Purchase);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'Purchase' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'Purchase' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_01_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_01_state, firm_02_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish f_receive_messages\n");


/* End of layer number 1 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_Purchase_message_board_read == 0)
{
	/*printf("%d> Purchase message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_Purchase)\n");
	rc = MB_SyncComplete(b_Purchase);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_Purchase)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'Purchase' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'Purchase' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_Purchase);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'Purchase' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'Purchase' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'Purchase' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start f_send_message\n");
	current_xmachine_firm_holder = firm_02_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		current_xmachine_firm = current_xmachine_firm_holder->agent;
		current_xmachine_firm_next_state = firm_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_buyer = NULL;
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_firm = current_xmachine_firm;

		

		

			i = f_send_message();

		

			if(i == 1)
			{
				free_firm_agent(current_xmachine_firm_holder, firm_02_state);
			}
			else
			{
				transition_firm_agent(current_xmachine_firm_holder, firm_02_state, firm_end_state);
			}
		

		current_xmachine_firm = NULL;

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish f_send_message\n");

	if(FLAME_PurchaseQuality_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_PurchaseQuality)\n");
		rc = MB_SyncStart(b_PurchaseQuality);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_PurchaseQuality)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'PurchaseQuality' board\n");
		   switch(rc) {
			   case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'PurchaseQuality' board is invalid\n");
				   break;
			   case MB_ERR_LOCKED:
				   fprintf(stderr, "\t reason: 'PurchaseQuality' board is locked\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 2 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_PurchaseQuality_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_PurchaseQuality)\n");
		rc = MB_SyncComplete(b_PurchaseQuality);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_PurchaseQuality)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'PurchaseQuality' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'PurchaseQuality' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start b_receive_messages\n");
	current_xmachine_buyer_holder = buyer_01_state->agents;
	while(current_xmachine_buyer_holder)
	{
		temp_xmachine_buyer_holder = current_xmachine_buyer_holder->next;
		current_xmachine_buyer = current_xmachine_buyer_holder->agent;
		current_xmachine_buyer_next_state = buyer_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_buyer = NULL;
		current_xmachine->xmachine_firm = NULL;
		current_xmachine->xmachine_buyer = current_xmachine_buyer;

		

		
		
          
                  
          
		    rc = MB_Iterator_CreateFiltered(b_PurchaseQuality, &i_PurchaseQuality, &FLAME_filter_buyer_b_receive_messages_01_end_PurchaseQuality, current_xmachine_buyer);
		    
		  
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'PurchaseQuality'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'PurchaseQuality' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'PurchaseQuality' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = b_receive_messages();

		
		    rc = MB_Iterator_Delete(&i_PurchaseQuality);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'PurchaseQuality' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'PurchaseQuality' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_buyer_agent(current_xmachine_buyer_holder, buyer_01_state);
			}
			else
			{
				transition_buyer_agent(current_xmachine_buyer_holder, buyer_01_state, buyer_end_state);
			}
		

		current_xmachine_buyer = NULL;

		current_xmachine_buyer_holder = temp_xmachine_buyer_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish b_receive_messages\n");


/* End of layer number 3 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_PurchaseQuality_message_board_read == 0)
{
	/*printf("%d> PurchaseQuality message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_PurchaseQuality)\n");
	rc = MB_SyncComplete(b_PurchaseQuality);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_PurchaseQuality)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'PurchaseQuality' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'PurchaseQuality' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

    rc = MB_Clear(b_PurchaseQuality);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'PurchaseQuality' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'PurchaseQuality' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'PurchaseQuality' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif



	/*printf("buyer_start_state->count = %d\n", buyer_start_state->count);*/
	buyer_start_state->count = 0;

	/*printf("buyer_end_state->count = %d\n", buyer_end_state->count);*/
	buyer_end_state->count = 0;

	/*printf("buyer_01_state->count = %d\n", buyer_01_state->count);*/
	buyer_01_state->count = 0;

	/*printf("firm_01_state->count = %d\n", firm_01_state->count);*/
	firm_01_state->count = 0;

	/*printf("firm_start_state->count = %d\n", firm_start_state->count);*/
	firm_start_state->count = 0;

	/*printf("firm_end_state->count = %d\n", firm_end_state->count);*/
	firm_end_state->count = 0;

	/*printf("firm_02_state->count = %d\n", firm_02_state->count);*/
	firm_02_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_buyer_holder = buyer_end_state->agents;
	while(current_xmachine_buyer_holder)
	{
		temp_xmachine_buyer_holder = current_xmachine_buyer_holder->next;
		transition_buyer_agent(current_xmachine_buyer_holder, buyer_end_state, buyer_start_state);

		current_xmachine_buyer_holder = temp_xmachine_buyer_holder;
	}

	current_xmachine_firm_holder = firm_end_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		transition_firm_agent(current_xmachine_firm_holder, firm_end_state, firm_start_state);

		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}

    if(iteration_loop%output_frequency == output_offset)
    {
        saveiterationdata(iteration_loop);
    }

		/* Calculate if any agents need to jump S.P. */
		/* propagate_agents(); */
	/* Save iteration time to log file */

		if((file = fopen(logfilepath, "a"))==NULL)
		{
			printf("Error: cannot open file '%s' for writing\n", logfilepath);
			exit(0);
		}
		(void)fputs("<iteration><no>", file);
		sprintf(data, "%i", iteration_loop);
		(void)fputs(data, file);
		(void)fputs("</no><time>", file);
		sprintf(data, "%d", (int)((get_time() - interval) * 1000) );
		(void)fputs(data, file);
		(void)fputs("</time></iteration>\n", file);
		(void)fclose(file);

	}

    

	/* Stop timing and print total time */
	stop = get_time();
	total_time = stop - start;
	printf("Execution time - %d:%02d:%03d [mins:secs:msecs]\n",
       (int)(total_time/60), ((int)total_time)%60, (((int)(total_time * 1000.0)) % 1000));

	clean_up(0);

	/* Exit successfully by returning zero to Operating System */
	return 0;
}
