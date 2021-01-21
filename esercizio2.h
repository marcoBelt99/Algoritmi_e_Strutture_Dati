
#include <stdio.h>   // Standard input-output library (e.g., fprintf).
#include <time.h>    // Time library (e.g., time, clock()).
#include <stdlib.h>  // Standard library (e.g., rand, srand).
#include <stdbool.h> // Boolean library (e.g., bool).
#include <string.h>  // String library (e.g., strcmp)

#define RED 'R' // Uso un alias per rendere più informativo il singolo carattere
#define BLACK 'B'

//  STRUTTURE DATI

//  LISTE COLLEGATE
typedef struct linkedListNode_t // NODO della Lista
{
    int value;                     // Chiave del nodo. Value contained in the node.
    struct linkedListNode_t *next; // Puntatore al nodo successivo. Pointer to next node.
    struct linkedListNode_t *prev; // Puntatore al nodo precedente. Pointer to previous node.
} linkedListNode_t;

typedef struct linkedList_t // LISTA COLLEGATA
{
    unsigned int size;             // Dimensione della lista. Size in number of nodes of the list.
    struct linkedListNode_t *head; // Indirizzo della testa. Pointer to the head node of the list.
} linkedList_t;

// Fine Liste collegate

// HASHTABLE
typedef struct hashtableEntry_t // "Casella" di una Tabella Hash.
{
    struct linkedList_t *list; // Puntatore a Lista
} hashtableEntry_t;

typedef struct hashtable_t // Tabella Hash
{
    unsigned int size;               // Size in number of entries of the hashtable.
    struct hashtableEntry_t **entry; // Array di puntatori a "Caselle".
} hashtable_t;

// ----- Fine HASHTABLE ----- //

// ----- RED BLACK TREE (RBT) ----- //

typedef struct rbtNode_t // Nodo di un RBT
{
    int value;                // Chiave del nodo.
    char color;               // Colore del nodo.
    struct rbtNode_t *parent; // Puntatore al padre.
    struct rbtNode_t *left;   // Puntatore al figlio sinistro.
    struct rbtNode_t *right;  // Puntatore al figlio destro.
} rbtNode_t;

typedef struct rbt_t // RBT
{
    unsigned int size;      // Size in number of nodes of the RBT.
    struct rbtNode_t *root; // Pointer to the root node.
    struct rbtNode_t *nil;  // Pointer to RBT NIL node.
} rbt_t;

typedef struct rbtTestStructure_t // test per l'RBT
{
    int *A;    // Array that contains the in order visit values of the RBT.
    int index; // Current index of the array.
} rbtTestStructure_t;

//  End of RBT

//  STRUTTURE DATI AUSILIARIE

typedef enum outputEnum_t
{
    ONCONSOLE, // On console.
    ONFILE     // On file.
} outputEnum_t;

// fine  STRUTTURE DATI AUSILIARIE

// fine STRUTTURE DATI

//  VARIABILI GLOBALI
extern time_t RANDOM_SEED;                       // Random seed (important for reproducibility).
extern const unsigned int MAX_RANDOM_NUMBER;     // Maximum random number allowed.
extern const unsigned int MIN_OPERATIONS;        // Minimum number of operations.
extern const unsigned int MAX_OPERATIONS;        // Maximum number of operations.
extern const unsigned int STEP;                  // Step of the experiment.
extern const unsigned int NUM_EXPERIMENTS;       // Number of experiments.
extern const unsigned int PERCENTAGE_INSERTIONS; // Percentage of insert operations.
extern const unsigned int NUM_ENTRIES;           // Size of the hashtable.
extern const bool TEST_DATA_STRUCTURES;          // Test data structures?
extern const unsigned int NUM_ELEMENTS_FOR_TEST; // Number of elements for testing.
extern const outputEnum_t outputType;            // Output type.
extern FILE *outputPointer;                      // Output pointer (for printing).

// Fine VARIABILI GLOBALI

//  DICHIARAZIONI DELLE FUNZIONI

// LISTE COLLEGATE

/**
 * @brief Create a new linked list node.
 * @param Value that the linked list node should contain.
 * @return Created linked list node.
 */
linkedListNode_t *createLinkedListNode(const int);

/**
 * @brief Create a new linked list.
 * @return Created linked list.
 */
linkedList_t *createLinkedList();

/**
 * @brief Insert linked list node in the head of the linked list.
 * @param The linked list.
 * @param Linked list node to be inserted.
 */
void linkedListInsert(linkedList_t *, linkedListNode_t *);

/**
 * @brief Search for a value in the linked list.
 * @param The linked list.
 * @param Value to be searched for.
 * @return First linked list node containing such value, if it exists; otherwise, NULL.
*/
linkedListNode_t *linkedListSearch(linkedList_t *, const int);

/**
 * @brief Delete a linked list node from linked list.
 * @param The linked list.
 * @param The linked list node to be deleted.
 */
void linkedListDelete(linkedList_t *, linkedListNode_t *);

/**
 * @brief Print the linked list.
 * @param Linked list to be printed.
 */
void linkedListPrint(linkedList_t *);

/**
 * @brief Free the linked list.
 * @param Linked list to be freed.
 */
void linkedListFree(linkedList_t *);

// Fine LISTE COLLEGATE

// HASHTABLE

/**
 * @brief Create a new hashtable.
 * @param The size of the hashtable (i.e., the number of entries).
 * @return The created hashtable.
 */
hashtable_t *createHashtable(const unsigned int);

/**
 * @brief Hash function computing the key for a given integer.
 * @param The hashtable needed to access the size of it.
 * @param The integer for which the key must be computed.
 * @return The computed key.
 */
const unsigned int hashFunction(hashtable_t *, const int);

/**
 * @brief Insert value in the hashtable.
 * @param The hashtable.
 * @param Value to be inserted.
 */
void hashtableInsert(hashtable_t *, const int);

/**
 * @brief Search for a value in the hashtable.
 * @param The hashtable.
 * @param Value to be searched.
 * @return Linked list node containing such value, if it exists; otherwise, NULL.
 */
linkedListNode_t *hashtableSearch(hashtable_t *, const int);

/**
 * @brief Delete value from hashtable.
 * @param The hashtable.
 * @param Linked list node to be deleted.
 */
void hashtableDelete(hashtable_t *, linkedListNode_t *);

/**
 * @brief Print the hashtable.
 * @param Hashtable to be printed.
 */
void hashtablePrint(hashtable_t *);

/**
 * @brief Test hashtable implementation.
 * @return True if it is correct; otherwise, false.
 */
bool hashtableTest();

/**
 * @brief Free hashtable.
 * @param Hashtable to be freed.
 */
void hashtableFree(hashtable_t *);

// Fine HASHTABLE

// RBT

/**
 * @brief Create new RBT node.
 * @param Value that the RBT node should contain.
 * @return Created RBT node.
 */
rbtNode_t *createRbtNode(const int);

/**
 * @brief Create new RBT.
 * @return Created RBT.
 */
rbt_t *createRbt();

/**
 * @brief Left rotate operation.
 * @param The RBT.
 * @param The RBT node to rotate on.
 */
void rbtLeftRotate(rbt_t *, rbtNode_t *);
/**
 * @brief Right rotate operation.
 * @param The RBT.
 * @param The RBT node to rotate on.
 */
void rbtRightRotate(rbt_t *, rbtNode_t *);

/**
 * @brief Insert RBT node in th RBT.
 * @param The RBT.
 * @param The RBT node to be inserted.
 */
void rbtInsert(rbt_t *, rbtNode_t *);

/**
 * @brief Fixup function for RBT insertion.
 * @param The RBT the be fixed.
 * @param The initial RBT node to be fixed.
 */
void rbtInsertFixup(rbt_t *, rbtNode_t *);

/**
 * @brief Search for a value in the RBT.
 * @param The RBT.
 * @param Value to be searched.
 * @return RBT node containing the value, if it exists; otherwise, NULL.
 */
rbtNode_t *rbtSearch(rbt_t *, const int);

/**
 * @brief Print RBT in order.
 * @param RBT to be printed.
 * @param RBT node to be printed.
 */
void rbtInOrder(rbt_t *, rbtNode_t *);

/**
 * @brief Test RBT implementation.
 * @return True if it is correct; otherwise, false.
 */
bool rbtTest();

/**
 * @brief Check if the tree is actually a RBT.
 * @param Tree to be checked.
 * @return True if it is; otherwise, false.
 */
bool isRbt(rbt_t *);

/**
 * @brief Function that checks if the tree has the BST property (i.e., x->left->value < x->value <= x->right->value, for all x).
 * @param Tree to be checked.
 * @return True if it is; otherwise, false.
 */
bool rbtHasBstProperty(rbt_t *);

/**
 * @brief Utility function for checking if the tree has the BST property.
 * @param Tree to be checked.
 * @param Current RBT node.
 * @param RBT test data structure.
 */
void rbtHasBstPropertyUtil(rbt_t *, rbtNode_t *, rbtTestStructure_t *);

/**
 * @brief Function that computes the black height of the RBT.
 * @param The RBT.
 * @param Current RBT node.
 * @return Black height if all paths have the same black height; otherwise, -1.
 */
int rbtComputeBlackHeight(rbt_t *, rbtNode_t *);

/**
 * @brief Free RBT nodes.
 * @param RBT whose nodes must be freed.
 * @param RBT node to be freed.
 */
void rbtFreeNodes(rbt_t *, rbtNode_t *);

/**
 * @brief Free RBT.
 * @param RBT to be freed.
 */
void rbtFree(rbt_t *);

// Fine RBT

// AUXILIARY FUNCTIONS
/**
 * @brief Generate a collection of random numbers.
 * @param Array of random numbers.
 * @param Size of the array.
 */
void generateRandomArray(int *, const int);

/**
 * @brief Unit test: check if the input array is sorted.
 * @param Array to be checked if sorted.
 * @param Size of the array.
 * @return True if it is sorted; otherwise, false
 */
bool isSorted(const int *, const int);

// End of AUXILIARY FUNCTIONS

// CORE FUNCTIONS

/**
 * @brief Function that does the experiment.
 * @param Array of random numbers.
 * @param Number of insertion operations.
 * @param Number of search operations.
 * @param Data structure to be used. The possible values are:
 * @return Elapsed time for the experiment.
 */
clock_t doExperiment(int *, const unsigned int, const unsigned int, char *);

// Fine CORE FUNCTIONS