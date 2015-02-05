/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */
#ifndef _HEADER_H
#define _HEADER_H

#ifdef _DEBUG_MODE
    #define ERRCHECK
#else
    #define NDEBUG
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "mboard.h"

#define FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS 0
#define FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS 0
#define FLAME_USE_FILTERS_IN_SYNC 1


/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT)
#endif


/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 10
/** \def ARRAY_GROWTH_RATE
 * \brief Growth ratio to scale size of dynamic arrays. 
 * Use golden ratio. This makes for a Fibonacci sequence, so the next allocation size 
 * is the sum of the current size and the previous size thus improving the chance of 
 * memory block reuse. It also allows for moderate rate of growth.
 */
#define ARRAY_GROWTH_RATE 1.618034
/** \def START_PURCHASEQUALITY_MESSAGE_LOOP
 * \brief Start of loop to process PurchaseQuality messages. */
#define START_PURCHASEQUALITY_MESSAGE_LOOP  for(PurchaseQuality_message = get_first_PurchaseQuality_message(); PurchaseQuality_message != NULL; PurchaseQuality_message = get_next_PurchaseQuality_message(PurchaseQuality_message)) {
/** \def FINISH_PURCHASEQUALITY_MESSAGE_LOOP
 * \brief Finish of loop to process PurchaseQuality messages. */
#define FINISH_PURCHASEQUALITY_MESSAGE_LOOP }
/** \def START_PURCHASE_MESSAGE_LOOP
 * \brief Start of loop to process Purchase messages. */
#define START_PURCHASE_MESSAGE_LOOP  for(Purchase_message = get_first_Purchase_message(); Purchase_message != NULL; Purchase_message = get_next_Purchase_message(Purchase_message)) {
/** \def FINISH_PURCHASE_MESSAGE_LOOP
 * \brief Finish of loop to process Purchase messages. */
#define FINISH_PURCHASE_MESSAGE_LOOP }


struct FLAME_output
{
	int type; /* 0=snapshot 1=buyer 2=firm */
	int format; /* 0=XML */
	char * location;
	int period;
	int phase;
	int flag; /* Used when outputting to show it has been used */

	struct FLAME_output * next;
};
typedef struct FLAME_output FLAME_output;

/** \struct int_array
 * \brief Dynamic array to hold integers.
 *
 * Holds a pointer to an integer array and values for size and memory size.
 */
struct int_array
{
	int size;
	int total_size;

	int * array;
};

/** \struct float_array
 * \brief Dynamic array to hold floats.
 *
 * Holds a pointer to an float array and values for size and memory size.
 */
struct float_array
{
	int size;
	int total_size;

	float * array;
};

/** \struct double_array
 * \brief Dynamic array to hold doubles.
 *
 * Holds a pointer to a double array and values for size and memory size.
 */
struct double_array
{
	int size;
	int total_size;

	double * array;
};

/** \struct char_array
 * \brief Dynamic array to hold chars.
 *
 * Holds a pointer to a char array and values for size and memory size.
 */
struct char_array
{
	int size;
	int total_size;

	char * array;
};

/** \typedef struct int_array int_array
 * \brief Typedef for int_array struct.
 */
typedef struct int_array int_array;
/** \typedef struct float_array float_array
 * \brief Typedef for float_array struct.
 */
typedef struct float_array float_array;
/** \typedef struct double_array double_array
 * \brief Typedef for double_array struct.
 */
typedef struct double_array double_array;
/** \typedef struct char_array char_array
 * \brief Typedef for char_array struct.
 */
typedef struct char_array char_array;


/** \struct xmachine_memory_buyer
 * \brief Holds memory of xmachine buyer.
 */
struct xmachine_memory_buyer
{
	int my_id;	/**< X-machine memory variable my_id of type int. */
	int firm_id;	/**< X-machine memory variable firm_id of type int. */
	int my_qual;	/**< X-machine memory variable my_qual of type int. */
};

/** \struct xmachine_memory_buyer_holder
 * \brief Holds struct of memory of xmachine buyer.
 */
struct xmachine_memory_buyer_holder
{
	/*@dependent@*/ struct xmachine_memory_buyer * agent;	/**< Pointer to X-machine memory buyer. */

	/*@dependent@*/ struct xmachine_memory_buyer_holder * prev;	/**< Pointer to previous buyer agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_buyer_holder * next;	/**< Pointer to next buyer agent in the list.  */
};

/** \struct xmachine_memory_buyer_holder
 * \brief Holds struct of memory of xmachine buyer.
 */
struct xmachine_memory_buyer_state
{
	/*@dependent@*/ struct xmachine_memory_buyer_holder * agents;	/**< Pointer to X-machine memory buyer. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_firm
 * \brief Holds memory of xmachine firm.
 */
struct xmachine_memory_firm
{
	int buyer_ids[100];	/**< X-machine memory variable buyer_ids of type int. */
	int my_id;	/**< X-machine memory variable my_id of type int. */
	float quality;	/**< X-machine memory variable quality of type float. */
	int stored_id;	/**< X-machine memory variable stored_id of type int. */
};

/** \struct xmachine_memory_firm_holder
 * \brief Holds struct of memory of xmachine firm.
 */
struct xmachine_memory_firm_holder
{
	/*@dependent@*/ struct xmachine_memory_firm * agent;	/**< Pointer to X-machine memory firm. */

	/*@dependent@*/ struct xmachine_memory_firm_holder * prev;	/**< Pointer to previous firm agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_firm_holder * next;	/**< Pointer to next firm agent in the list.  */
};

/** \struct xmachine_memory_firm_holder
 * \brief Holds struct of memory of xmachine firm.
 */
struct xmachine_memory_firm_state
{
	/*@dependent@*/ struct xmachine_memory_firm_holder * agents;	/**< Pointer to X-machine memory firm. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_buyer * xmachine_buyer;	/**< Pointer to X-machine memory of type buyer.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_firm * xmachine_firm;	/**< Pointer to X-machine memory of type firm.  */
};

/** \var void* FLAME_m_PurchaseQuality_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_PurchaseQuality_composite_params;

/** \struct m_PurchaseQuality
 * \brief Holds message of type PurchaseQuality_message.
 */
struct m_PurchaseQuality
{
	int qual;	/**< Message memory variable qual of type int. */
	int id;	/**< Message memory variable id of type int. */
	int seller;	/**< Message memory variable seller of type int. */
};

/** \var void* FLAME_m_Purchase_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_Purchase_composite_params;

/** \struct m_Purchase
 * \brief Holds message of type Purchase_message.
 */
struct m_Purchase
{
	int an_id;	/**< Message memory variable an_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_buyer xmachine_memory_buyer
 * \brief Typedef for xmachine_memory_buyer struct.
 */
typedef struct xmachine_memory_buyer xmachine_memory_buyer;
/** \var typedef xmachine_memory_buyer xmachine_memory_buyer
 * \brief Typedef for xmachine_memory_buyer struct.
 */
typedef struct xmachine_memory_buyer_holder xmachine_memory_buyer_holder;
/** \var typedef xmachine_memory_buyer xmachine_memory_buyer
 * \brief Typedef for xmachine_memory_buyer struct.
 */
typedef struct xmachine_memory_buyer_state xmachine_memory_buyer_state;
/** \var typedef xmachine_memory_firm xmachine_memory_firm
 * \brief Typedef for xmachine_memory_firm struct.
 */
typedef struct xmachine_memory_firm xmachine_memory_firm;
/** \var typedef xmachine_memory_firm xmachine_memory_firm
 * \brief Typedef for xmachine_memory_firm struct.
 */
typedef struct xmachine_memory_firm_holder xmachine_memory_firm_holder;
/** \var typedef xmachine_memory_firm xmachine_memory_firm
 * \brief Typedef for xmachine_memory_firm struct.
 */
typedef struct xmachine_memory_firm_state xmachine_memory_firm_state;
/** \typedef m_PurchaseQuality m_PurchaseQuality
 * \brief Typedef for m_PurchaseQuality struct.
 */
typedef struct m_PurchaseQuality m_PurchaseQuality;

/** \typedef m_Purchase m_Purchase
 * \brief Typedef for m_Purchase struct.
 */
typedef struct m_Purchase m_Purchase;


/** \struct location
 * \brief Holds location for calculating space partitioning .
 */
struct location
{
	double point;		/**< Point on an axis. */

	struct location * next;	/**< Pointer to next location on the list. */
};

/** \struct node_information
 * \brief Holds node information .
 */
struct node_information
{
	int node_id;	/**< Node ID. */
	double partition_data[6];	/**< Defines bounding box. */
	int agents_in_halo;	/**< Number of agents in the halo region. */
	int agent_total;	/**< Total number of agents on the node. */
	struct xmachine * agents;	/**< Pointer to list of X-machines. */
	struct m_PurchaseQuality * PurchaseQuality_messages;	/**< Pointer to PurchaseQuality message list. */
	struct m_Purchase * Purchase_messages;	/**< Pointer to Purchase message list. */

	struct node_information * next;	/**< Pointer to next node on the list. */
};


/** \typedef struct location location
 * \brief Typedef for location struct.
 */
typedef struct location location;
/** \typedef struct node_information node_information
 * \brief Typedef for node_information struct.
 */
typedef struct node_information node_information;

/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_PurchaseQuality * temp_PurchaseQuality_message
* \brief Pointer to m_PurchaseQuality to initialise linked list. */
m_PurchaseQuality * temp_PurchaseQuality_message;
/** \var m_Purchase * temp_Purchase_message
* \brief Pointer to m_Purchase to initialise linked list. */
m_Purchase * temp_Purchase_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[1000]
* \brief Output path for files. */
char outputpath[1000];
/** \var long total_time
* \brief Total time for the simulation run (in seconds) */
double total_time;
/** \var int total_messages
* \brief Total messages sent between nodes for the simulation run */
int total_messages;
/** \var int totalnodes
* \brief Number of nodes */
int totalnodes;
/** \var xmachine ** p_xmachine
* \brief Pointer to first pointer of x-machine memory list */
//xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_buyer * current_xmachine_buyer;
/*@dependent@*/ xmachine_memory_buyer_holder * temp_xmachine_buyer_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_buyer_holder * current_xmachine_buyer_holder;
xmachine_memory_buyer_state * current_xmachine_buyer_next_state; /* New agents added to this state */
/* Pointer to list of buyer agents in state start state */
//xmachine_memory_buyer * temp_xmachine_buyer_start;
xmachine_memory_buyer_state * buyer_start_state;
/* Pointer to list of buyer agents in state end state */
//xmachine_memory_buyer * temp_xmachine_buyer_end;
xmachine_memory_buyer_state * buyer_end_state;
/* Pointer to list of buyer agents in state 01 state */
//xmachine_memory_buyer * temp_xmachine_buyer_01;
xmachine_memory_buyer_state * buyer_01_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_firm * current_xmachine_firm;
/*@dependent@*/ xmachine_memory_firm_holder * temp_xmachine_firm_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_firm_holder * current_xmachine_firm_holder;
xmachine_memory_firm_state * current_xmachine_firm_next_state; /* New agents added to this state */
/* Pointer to list of firm agents in state 01 state */
//xmachine_memory_firm * temp_xmachine_firm_01;
xmachine_memory_firm_state * firm_01_state;
/* Pointer to list of firm agents in state start state */
//xmachine_memory_firm * temp_xmachine_firm_start;
xmachine_memory_firm_state * firm_start_state;
/* Pointer to list of firm agents in state end state */
//xmachine_memory_firm * temp_xmachine_firm_end;
xmachine_memory_firm_state * firm_end_state;
/* Pointer to list of firm agents in state 02 state */
//xmachine_memory_firm * temp_xmachine_firm_02;
xmachine_memory_firm_state * firm_02_state;



MBt_Board b_PurchaseQuality;
MBt_Iterator i_PurchaseQuality;

MBt_Board b_Purchase;
MBt_Iterator i_Purchase;


/** \var m_PurchaseQuality * PurchaseQuality_message
* \brief Pointer to message struct for looping through PurchaseQuality message list */
m_PurchaseQuality * PurchaseQuality_message;
/** \var m_Purchase * Purchase_message
* \brief Pointer to message struct for looping through Purchase message list */
m_Purchase * Purchase_message;
/** \var FLAME_output ** FLAME_outputs
* \brief Pointer to list of outputs */
FLAME_output * FLAME_outputs;
/** \var node_information * p_node_info
* \brief Pointer to first pointer of node list */
node_information ** p_node_info;
/** \var node_information * current_node
* \brief Pointer to current node */
node_information * current_node;

/** \var int iteration_loop
* \brief The current iteration number */
int iteration_loop;
/** \var int output_frequency
* \brief Frequency to output results */
int output_frequency;
/** \var int output_offset
* \brief Offset to output results */
int output_offset;

/** \def SPINF
* \brief Dummy inf value for space partition data. */
#define SPINF 999999.123456
/** \def RELEASE
* \brief Used to kill an agent via 'return RELEASE;'. */
#define RELEASE 1
/** \def kill_me_now
* \brief Used to kill an agent via 'kill_me_now'. */
#define kill_me_now return 1

void initialise_pointers(void);
void initialise_unit_testing(void);
FLAME_output * add_FLAME_output(FLAME_output ** outputs);
void free_FLAME_outputs(FLAME_output ** outputs);
void add_location(double point, location ** p_location);
void freelocations(location ** p_location);
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz);
void clean_up(int code);
void propagate_agents(void);
void propagate_messages_init(void);
void propagate_messages_complete(void);
void create_partitions(char * filename, int * itno);
void free_node_info(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_int_static_array(/*@out@*/ int * array, int size);
void init_int_array(int_array * array);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void copy_int_array(int_array * from, int_array * to);
//void sort_int_array(int_array array);
//int quicksort_int(int array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
void init_float_static_array(float * array, int size);
void init_float_array(float_array * array);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void copy_float_array(float_array * from, float_array * to);
//void sort_float_array(float_array array);
//int quicksort_float(float array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
void init_double_static_array(/*@out@*/ double* array, int size);
void init_double_array(double_array * array);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void copy_double_array(double_array * from, double_array * to);
//void sort_double_array(double_array array);
//int quicksort_double(double array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
void init_char_static_array(/*@out@*/ char * array, int size);
void init_char_array(char_array * array);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void copy_char_array(char_array * from, char_array * to);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
int idle(void);
/* xml.c */
int read_int_static_array(char * buffer, int buffer_size, int * j, int * int_static_array, int size);
int read_float_static_array(char * buffer, int buffer_size, int * j, float * float_static_array, int size);
int read_double_static_array(char * buffer, int buffer_size, int * j, double * double_static_array, int size);
int read_char_static_array(char * buffer, int buffer_size, int * j, char * char_static_array, int size);
int read_int_dynamic_array(char * buffer, int buffer_size, int * j, int_array * int_dynamic_array);
int read_float_dynamic_array(char * buffer, int buffer_size, int * j, float_array * float_dynamic_array);
int read_double_dynamic_array(char * buffer, int buffer_size, int * j, double_array * double_dynamic_array);
int read_char_dynamic_array(char * buffer, int buffer_size, int * j, char_array * char_dynamic_array);


void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[],
					   int partition_method, int flag);
void saveiterationdata(int iteration_number);


xmachine_memory_buyer_state * init_buyer_state();
xmachine_memory_buyer * init_buyer_agent();
void free_buyer_agent(xmachine_memory_buyer_holder * tmp, xmachine_memory_buyer_state * state);
void transition_buyer_agent(xmachine_memory_buyer_holder * tmp, xmachine_memory_buyer_state * from_state, xmachine_memory_buyer_state * to_state);
void add_buyer_agent_internal(xmachine_memory_buyer * agent, xmachine_memory_buyer_state * state);
void add_buyer_agent(int my_id, int firm_id, int my_qual);
void unittest_init_buyer_agent();
void unittest_free_buyer_agent();
xmachine_memory_firm_state * init_firm_state();
xmachine_memory_firm * init_firm_agent();
void free_firm_agent(xmachine_memory_firm_holder * tmp, xmachine_memory_firm_state * state);
void transition_firm_agent(xmachine_memory_firm_holder * tmp, xmachine_memory_firm_state * from_state, xmachine_memory_firm_state * to_state);
void add_firm_agent_internal(xmachine_memory_firm * agent, xmachine_memory_firm_state * state);
void add_firm_agent(int buyer_ids[], int my_id, float quality, int stored_id);
void unittest_init_firm_agent();
void unittest_free_firm_agent();

void add_PurchaseQuality_message(int qual, int id, int seller);
m_PurchaseQuality * add_PurchaseQuality_message_internal(void);
m_PurchaseQuality * get_first_PurchaseQuality_message(void);
m_PurchaseQuality * get_next_PurchaseQuality_message(m_PurchaseQuality * current);
void freePurchaseQualitymessages(void);

void add_Purchase_message(int an_id, int firm_id);
m_Purchase * add_Purchase_message_internal(void);
m_Purchase * get_first_Purchase_message(void);
m_Purchase * get_next_Purchase_message(m_Purchase * current);
void freePurchasemessages(void);


void set_my_id(int my_id);
int get_my_id();
void set_firm_id(int firm_id);
int get_firm_id();
void set_my_qual(int my_qual);
int get_my_qual();
int * get_buyer_ids();
void set_quality(float quality);
float get_quality();
void set_stored_id(int stored_id);
int get_stored_id();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[], int partitions, int partition_method);

/* messageboard.c */
m_PurchaseQuality * get_next_message_PurchaseQuality_in_range(m_PurchaseQuality * current);



m_Purchase * get_next_message_Purchase_in_range(m_Purchase * current);




/* memory.c */
xmachine * add_xmachine(void);


/* rules.c */
int FLAME_integer_in_array(int a, int * b, int size);

/* timing.c */
double get_time(void);

int b_receive_messages(void);
int FLAME_filter_buyer_b_receive_messages_01_end_PurchaseQuality(const void *msg, const void *params);
int b_send_message(void);
int f_send_message(void);
int f_idle(void);
int f_receive_messages(void);
int FLAME_filter_firm_f_receive_messages_01_02_Purchase(const void *msg, const void *params);
#endif
