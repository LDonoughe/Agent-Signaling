/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"



/* Box filtering functions */




union pu_PurchaseQuality 
{
    m_PurchaseQuality *ptr;
    void *ptr_anon;
};

/** \fn void add_PurchaseQuality_message(int qual, int id, int seller)
 * \brief Add PurchaseQuality message by calling internal and processing.
 * \param qual Message variable.
 * \param id Message variable.
 * \param seller Message variable.
 */
void add_PurchaseQuality_message(int qual, int id, int seller)
{
    int rc;
	m_PurchaseQuality msg;
    
    msg.qual = qual;
    msg.id = id;
    msg.seller = seller;
    
    
    rc = MB_AddMessage(b_PurchaseQuality, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'PurchaseQuality' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'PurchaseQuality' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'PurchaseQuality' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_PurchaseQuality* getInternalMessage_PurchaseQuality(void)
{
    static m_PurchaseQuality *msg_prev = NULL;
    union pu_PurchaseQuality msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_PurchaseQuality); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'PurchaseQuality' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'PurchaseQuality' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_PurchaseQuality, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'PurchaseQuality' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'PurchaseQuality' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_PurchaseQuality * get_first_PurchaseQuality_message()
 * \brief Get the first PurchaseQuality message in the PurchaseQuality message list.
 * \return The first message in the list.
 */
m_PurchaseQuality * get_first_PurchaseQuality_message()
{
	return getInternalMessage_PurchaseQuality();
}

/** \fn xmachine_message_PurchaseQuality * get_next_PurchaseQuality_message(xmachine_message_PurchaseQuality * current)
 * \brief Get the next PurchaseQuality message in the PurchaseQuality message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_PurchaseQuality * get_next_PurchaseQuality_message(m_PurchaseQuality * current)
{
	return getInternalMessage_PurchaseQuality();
}


/* Box filtering functions */




union pu_Purchase 
{
    m_Purchase *ptr;
    void *ptr_anon;
};

/** \fn void add_Purchase_message(int an_id, int firm_id)
 * \brief Add Purchase message by calling internal and processing.
 * \param an_id Message variable.
 * \param firm_id Message variable.
 */
void add_Purchase_message(int an_id, int firm_id)
{
    int rc;
	m_Purchase msg;
    
    msg.an_id = an_id;
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_Purchase, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'Purchase' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'Purchase' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'Purchase' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_Purchase* getInternalMessage_Purchase(void)
{
    static m_Purchase *msg_prev = NULL;
    union pu_Purchase msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_Purchase); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'Purchase' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'Purchase' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_Purchase, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'Purchase' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'Purchase' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_Purchase * get_first_Purchase_message()
 * \brief Get the first Purchase message in the Purchase message list.
 * \return The first message in the list.
 */
m_Purchase * get_first_Purchase_message()
{
	return getInternalMessage_Purchase();
}

/** \fn xmachine_message_Purchase * get_next_Purchase_message(xmachine_message_Purchase * current)
 * \brief Get the next Purchase message in the Purchase message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_Purchase * get_next_Purchase_message(m_Purchase * current)
{
	return getInternalMessage_Purchase();
}

