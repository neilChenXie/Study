/*
 * =====================================================================================
 *
 *       Filename:  func.h
 *
 *    Description:  hash table DS for Q1
 *
 *        Version:  1.0
 *        Created:  01/11/2015 09:21:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Xie, 
 *   Organization:  USC
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
using namespace std;


#ifndef  func_INC
#define  func_INC

struct node {
	string key;
	int count;
	node *next;
};				/* ----------  end of struct node  ---------- */

typedef struct node Node_t;
/*
 * =====================================================================================
 *        Class:  C_hash
 *  Description:  hash table class
 * =====================================================================================
 */
class C_hash
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		C_hash ();                             /* constructor */

		/* ====================  ACCESSORS     ======================================= */
		void add_node(string key);
		bool find_ext(string key);
		void print_table();

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */
		int hash(string key);
		Node_t* create_new_node(string key);
		/* ====================  DATA MEMBERS  ======================================= */
		static const int table_size = 50;
		Node_t *rec[table_size];
}; /* -----  end of class C_hash  ----- */

#endif   /* ----- #ifndef func_INC  ----- */
