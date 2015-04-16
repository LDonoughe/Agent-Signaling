/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"


void unittest_b_receive_messages_01_end()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return b_receive_messages();
}

void unittest_b_send_message_start_01()
{
	
	
	//return b_send_message();
}

void unittest_f_send_message_02_03()
{
	
	
	//return f_send_message();
}

void unittest_f_idle_start_01()
{
	
	
	//return f_idle();
}

void unittest_f_receive_messages_01_02()
{
	int rc;
	
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
	   }
	}
	#endif
	
	//return f_receive_messages();
}

void unittest_f_receive_strategy_03_end()
{
	int rc;
	
	rc = MB_Iterator_CreateFiltered(b_StrategyAdjustment, &i_StrategyAdjustment, &FLAME_filter_firm_f_receive_strategy_03_end_StrategyAdjustment, current_xmachine_firm);
	
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'StrategyAdjustment'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'StrategyAdjustment' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'StrategyAdjustment' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return f_receive_strategy();
}

void unittest_o_receive_messages_start_01()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_PurchaseQuality, &i_PurchaseQuality);
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
	   }
	}
	#endif
	
	//return o_receive_messages();
}

void unittest_o_send_message_01_end()
{
	
	
	//return o_send_message();
}


void free_messages()
{
	int rc;
	
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
	
	    rc = MB_Clear(b_StrategyAdjustment);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'StrategyAdjustment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'StrategyAdjustment' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'StrategyAdjustment' board is locked\n");
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
	
}

/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
int rc;

	/* Initialise message sync composite params as NULL */
	FLAME_m_PurchaseQuality_composite_params = NULL;

	    rc = MB_Create(&b_PurchaseQuality, sizeof(m_PurchaseQuality));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'PurchaseQuality' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_Purchase_composite_params = NULL;

	    rc = MB_Create(&b_Purchase, sizeof(m_Purchase));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'Purchase' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_StrategyAdjustment_composite_params = NULL;

	    rc = MB_Create(&b_StrategyAdjustment, sizeof(m_StrategyAdjustment));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'StrategyAdjustment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	buyer_start_state = init_buyer_state();

	buyer_end_state = init_buyer_state();

	buyer_01_state = init_buyer_state();

	firm_end_state = init_firm_state();

	firm_01_state = init_firm_state();

	firm_start_state = init_firm_state();

	firm_03_state = init_firm_state();

	firm_02_state = init_firm_state();

	overseer_end_state = init_overseer_state();

	overseer_01_state = init_overseer_state();

	overseer_start_state = init_overseer_state();

	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/** \fn void initialise_unit_testing()
 * \brief Initialises framework for unit testing.
 */
void initialise_unit_testing()
{
	int rc;

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

	initialise_pointers();
}

FLAME_output * add_FLAME_output(FLAME_output ** outputs)
{
	FLAME_output * current;

	current = (FLAME_output *)malloc(sizeof(FLAME_output));
	CHECK_POINTER(current);
	current->next = *outputs;
	*outputs = current;

	current->type = -1;
	current->format = -1;
	current->location = NULL;
	current->period = -1;
	current->phase = -1;
	current->flag = 0;

	return current;
}

void free_FLAME_outputs(FLAME_output ** outputs)
{
	FLAME_output * current, * next;

	current = *outputs;
	while(current)
	{
		next = current->next;
		free(current->location);
		free(current);
		current = next;
	}
	*outputs = NULL;
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;

	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}

	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}

	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_location = NULL;
}

void init_int_static_array(/*@out@*/ int * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0;
}

void init_float_static_array(/*@out@*/ float * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_double_static_array(/*@out@*/ double* array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_char_static_array(/*@out@*/ char * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = '\0';
}




xmachine_memory_buyer_state * init_buyer_state()
{
	xmachine_memory_buyer_state * current = (xmachine_memory_buyer_state *)malloc(sizeof(xmachine_memory_buyer_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_buyer * init_buyer_agent()
{
	xmachine_memory_buyer * current = (xmachine_memory_buyer *)malloc(sizeof(xmachine_memory_buyer));
	CHECK_POINTER(current);

	current->my_id = 0;
	current->firm_id = 0;
	current->my_qual = 0;

	return current;
}

void free_buyer_agent(xmachine_memory_buyer_holder * tmp, xmachine_memory_buyer_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_buyer_agent()
{
	current_xmachine_buyer = (xmachine_memory_buyer *)malloc(sizeof(xmachine_memory_buyer));
	CHECK_POINTER(current);

		current_xmachine_buyer->my_id = 0;
		current_xmachine_buyer->firm_id = 0;
		current_xmachine_buyer->my_qual = 0;
	
}

void unittest_free_buyer_agent()
{
	
	free(current_xmachine_buyer);
}

void free_buyer_agents()
{
	current_xmachine_buyer_holder = buyer_start_state->agents;
	while(current_xmachine_buyer_holder)
	{
		temp_xmachine_buyer_holder = current_xmachine_buyer_holder->next;
		free_buyer_agent(current_xmachine_buyer_holder, buyer_start_state);
		current_xmachine_buyer_holder = temp_xmachine_buyer_holder;
	}
	buyer_start_state->count = 0;
	current_xmachine_buyer_holder = buyer_end_state->agents;
	while(current_xmachine_buyer_holder)
	{
		temp_xmachine_buyer_holder = current_xmachine_buyer_holder->next;
		free_buyer_agent(current_xmachine_buyer_holder, buyer_end_state);
		current_xmachine_buyer_holder = temp_xmachine_buyer_holder;
	}
	buyer_end_state->count = 0;
	current_xmachine_buyer_holder = buyer_01_state->agents;
	while(current_xmachine_buyer_holder)
	{
		temp_xmachine_buyer_holder = current_xmachine_buyer_holder->next;
		free_buyer_agent(current_xmachine_buyer_holder, buyer_01_state);
		current_xmachine_buyer_holder = temp_xmachine_buyer_holder;
	}
	buyer_01_state->count = 0;
}

void free_buyer_states()
{
	free(buyer_start_state);
	free(buyer_end_state);
	free(buyer_01_state);
}

void transition_buyer_agent(xmachine_memory_buyer_holder * tmp, xmachine_memory_buyer_state * from_state, xmachine_memory_buyer_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_buyer_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_buyer_agent_internal(xmachine_memory_buyer * agent, xmachine_memory_buyer_state * state)
{
	xmachine_memory_buyer_holder * current = (xmachine_memory_buyer_holder *)malloc(sizeof(xmachine_memory_buyer_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_buyer_agent(int my_id, int firm_id, int my_qual)
 * \brief Add buyer X-machine to the current being used X-machine list.
 * \param my_id Variable for the X-machine memory.
 * \param firm_id Variable for the X-machine memory.
 * \param my_qual Variable for the X-machine memory.
 */
void add_buyer_agent(int my_id, int firm_id, int my_qual)
{
	xmachine_memory_buyer * current;

	current = init_buyer_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_buyer_next_state = buyer_start_state;
	add_buyer_agent_internal(current, current_xmachine_buyer_next_state);

	current->my_id = my_id;
	current->firm_id = firm_id;
	current->my_qual = my_qual;
}

xmachine_memory_firm_state * init_firm_state()
{
	xmachine_memory_firm_state * current = (xmachine_memory_firm_state *)malloc(sizeof(xmachine_memory_firm_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_firm * init_firm_agent()
{
	xmachine_memory_firm * current = (xmachine_memory_firm *)malloc(sizeof(xmachine_memory_firm));
	CHECK_POINTER(current);

	init_int_static_array(current->buyer_ids, 100);
	current->my_id = 0;
	current->quality = 0.0;
	current->stored_id = 0;

	return current;
}

void free_firm_agent(xmachine_memory_firm_holder * tmp, xmachine_memory_firm_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_firm_agent()
{
	current_xmachine_firm = (xmachine_memory_firm *)malloc(sizeof(xmachine_memory_firm));
	CHECK_POINTER(current);

		init_int_static_array(current_xmachine_firm->buyer_ids, 100);
		current_xmachine_firm->my_id = 0;
		current_xmachine_firm->quality = 0.0;
		current_xmachine_firm->stored_id = 0;
	
}

void unittest_free_firm_agent()
{
	
	free(current_xmachine_firm);
}

void free_firm_agents()
{
	current_xmachine_firm_holder = firm_end_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_end_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_end_state->count = 0;
	current_xmachine_firm_holder = firm_01_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_01_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_01_state->count = 0;
	current_xmachine_firm_holder = firm_start_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_start_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_start_state->count = 0;
	current_xmachine_firm_holder = firm_03_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_03_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_03_state->count = 0;
	current_xmachine_firm_holder = firm_02_state->agents;
	while(current_xmachine_firm_holder)
	{
		temp_xmachine_firm_holder = current_xmachine_firm_holder->next;
		free_firm_agent(current_xmachine_firm_holder, firm_02_state);
		current_xmachine_firm_holder = temp_xmachine_firm_holder;
	}
	firm_02_state->count = 0;
}

void free_firm_states()
{
	free(firm_end_state);
	free(firm_01_state);
	free(firm_start_state);
	free(firm_03_state);
	free(firm_02_state);
}

void transition_firm_agent(xmachine_memory_firm_holder * tmp, xmachine_memory_firm_state * from_state, xmachine_memory_firm_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_firm_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_firm_agent_internal(xmachine_memory_firm * agent, xmachine_memory_firm_state * state)
{
	xmachine_memory_firm_holder * current = (xmachine_memory_firm_holder *)malloc(sizeof(xmachine_memory_firm_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_firm_agent(int buyer_ids[], int my_id, float quality, int stored_id)
 * \brief Add firm X-machine to the current being used X-machine list.
 * \param buyer_ids Variable for the X-machine memory.
 * \param my_id Variable for the X-machine memory.
 * \param quality Variable for the X-machine memory.
 * \param stored_id Variable for the X-machine memory.
 */
void add_firm_agent(int buyer_ids[], int my_id, float quality, int stored_id)
{
	xmachine_memory_firm * current;

	current = init_firm_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_firm_next_state = firm_start_state;
	add_firm_agent_internal(current, current_xmachine_firm_next_state);

	memcpy(current->buyer_ids, buyer_ids, 100*sizeof(int));
	current->my_id = my_id;
	current->quality = quality;
	current->stored_id = stored_id;
}

xmachine_memory_overseer_state * init_overseer_state()
{
	xmachine_memory_overseer_state * current = (xmachine_memory_overseer_state *)malloc(sizeof(xmachine_memory_overseer_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_overseer * init_overseer_agent()
{
	xmachine_memory_overseer * current = (xmachine_memory_overseer *)malloc(sizeof(xmachine_memory_overseer));
	CHECK_POINTER(current);

	init_int_static_array(current->firm_revenues, 10);
	init_float_static_array(current->firm_strategies, 10);

	return current;
}

void free_overseer_agent(xmachine_memory_overseer_holder * tmp, xmachine_memory_overseer_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_overseer_agent()
{
	current_xmachine_overseer = (xmachine_memory_overseer *)malloc(sizeof(xmachine_memory_overseer));
	CHECK_POINTER(current);

		init_int_static_array(current_xmachine_overseer->firm_revenues, 10);
		init_float_static_array(current_xmachine_overseer->firm_strategies, 10);
	
}

void unittest_free_overseer_agent()
{
	
	free(current_xmachine_overseer);
}

void free_overseer_agents()
{
	current_xmachine_overseer_holder = overseer_end_state->agents;
	while(current_xmachine_overseer_holder)
	{
		temp_xmachine_overseer_holder = current_xmachine_overseer_holder->next;
		free_overseer_agent(current_xmachine_overseer_holder, overseer_end_state);
		current_xmachine_overseer_holder = temp_xmachine_overseer_holder;
	}
	overseer_end_state->count = 0;
	current_xmachine_overseer_holder = overseer_01_state->agents;
	while(current_xmachine_overseer_holder)
	{
		temp_xmachine_overseer_holder = current_xmachine_overseer_holder->next;
		free_overseer_agent(current_xmachine_overseer_holder, overseer_01_state);
		current_xmachine_overseer_holder = temp_xmachine_overseer_holder;
	}
	overseer_01_state->count = 0;
	current_xmachine_overseer_holder = overseer_start_state->agents;
	while(current_xmachine_overseer_holder)
	{
		temp_xmachine_overseer_holder = current_xmachine_overseer_holder->next;
		free_overseer_agent(current_xmachine_overseer_holder, overseer_start_state);
		current_xmachine_overseer_holder = temp_xmachine_overseer_holder;
	}
	overseer_start_state->count = 0;
}

void free_overseer_states()
{
	free(overseer_end_state);
	free(overseer_01_state);
	free(overseer_start_state);
}

void transition_overseer_agent(xmachine_memory_overseer_holder * tmp, xmachine_memory_overseer_state * from_state, xmachine_memory_overseer_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_overseer_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_overseer_agent_internal(xmachine_memory_overseer * agent, xmachine_memory_overseer_state * state)
{
	xmachine_memory_overseer_holder * current = (xmachine_memory_overseer_holder *)malloc(sizeof(xmachine_memory_overseer_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_overseer_agent(int firm_revenues[], float firm_strategies[])
 * \brief Add overseer X-machine to the current being used X-machine list.
 * \param firm_revenues Variable for the X-machine memory.
 * \param firm_strategies Variable for the X-machine memory.
 */
void add_overseer_agent(int firm_revenues[], float firm_strategies[])
{
	xmachine_memory_overseer * current;

	current = init_overseer_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_overseer_next_state = overseer_start_state;
	add_overseer_agent_internal(current, current_xmachine_overseer_next_state);

	memcpy(current->firm_revenues, firm_revenues, 10*sizeof(int));
	memcpy(current->firm_strategies, firm_strategies, 10*sizeof(float));
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_buyer_agents();
	free_firm_agents();
	free_overseer_agents();
	
}


/** \fn void set_my_id(int my_id)
 * \brief Set my_id memory variable for current X-machine.
 * \param my_id New value for variable.
 */
void set_my_id(int my_id)
{
	if(current_xmachine->xmachine_buyer) (*current_xmachine->xmachine_buyer).my_id = my_id;
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).my_id = my_id;
}

/** \fn int get_my_id()
 * \brief Get my_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_my_id()
{
	if(current_xmachine->xmachine_buyer) return (*current_xmachine->xmachine_buyer).my_id;
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).my_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_firm_id(int firm_id)
 * \brief Set firm_id memory variable for current X-machine.
 * \param firm_id New value for variable.
 */
void set_firm_id(int firm_id)
{
	if(current_xmachine->xmachine_buyer) (*current_xmachine->xmachine_buyer).firm_id = firm_id;
}

/** \fn int get_firm_id()
 * \brief Get firm_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_firm_id()
{
	if(current_xmachine->xmachine_buyer) return (*current_xmachine->xmachine_buyer).firm_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_my_qual(int my_qual)
 * \brief Set my_qual memory variable for current X-machine.
 * \param my_qual New value for variable.
 */
void set_my_qual(int my_qual)
{
	if(current_xmachine->xmachine_buyer) (*current_xmachine->xmachine_buyer).my_qual = my_qual;
}

/** \fn int get_my_qual()
 * \brief Get my_qual memory variable from current X-machine.
 * \return Value for variable.
 */
int get_my_qual()
{
	if(current_xmachine->xmachine_buyer) return (*current_xmachine->xmachine_buyer).my_qual;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn int get_buyer_ids()
 * \brief Get buyer_ids memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_buyer_ids()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).buyer_ids;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_quality(float quality)
 * \brief Set quality memory variable for current X-machine.
 * \param quality New value for variable.
 */
void set_quality(float quality)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).quality = quality;
}

/** \fn float get_quality()
 * \brief Get quality memory variable from current X-machine.
 * \return Value for variable.
 */
float get_quality()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).quality;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (float)0;
}

/** \fn void set_stored_id(int stored_id)
 * \brief Set stored_id memory variable for current X-machine.
 * \param stored_id New value for variable.
 */
void set_stored_id(int stored_id)
{
	if(current_xmachine->xmachine_firm) (*current_xmachine->xmachine_firm).stored_id = stored_id;
}

/** \fn int get_stored_id()
 * \brief Get stored_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_stored_id()
{
	if(current_xmachine->xmachine_firm) return (*current_xmachine->xmachine_firm).stored_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn int get_firm_revenues()
 * \brief Get firm_revenues memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_firm_revenues()
{
	if(current_xmachine->xmachine_overseer) return (*current_xmachine->xmachine_overseer).firm_revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn float get_firm_strategies()
 * \brief Get firm_strategies memory variable from current X-machine.
 * \return Value for variable.
 */
float * get_firm_strategies()
{
	if(current_xmachine->xmachine_overseer) return (*current_xmachine->xmachine_overseer).firm_strategies;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_buyer) value = current_xmachine->xmachine_buyer->;*/
    /*if (current_xmachine->xmachine_firm) value = current_xmachine->xmachine_firm->;*/
    /*if (current_xmachine->xmachine_overseer) value = current_xmachine->xmachine_overseer->;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_buyer) value = current_xmachine->xmachine_buyer->;*/
    /*if (current_xmachine->xmachine_firm) value = current_xmachine->xmachine_firm->;*/
    /*if (current_xmachine->xmachine_overseer) value = current_xmachine->xmachine_overseer->;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_buyer) value = current_xmachine->xmachine_buyer->0.0;*/
    /*if (current_xmachine->xmachine_firm) value = current_xmachine->xmachine_firm->0.0;*/
    /*if (current_xmachine->xmachine_overseer) value = current_xmachine->xmachine_overseer->0.0;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_buyer) value = current_xmachine->xmachine_buyer->0.0;*/
    /*if (current_xmachine->xmachine_firm) value = current_xmachine->xmachine_firm->0.0;*/
    /*if (current_xmachine->xmachine_overseer) value = current_xmachine->xmachine_overseer->0.0;*/

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}

/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;

	while(current)
	{
		tmp = current;
		current = current->next;
	}

	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}

	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->PurchaseQuality_messages = NULL;
	current->Purchase_messages = NULL;
	current->StrategyAdjustment_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_node_info = NULL;
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
    int rc;
	FILE *file;
	char data[100];

	free(current_xmachine);
	/* Free x-machine memory */
	freexmachines();
	/* Free space partitions linked list */
	free_node_info();
	/* Free output list */
	free_FLAME_outputs(&FLAME_outputs);
	/* Free agent states */
	free_buyer_states();
	free_firm_states();
	free_overseer_states();


	/* Free index maps */


	/* Free message boards */

	rc = MB_Delete(&b_PurchaseQuality);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'PurchaseQuality' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'PurchaseQuality' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'PurchaseQuality' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_Purchase);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'Purchase' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'Purchase' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'Purchase' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_StrategyAdjustment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'StrategyAdjustment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'StrategyAdjustment' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'StrategyAdjustment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif


    rc = MB_Env_Finalise();
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not finalise MB environment\n");
       switch(rc) {
           case MB_ERR_ENV:
               fprintf(stderr, "\t reason: MB environment not yet started?\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Env_Finalise returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif



	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<!-- <totaltime> unit: seconds -->\n", file);
	fputs("<totaltime>", file);
	sprintf(data, "%.3f", total_time);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);


	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");

		printf(" ***");
		exit(0);
	}
}


/** \fn void propagate_agents()
 * \brief Check agent positions to see if any need to be moved to a another node.
 */
void propagate_agents()
{
/*	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_buyer != NULL)
		{
			x_xmachine = current_xmachine->xmachine_buyer->0.0;
			y_xmachine = current_xmachine->xmachine_buyer->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_firm->0.0;
			y_xmachine = current_xmachine->xmachine_firm->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_overseer != NULL)
		{
			x_xmachine = current_xmachine->xmachine_overseer->0.0;
			y_xmachine = current_xmachine->xmachine_overseer->0.0;
			z_xmachine = 0.0;
		}

		if(x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5])
		{
			node_info = *p_node_info;
			while(node_info)
			{
				if(node_info->node_id != current_node->node_id &&
				node_info->partition_data[0] < x_xmachine && node_info->partition_data[1] > x_xmachine &&
				node_info->partition_data[2] < y_xmachine && node_info->partition_data[3] > y_xmachine &&
				node_info->partition_data[4] < z_xmachine && node_info->partition_data[5] > z_xmachine)
				{
                    // Remove agent
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    // Add agent
                    p_temp_xmachine = &node_info->agents;
                    temp_xmachine = *p_temp_xmachine;
                    current_xmachine->next = temp_xmachine;
                    *p_temp_xmachine = current_xmachine;
                    node_info->agent_total++;
                    node_info = NULL;
				}
				else node_info = node_info->next;
				}
			}
			else before_xmachine = current_xmachine;

			if(before_xmachine) current_xmachine = before_xmachine->next;
			else current_xmachine = NULL;
		}*/
}


/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
void init_int_array(int_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	(*array).size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free((*array).array);
}

void copy_int_array(int_array * from, int_array * to)
{
	int i;
	//to = init_int_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_int(to, (*from).array[i]);
	}
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
/*void sort_int_array(int_array * array)
{
	int i, j, temp;

	for(i=0; i<((*array).size-1); i++)
	{
		for(j=0; j<((*array).size-1)-i; j++)
		{
			if(*((*array).array+j+1) < *((*array).array+j))
			{
                temp = *((*array).(*array)+j);
                *((*array).array+j) = *((*array).array+j+1);
                *((*array).array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_int(int array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (int *)realloc((*array).array, ((*array).total_size * sizeof(int)));
	}
	(*array).array[(*array).size] = new_int;
	(*array).size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;

	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %d", i, (*array).array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
void init_float_array(float_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	(*array).size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free((*array).array);
}

void copy_float_array(float_array * from, float_array * to)
{
	int i;
	//to = init_float_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_float(to, (*from).array[i]);
	}
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
/*void sort_float_array(float_array array)
{
	int i, j;
	float temp;
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_float(float array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (float *)realloc((*array).array, ((*array).total_size * sizeof(float)));
	}
	(*array).array[(*array).size] = new_float;
	(*array).size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;

	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
void init_double_array(double_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	(*array).size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free((*array).array);
}

void copy_double_array(double_array * from, double_array * to)
{
	int i;
	//to = init_double_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_double(to, (*from).array[i]);
	}
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
/*void sort_double_array(double_array array)
{
	int i, j;
	double temp;

	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_double(double array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (double *)realloc((*array).array, ((*array).total_size * sizeof(double)));
	}
	(*array).array[(*array).size] = new_double;
	(*array).size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
void init_char_array(char_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
	CHECK_POINTER((*array).array);
	(*array).array[0] = '\0';
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	(*array).size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free((*array).array);
}

void copy_char_array(char_array * from, char_array * to)
{
	int i;

	for (i = 0; i < (*from).size; i++)
	{
		add_char(to, (*from).array[i]);
	}
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if((*array).size + 1 == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (char *)realloc((*array).array, ((*array).total_size * sizeof(char)));
	}
	(*array).array[(*array).size] = new_char;
	(*array).array[(*array).size + 1] = '\0';
	(*array).size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( ((*array).size + 1) * sizeof(char));
	CHECK_POINTER(new_string);
	return strcpy(new_string, (*array).array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", (*array).array);
}


/** \fn int idle()
 * \brief an idle function for use by agents.
 */
int idle()
{
	return 0;
}



