/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

/** \fn int FLAME_integer_in_array(int a, int * b, int size)
 * \brief Returns 1 if an integer is a member of an integer array, else 0
 * \param a The integer to check.
 * \param b Pointer to the integer array.
 * \param size The size of the array
 * \return 1 for true, 0 for false.
 */
int FLAME_integer_in_array(int a, int * b, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		if(a == b[i]) return 1;
	}
	
	return 0;
}

/** \fn void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
 * \brief Create memory to hold agent filter variables for every agent using the filter on the current node.
 * \param agent_number The number of agent types.
 * \param agent_count List of the number of agents of each agent type.
 * \param agent_struct_size The struct size needed for each agent type.
 * \param cparam_size The size of the memory created.
 * \return Pointer to the created memory.
 */
void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
{
	/* Pointer to the memory created that is going to be returned */
	void *data;
	/* Variable used in for loops */
	int i;
	/* Variable to hold total size of memory required for agent structures */
	size_t total_param_size = 0;

	/* For each agent type add required memory for agent structures */
	for(i = 0; i < agent_number; i++)
	{
		total_param_size += agent_count[i] * agent_struct_size[i];
	}

	//assert(count > 0);
	//assert(total_param_size > 0);
	/* Does libmboard free this memory? */
	
	/* Allocate required memory, where memory holds the number
	 * of each agent type, in order, and the total required
	 * memory for agent structures */
	data = malloc(agent_number*sizeof(int) + total_param_size);
	/* Make the memory size parameter equal to the actual memory size */
	*cparam_size = agent_number*sizeof(int) + total_param_size;
	/* Assert that the created memory was successfully created and not null */
	assert(data != NULL);

	/* Return the pointer to the created memory */
	return data;
}


/** \fn int FLAME_condition_overseer_o_send_message_01_end(xmachine_memory_overseer *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_overseer_o_send_message_01_end(xmachine_memory_overseer *a)
{
	if((iteration_loop%10 == 0)) return 1;
	else return 0;
}



/** \fn int FLAME_filter_buyer_b_receive_messages_01_end_PurchaseQuality(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_buyer_b_receive_messages_01_end_PurchaseQuality(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_buyer_b_receive_messages_01_end_PurchaseQuality(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_PurchaseQuality *m = (m_PurchaseQuality*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_buyer *a = (xmachine_memory_buyer *)params;

	/* The filter */
	if((a->my_id == m->id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_f_receive_messages_01_02_Purchase(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_f_receive_messages_01_02_Purchase(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_f_receive_messages_01_02_Purchase(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_Purchase *m = (m_Purchase*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->my_id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_firm_f_receive_strategy_03_end_StrategyAdjustment(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_firm_f_receive_strategy_03_end_StrategyAdjustment(const void *msg, const void *params)
{
	//printf("**** FLAME_filter_firm_f_receive_strategy_03_end_StrategyAdjustment(const void *msg, const void *params)\n");
	
	/* Cast the message pointer to the correct message type */
	m_StrategyAdjustment *m = (m_StrategyAdjustment*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_firm *a = (xmachine_memory_firm *)params;

	/* The filter */
	if((a->my_id == m->firm_id)) return 1;
	else return 0;
}



